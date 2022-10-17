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

#define int long long

const int MAXN = 1001;

int n, m;

int a[MAXN] = {};
int b[MAXN] = {};
int f[MAXN][MAXN] = {};

const int mod = 1000000007;

int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return ret;
}

signed main () {
    n = read(), m = read();
    int i, j;
    for (i = 1; i <= n; i++) a[i] = read();
    for (i = 1; i <= m; i++) b[i] = read();
    for (i = 1; i <= m; i++) {
        for (j = 1; j <= b[i]; j++) f[j][i] = 1;
        f[b[i] + 1][i] = 2;
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= a[i]; j++) {
            if (f[i][j] == 2) { puts("0"); return 0; }
            f[i][j] = 1;
        }
        if (f[i][a[i] + 1] == 1) { puts("0"); return 0; }
        f[i][a[i] + 1] = 2;
    }
    int cnt = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (f[i][j] == 0) cnt++;
    printf("%d\n", qpow(2, cnt));
    return 0;
}