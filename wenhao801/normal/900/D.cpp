#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int mod = 1e9 + 7;
int qpow (int y) {
    int ret = 1, x = 2;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}
const int MAXN = 100100, LIM = 100000;
int p[MAXN], top, mu[MAXN]; bool np[MAXN];

void gp () {
    mu[1] = 1;
    for (int i = 2; i <= LIM; i++) {
        if (!np[i]) p[++top] = i, mu[i] = -1;
        for (int j = 1; j <= top; j++) {
            if (p[j] * i > LIM) break;
            np[p[j] * i] = true;
            if (i % p[j] == 0) { mu[i * p[j]] = 0; break; }
            mu[i * p[j]] = -mu[i];
        }
    }
}
int gmu (int x) {
    if (x <= LIM) return mu[x];
    int lim = sqrt(x) + 1, ret = 1;
    for (int i = 1; p[i] <= lim; i++) {
        if (x % (p[i] * p[i]) == 0) return 0;
        if (x % p[i] == 0) x /= p[i], ret = -ret;
    }
    if (x != 1) ret = -ret;
    return ret;
}

int main () {
    gp(); int x, y; scanf("%d%d", &x, &y);
    if (y % x) { puts("0"); return 0; }
    y /= x; int ans = 0, lim = sqrt(y);
    for (int i = 1; i <= lim; i++) {
        if (y % i) continue;
        ans = (ans + qpow(i - 1) * gmu(y / i)) % mod;
        if (i * i != y) ans = (ans + qpow(y/i - 1) * gmu(i)) % mod;
    }
    printf("%d\n", (ans + mod) % mod);
    return 0;
}