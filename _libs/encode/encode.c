#include <windows.h>

//gbk ת utf8
int ANSIToUTF8(char *buf, int sz, const char* str, int len)
{
    int n = MultiByteToWideChar(CP_ACP, 0, str, len, NULL, 0);
    if (n > 0) {
      WCHAR * ws = malloc(sizeof(WCHAR)*n);
      memset(ws, 0, sizeof(WCHAR)*n);
      MultiByteToWideChar(CP_ACP, 0, str, len, ws, n);
      n = WideCharToMultiByte(CP_UTF8, 0, ws, -1, NULL, 0, NULL, NULL);
      if (n <= sz && buf!=NULL ) {
        memset(buf, 0, sz);
        n = WideCharToMultiByte(CP_UTF8, 0, ws, -1, buf, sz, NULL, NULL);
        if (n < sz)
          buf[n] = '\0';
      }
      free(ws);
    }
    return n;
}

//utf-8 ת gbk
int UTF8ToANSI(char *buf, int sz, const char* str, int len)
{
    int n = MultiByteToWideChar(CP_UTF8, 0, str, len, NULL, 0);
    if (n > 0) {
      WCHAR * ws = malloc(sizeof(WCHAR)*n);
      memset(ws, 0, sizeof(WCHAR)*n);
      MultiByteToWideChar(CP_UTF8, 0, str, len, ws, n);
      n = WideCharToMultiByte(CP_ACP, 0, ws, -1, NULL, 0, NULL, NULL);
      if (n <= sz && buf != NULL) {
        memset(buf, 0, sz);
        n = WideCharToMultiByte(CP_ACP, 0, ws, -1, buf, sz, NULL, NULL);
        if (n < sz)
          buf[n] = '\0';
      }
      free(ws);
    }
    return n;
}
