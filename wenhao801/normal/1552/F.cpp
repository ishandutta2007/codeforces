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

const int MAXN = 202000, mod = 998244353;

int n, f[MAXN], g[MAXN], sg[MAXN];
int x[MAXN], to[MAXN], op[MAXN];

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) x[i] = read(), to[i] = read(), op[i] = read();
    for (i = 1; i <= n; i++) {
        int tmp = lower_bound(x + 1, x + n + 1, to[i]) - x;
        g[i] = (1ll * sg[i - 1] - sg[tmp - 1] + x[i] - to[i]) % mod;
        sg[i] = (sg[i - 1] + g[i]) % mod; f[i] = (1ll * f[i - 1] + x[i] - x[i - 1] + op[i] * g[i]) % mod;
    }
    printf("%d\n", (f[n] + 1 + mod) % mod);
    return 0;
}