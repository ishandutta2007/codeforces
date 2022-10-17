#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

int main () {
    int T = read();
    while (T--) {
        int n = read(), m = read(), i, j;
        long long ans = 0;
        for (i = 1; i - 1 < (n / (i + 1)) && i <= m; i++) {
            ans += min(n / (i + 1), i - 1);
        }
        ++i;
        int l = i, r;
        while (l <= m + 1 && l <= n) {
            r = min(m + 1, n / (n / l));
            ans += 1ll * (r - l + 1) * (n / l);
            l = r + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}