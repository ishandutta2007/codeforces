#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 1001000, mod = 1e9 + 7;
int n, fac[MAXN], ifac[MAXN];

int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod; y >>= 1;
    }
    return ret;
}

int binom (int x, int y) { if (x < y || y < 0) return 0; return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod; }

int main () {
    n = read(); int i, j;
    if (n == 1) { puts("2"); return 0; }
    fac[0] = ifac[0] = 1;
    for (i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
    ifac[n] = qpow(fac[n], mod - 2); for (i = n - 1; i >= 1; i--) ifac[i] = 1ll * (i + 1) * ifac[i + 1] % mod;
    int ans = 0;
    for (i = n & 1; i < n; i += 2)
        ans = (ans + 1ll * (binom(n - i - 1, i - 1) + binom(n - i, i)) % mod * fac[n - i]) % mod;
    ans = (ans << 1) % mod;
    printf("%d\n", ans);
    return 0;
}