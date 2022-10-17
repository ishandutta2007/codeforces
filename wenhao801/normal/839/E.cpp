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

int n, K, f[1 << 20], g[1 << 20]; bool E[44][44];

int main () {
    n = read(), K = read(); int i, j, k, n1 = n >> 1, n2 = n - n1;
    for (i = 1; i <= n; i++) for (j = 1; j <= n; j++) E[i][j] = read();
    for (i = 1; i < (1 << n1); i++) {
        if (__builtin_popcount(i) == 1) { f[i] = 1; continue; }
        for (j = 0; j < n1; j++) if ((i >> j) & 1) {
            if (!f[i ^ (1 << j)]) break;
            f[i] = f[i ^ (1 << j)] + 1;
            for (k = j + 1; k < n1; k++) if ((i >> k) & 1) f[i] *= E[j + 1][k + 1];
            break;
        }
    }
    for (i = 1; i < (1 << n2); i++) {
        if (__builtin_popcount(i) == 1) { g[i] = 1; continue; }
        for (j = 0; j < n2; j++) if ((i >> j) & 1) {
            if (!g[i ^ (1 << j)]) break;
            g[i] = g[i ^ (1 << j)] + 1;
            for (k = j + 1; k < n2; k++) if ((i >> k) & 1) g[i] *= E[j + 1 + n1][k + 1 + n1];
            break;
        }
    }
    for (i = 1; i < (1 << n2); i++) for (j = 0; j < n2; j++) if ((i >> j) & 1)
        g[i] = max(g[i], g[i ^ (1 << j)]);
    int ans = 0;
    for (i = 0; i < (1 << n1); i++) {
        int st = (1 << n2) - 1;
        for (j = 0; j < n1; j++) if ((i >> j) & 1) {
            int tmp = 0;
            for (k = 0; k < n2; k++) tmp += E[j + 1][k + n1 + 1] << k;
            st &= tmp;
        }
        ans = max(ans, f[i] + g[st]);
    }
    printf("%.9lf\n", 1.0 * K * K / 2 * (ans - 1) / ans);
    return 0;
}