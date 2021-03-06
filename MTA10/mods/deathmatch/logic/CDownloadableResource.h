/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        mods/deathmatch/logic/CDownloadableResource.h
*  PURPOSE:     Header for downloadable resource class
*  DEVELOPERS:  Chris McArthur <>
*               Cecill Etheredge <ijsf@gmx.net>
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef CDOWNLOADABLERESOURCE_H
#define CDOWNLOADABLERESOURCE_H

#ifndef _WINDOWS_

#define WIN32_LEAN_AND_MEAN     // Exclude all uncommon functions from windows.h to reduce executable size

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0400     // So we can use IsDebuggerPresent()
#endif

#include <windows.h>
#endif

#include "../../shared_logic/utils/zip/crc32.h"

class CDownloadableResource
{
public:
    enum eResourceType
    {
        RESOURCE_FILE_TYPE_MAP,
        RESOURCE_FILE_TYPE_SCRIPT,
        RESOURCE_FILE_TYPE_CLIENT_SCRIPT,
        RESOURCE_FILE_TYPE_CONFIG,
        RESOURCE_FILE_TYPE_CLIENT_CONFIG,
        RESOURCE_FILE_TYPE_HTML,
        RESOURCE_FILE_TYPE_CLIENT_FILE,
    };

public:
    CDownloadableResource           ( eResourceType resourceType, const char* szName, const char* szNameShort, unsigned long ulServerCRC = 0, bool bGenerateClientCRC = false, CRCGenerator* pCRCGen = NULL );
    virtual ~CDownloadableResource  ( void );

    bool DoesClientAndServerCRCMatch( void );

    eResourceType GetResourceType   ( void ) { return m_resourceType; };
    const char* GetName             ( void ) { return m_szName; };
    const char* GetShortName        ( void ) { return m_szNameShort; };

    // CRC-based methods
    unsigned long GenerateClientCRC ( void );
    unsigned long GenerateClientCRC ( CRCGenerator* pCRCGen );

    unsigned long GetLastClientCRC  ( void );

    unsigned long GetServerCRC      ( void );
    void SetServerCRC               ( unsigned long ulServerCRC );
protected:
    eResourceType       m_resourceType;

    char*               m_szName;
    char*               m_szNameShort;

    unsigned long       m_ulLastClientCRC;
    unsigned long       m_ulServerCRC;
};

#endif