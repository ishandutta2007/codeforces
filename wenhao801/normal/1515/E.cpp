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

const int MAXN = 404;
int n, mod, f[MAXN][MAXN];

int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod; y >>= 1;
    }
    return ret;
}
int inv (int x) { return qpow(x, mod - 2); }
int fac[MAXN], ifac[MAXN];

int main () {
    n = read(); int i, j; mod = read();
    fac[0] = ifac[0] = 1;
    for (i = 1; i <= n; i++ )fac[i] = 1ll * i * fac[i - 1] % mod;
    ifac[n] = inv(fac[n]); for (i = n - 1; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    int ans = 0;
    for (i = 1; i <= n; i++) for (j = 1; j <= i; j++) {
        for (int k = 1; k <= j; k++) {
            if (k == j) {
                if (i == j) f[i][j] = (f[i][j] + 1ll * qpow(2, k - 1) * ifac[k]) % mod;
            }
            else {
                f[i][j] = (f[i][j] + 1ll * f[i - k - 1][j - k] * qpow(2, k - 1) % mod * ifac[k]) % mod;
            }
        }
        // printf("f %d %d = %d\n", i, j, f[i][j]);
        if (i == n) ans = (ans + 1ll * fac[j] * f[i][j]) % mod;
    }
    printf("%d\n", (ans + mod) % mod);
    return 0;
}