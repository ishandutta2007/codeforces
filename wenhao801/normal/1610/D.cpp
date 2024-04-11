#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200, mod = 1e9 + 7;
int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret= 1ll * ret * x % mod;
        x = 1ll * x * x % mod; y >>= 1;
    }return ret;
}
int inv (int x)  { return qpow(x, mod - 2); }

int n, c[MAXN], sc[MAXN], a[MAXN], p2[MAXN], fac[MAXN], ifac[MAXN];
int binom (int u, int v) { return 1ll * fac[u] * ifac[v] % mod * ifac[u - v] % mod; }

map <int, int> mp;

int main () {
    n = read(); int i, j;
    for (i = 1; i <= n; i++) {
        a[i] = read();
        for (j = 0; j < 40; j++) if ((a[i] >> j) & 1) break;
        ++c[j];
    }
    p2[0] = 1; for (i = 1; i <= n; i++) p2[i] = (p2[i - 1] << 1) % mod;
    fac[0] = ifac[0] = 1; for (i = 1; i <= n; i++) fac[i] = 1ll * i * fac[i - 1] % mod;
    ifac[n] = inv(fac[n]); for (i = n- 1; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    for (i = 30; i >= 0; i--) sc[i] = sc[i + 1] + c[i];
    // for (i = 0; i <= 30; i++) cout << sc[i] << ' '; cout << endl;
    int ans = 0;
    ans = (ans + 1ll * (p2[c[0]] - 1) * (p2[sc[1]])) % mod;
    for (i = 1; i <= 30; i++) {
        for (j = 2; j <= c[i]; j += 2) ans = (ans + 1ll * binom(c[i], j) * p2[sc[i + 1]]) % mod;
    }
    printf("%d\n", (ans + mod) % mod);
    return 0;
}