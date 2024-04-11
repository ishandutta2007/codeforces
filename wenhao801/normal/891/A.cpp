#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

int n, a[2020];

int main () {
    n = read(); int i, j = 0, k = 0;
    for (i = 1; i <= n; i++) a[i] = read(), j += a[i] == 1;
    if (j) { printf("%d\n", n - j); return 0; }
    int ans = 1e9 + 7;
    for (i = 1; i <= n; i++) {
        int now = a[i];
        for (j = i + 1; j <= n; j++) {
            now = __gcd(a[j], now);
            if (now == 1) break;
        }
        if (j <= n) ans = min(ans, j - i + n - 1);
    }
    if (ans > 1e9) puts("-1"); else printf("%d\n", ans);
    return 0;
}