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

int n, a[550][550];

int main () {
    int T = read(); while (T--) {
        n = read(); int i, j;
        for (i = 1; i <= n * 2; i++) for (j = 1; j <= n * 2; j++) a[i][j] = read();
        long long ans = 0;
        for (i = n + 1; i <= n + n; i++) for (j = n + 1; j <= n + n; j++) ans += a[i][j];
        ans += min({a[n + 1][1], a[n + 1][n], a[n + n][1], a[n + n][n], a[1][n + 1], a[1][n + n], a[n][n + 1], a[n][n + n]});
        printf("%lld\n", ans);
    }
    return 0;
}