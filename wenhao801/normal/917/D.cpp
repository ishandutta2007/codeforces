#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int mod = 1e9 + 7, MAXN = 220;
int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod; y >>= 1;
    }
    return ret;
}
int n; vector <int> E[MAXN];
int f[MAXN][MAXN][2], tmp[MAXN][2];

void add (int &u, int v) { u = (u + v) % mod; }

void dfs (int x, int fa) {
    f[x][0][0] = f[x][0][1] = 1;
    for (auto v: E[x]) if (v != fa) {
        dfs(v, x);
        memset(tmp, 0, sizeof tmp);
        for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) {
            add(tmp[i + j + 1][0], 1ll * f[x][i][0] * f[v][j][1] % mod);
            add(tmp[i + j][0], 1ll * f[x][i][0] * f[v][j][0] % mod);
            add(tmp[i + j][1], 1ll * f[x][i][1] * f[v][j][0] % mod);
            add(tmp[i + j + 1][1], 1ll * f[x][i][1] * f[v][j][1] % mod);
            add(tmp[i + j][1], 1ll * f[x][i][0] * f[v][j][1] % mod);
        }
        for (int i = 0; i <= n; i++) f[x][i][0] = tmp[i][0], f[x][i][1] = tmp[i][1];
    }
    // printf("print node %d\n",x );
    // for (int i = 0; i < n; i++) for (int j = 0; j <= 1; j++) printf("sel = %d, qd = %d, %d\n", i, j, f[x][i][j]);
}

int F[MAXN], G[MAXN], binom[MAXN][MAXN];

int main () {
    n = read(); int i, j;
    for (i = 1; i < n; i++) { int u = read(), v = read(); E[u].push_back(v), E[v].push_back(u); }
    dfs(1, 0); binom[0][0] = 1;
    for (i = 1; i <= n; i++) {
        binom[i][0] = 1;
        for (j = 1; j <= i; j++) binom[i][j] = (binom[i - 1][j] + binom[i - 1][j - 1]) % mod;
    }
    for (i = 1, j = qpow(n, mod - 2); i <= n; i++, j = 1ll * j * n % mod) F[n - i] = 1ll * j * f[1][i - 1][1] % mod;
    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) G[i] = (G[i] + ((j - i) % 2 == 0 ? 1ll : -1ll) * binom[j][i] * F[j]) % mod;
        printf("%d ", (G[i] + mod) % mod);
    }
    return 0;
}