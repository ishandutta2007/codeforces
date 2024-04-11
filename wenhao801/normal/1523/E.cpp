#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long
inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int mod = 1e9 + 7, MAXN = 100100;
int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod; y >>= 1;
    }
    return ret;
}
int inv (int x) { return qpow(x, mod - 2); }
int fac[MAXN], ifac[MAXN], n, K, f[MAXN];
int binom (int x, int y) { if (x < y || y < 0) return 0; return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod; }

signed main () {
    int i, j; fac[0] = ifac[0] = 1;
    for (i = 1; i <= 100000; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[100000] = inv(fac[100000]);
    for (i = 100000 - 1; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    int T = read();
    while (T--) {
        n = read(), K = read(); int ans = 0;
        f[0] = f[1] = fac[n];
        for (i = 2; i <= n; i++) f[i] = 1ll * binom(n - i - 1ll * (K - 1) * (i - 1) + (i + 1) - 1, i) * fac[i] % mod * fac[n - i] % mod;
        for (i = 1; i <= n; i++) ans = (ans + 1ll * (f[i] - f[i + 1]) * (i + 1)) % mod;
        ans = 1ll * ans * ifac[n] % mod;
        cout << (ans + mod) % mod << endl;
    }
    return 0;
}