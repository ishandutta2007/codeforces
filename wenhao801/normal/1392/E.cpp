#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

using ll = long long;
int n; ll a[55][55];

int main() {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) a[i][j] = (i & 1) ? (1ll << (i + j - 2)) : 0;
    for (i = 1; i <= n; i++, putchar('\n')) for (j = 1; j <= n; j++) printf("%lld ", a[i][j]);
    fflush(stdout);
    int q = read(); while (q--) {
        ll x; cin >> x;
        int px = 1, py = 1;
        while (px != n || py != n) {
            printf("%d %d\n", px, py);
            if (px < n && ((x >> (px + py - 1)) & 1) == bool(a[px + 1][py])) ++px; else ++py;
        }
        printf("%d %d\n", px, py); fflush(stdout);
    }
    return 0;
}