#pragma GCC optimize("Ofast")
#pragma GCC target("arch=ivybridge")
#include <bits/stdc++.h>
using namespace std;

namespace fio {
    const int BSIZE = 524288;
    char buffer[BSIZE];
    int p = BSIZE;
    inline char readChar() {
        if(p == BSIZE) {
            fread(buffer, 1, BSIZE, stdin);
            p = 0;
        }
        return buffer[p++];
    }
    int readint() {
        char c = readChar();
        while ((c < '0' || c > '9') && c != '-') {
            c = readChar();
        }
        int ret = 0; bool neg = c == '-';
        if (neg) c = readChar();
        while (c >= '0' && c <= '9') {
            ret = ret * 10 + c - '0';
            c = readChar();
        }
        return neg ? -ret : ret;
    }
}

using fio::readint;

float a[100005];

int main()
{
    int n, m;
    n = readint();
    m = readint();
    for (int i = 0; i < n; i++) a[i] = readint();

    for (int i = 0; i < m; i++)
    {
        int t, l, r, x;
        t = readint();
        l = readint() - 1;
        r = readint() - 1;
        x = readint();

        if (t == 1)
        {
            for (int j = l; j <= r; j++) if (a[j] > x) a[j] -= x;
        }
        else
        {
            int cnt = 0;
            for (int j = l; j <= r; j++) if (a[j] == x) ++cnt;
            printf("%d\n", cnt);
        }
    }
}