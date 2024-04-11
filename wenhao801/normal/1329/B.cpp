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
        int n = read(), mod = read();
        int ans = 1;
        int i, j;
        for (i = 1; i <= n; i <<= 1ll)
            if ((i << 1ll) <= n) ans = ans * (i + 1) % mod;
            else ans = ans * (n - i + 2) % mod;
        ans = (ans - 1 + mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}