#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

inline int read() {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
    return ret * t;
}

const int MAXN = 200200, mod = 998244353, mx = 2e5;
inline int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod, y >>= 1;
    }
    return ret;
}
int inv (int x) { return qpow(x, mod - 2); }

int fac[MAXN], ifac[MAXN];
int n, m, a[MAXN], b[MAXN];

int t[MAXN];
inline int lowbit (int x) { return x & -x; }
inline int ask (int x) { int ret = 0; while (x) ret = (ret + t[x]) % mod, x -= lowbit(x); return ret; }
inline void add (int x, int k) { while (x <= mx) t[x] = (t[x] + k) % mod, x += lowbit(x); }

int main () {
    n = read(), m = read(); int i, j;
    for (i = 1; i <= n; i++) ++a[read()];
    for (i = 1; i <= m; i++) b[i] = read();
    fac[0] = ifac[0] = 1; for (i = 1; i <= mx; i++) fac[i] = 1ll * i * fac[i - 1] % mod;
    ifac[mx] = inv(fac[mx]); for (i = mx - 1; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;

    int now = fac[n], ans = 0;
    for (i = 1; i <= mx; i++) add(i, a[i]), now = 1ll * now * ifac[a[i]] % mod;

    for (i = 1; i <= min(n, m); i++) {
        ans = (ans + 1ll * now * inv(n - i + 1) % mod * ask(b[i] - 1)) % mod;
        --a[b[i]]; add(b[i], -1); 
        if (a[b[i]] < 0) break;
        now = 1ll * now * inv(n - i + 1) % mod * (a[b[i]] + 1) % mod;
    }
    if (n < m && i == n + 1) ++ans;
    printf("%d\n", (ans + mod) % mod);
    return 0;
}