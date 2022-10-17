#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int mod = 998244353, MAXN = 5050;
int qpow (int x, int y) {
    if (y < 0) return qpow(qpow(x, -y), mod - 2);
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}

int s2[MAXN][MAXN], rua[MAXN], p2[MAXN];
int n, m, t;

int main () {
    scanf("%d%d%d", &n, &m, &t);
    int i, j;
    rua[0] = 1; s2[0][0] = 1; p2[0] = qpow(2, n);
    for (i = 1; i <= t; i++) rua[i] = 1ll * rua[i - 1] * (n - i + 1) % mod, p2[i] = qpow(m, n - i);
    for (i = 1; i <= t; i++) for (j = 1; j <= i; j++)
        s2[i][j] = (1ll * j * s2[i - 1][j] % mod + s2[i - 1][j - 1]) % mod;
    int ans = 0;
    for (i = 0; i <= t; i++)
        ans = (ans + 1ll * s2[t][i] * rua[i] % mod * p2[i] % mod) % mod;
    ans = 1ll * ans * qpow(m, -n) % mod;
    printf("%d\n", (ans + mod) % mod);
    return 0;
}