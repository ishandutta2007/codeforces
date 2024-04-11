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

#define ld long double
const int MAXN = 55;
const ld eps = 1e-10;
int n, m, a[MAXN], b[MAXN]; ld p[MAXN], cur;

ld f[55][5050];
bool check () {
    int i, j; memset(f, 0, sizeof f);
    for (i = n; i >= 1; i--) {
        for (j = 0; j <= n * 100; j++) {
            f[i][j] = 1e18;
            ld u = cur, v = cur;
            if (j >= a[i]) u = min(u, f[i + 1][j - a[i]]);
            if (j >= b[i]) v = min(v, f[i + 1][j - b[i]]);
            f[i][j] = min(f[i][j], p[i] * (u + a[i]) + (1 - p[i]) * (v + b[i]));
            // printf("f %d %d = %.3Lf\n", i, j, f[i][j]);
        }
    }
    return f[1][m] <= cur;
}

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) a[i] = read(), b[i] = read(), p[i] = 0.01 * read();
    ld L = 1, R = 1e9, ans = -1;
    while (R - L > eps) {
        cur = (L + R) / 2;
        if (check()) ans = cur, R = cur - eps;
        else L = cur + eps;
    }
    printf("%.9Lf\n", ans);
    return 0;
}