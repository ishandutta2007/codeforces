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

#define ll long long
const int MAXN = 22;
int n, m, lo[1 << 19]; bool E[MAXN][MAXN];
ll f[MAXN][1 << 19];

int main () {
    n = read(), m = read(); int i, j, k;
    for (i = 1; i <= m; i++) {
        int u = read(), v = read();
        E[u][v] = E[v][u] = 1;
    }
    for (i = 1; i <= n; i++) f[i][1 << (i - 1)] = 1;
    for (i = 1; i <= (1 << n); i++) lo[i] = (i & 1) ? 1 : (lo[i >> 1] + 1);
    ll ans = 0;
    for (i = 1; i < (1 << n); i++) if (__builtin_popcount(i) > 1) {
        for (j = 1; j <= n; j++) if ((i >> (j - 1)) & 1) {
            for (k = 1; k <= n; k++) if (((i >> (k - 1)) & 1) && E[j][k]) {
                if (lo[i - (1 << (j - 1))] != lo[i]) continue;
                // printf("trans from %d %d: %d\n", k, i - (1 << (j - 1)), f[k][i - (1 << (j - 1))]);
                f[j][i] += f[k][i - (1 << (j - 1))];
            }
            ans += E[lo[i]][j] * f[j][i];
        }
    }
    printf("%lld\n", (ans - m) >> 1);
    return 0;
}