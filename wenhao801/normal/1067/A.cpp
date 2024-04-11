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

const int MAXN = 100100, mod = 998244353;
int n, a[MAXN], f[2][220][2];

int main () {
    n = read(); int i,j ;
    for (i = 1; i <= n; i++) a[i] = read();
    if (a[1] != -1) f[1][a[1]][1] = 1;
    else {
        for (i = 1; i <= 200; i++) f[1][i][1] = 1;
    }
    for (i = 1; i < n; i++) {
        int now = i & 1, nex = now ^ 1;
        for (j = 1; j <= 200; j++) f[nex][j][0] = f[nex][j][1] = 0;
        for (j = 1; j <= 200; j++) {
            f[nex][1][0] = (f[nex][1][0] + f[now][j][0]) % mod;
            f[nex][j + 1][0] = (f[nex][j + 1][0] - f[now][j][0]) % mod;
            f[nex][j + 1][1] = (f[nex][j + 1][1] + f[now][j][0]) % mod;

            f[nex][j + 1][1] = (f[nex][j + 1][1] + f[now][j][1]) % mod;
            f[nex][j][0] = (f[nex][j][0] + f[now][j][1]) % mod;
            f[nex][j + 1][0] = (f[nex][j + 1][0] - f[now][j][1]) % mod;
        }
        for (j = 1; j <= 200; j++) f[nex][j][0] = (f[nex][j][0] + f[nex][j - 1][0]) % mod,
            f[nex][j][1] = (f[nex][j][1] + f[nex][j - 1][1]) % mod;
        if (a[i + 1] != -1) {
            for (j = 1; j <= 200; j++) if (j != a[i + 1]) f[nex][j][0] = f[nex][j][1] = 0;
        }
    }
    int ans = 0;
    for (i = 1; i <= 200; i++) ans = (ans + f[n & 1][i][0]) % mod;
    printf("%d\n", (ans + mod) % mod);
    return 0;
}