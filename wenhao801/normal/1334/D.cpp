#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define int long long

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

signed main () {
    int T = read();
    while (T--) {
        int n = read(), l = read(), r = read();
        int i, j;
        for (i = n - 1, j = n - 1; j * 2 < l && i; --i, j += i);
        int p = n - i, q = ((l - (j - i) * 2 + 1) / 2) + p;
        bool f = l % 2;
        if (q > n) { puts("1"); continue; }
        while (l <= r) {
            if (f) printf("%lld ", p);
            else printf("%lld ", q);
            f = !f;
            
            if (f) {q++;
            if (q > n) p++, q = p + 1; }
            l++;
            if (p == n) break;
        } 
        if (l <= r) putchar('1');
        puts("");
    }
    return 0;
}