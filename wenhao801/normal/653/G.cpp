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

const int mod = 1e9 + 7, MAXN = 300300;
int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod; y >>= 1;
    }
    return ret;
}
int inv (int x) { return qpow(x, mod - 2); }

int pr[MAXN], top; bool np[MAXN];
void sieve () {
    const int lim = 300000;
    for (int i = 2; i <= lim; i++) {
        if (!np[i]) pr[++top] = i;
        for (int j = 1; j <= top; j++) {
            if (pr[j] * i > lim) break;
            np[pr[j] * i] = 1;
            if (i % pr[j] == 0) break;
        }
    }
}

int n, buc[MAXN][22];
int fac[MAXN], ifac[MAXN], f[MAXN];
inline int binom (int x, int y) { if (y < 0) return 0; return 1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod; }

int main () {
    sieve();
    n = read(); int i, j;
    fac[0] = ifac[0] = 1;
    for (i = 1; i <= n; i++) fac[i] = 1ll * i * fac[i - 1] % mod;
    ifac[n] = inv(fac[n]); for (i = n - 1; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
    for (i = 1; i <= n; i++) f[i] = (f[i - 1] + binom(n - 1, i - 1)) % mod;
    for (i = 1; i <= n; i++) f[i] = (f[i - 1] + f[i]) % mod;
    
    for (i = 1; i <= n; i++) {
        int x = read();
        for (j = 1; j <= top && pr[j] * pr[j] <= x; j++) {
            int cur = 0; while (x % pr[j] == 0) ++cur, x /= pr[j];
            ++buc[j][cur]; --buc[j + 1][cur];
        } ++buc[j][0];
        if (x != 1) { int tmp = lower_bound(pr + 1, pr + top + 1, x) - pr; --buc[tmp][0], ++buc[tmp + 1][0]; ++buc[tmp][1], --buc[tmp + 1][1]; }
    }
    for (i = 0; i <= 20; i++) for (j = 1; j <= top; j++) buc[j][i] += buc[j - 1][i];
    int ans = 0;
    for (i = 1; i <= top; i++) {
        int pre = 0, suf = n - buc[i][0];
        for (j = 0; j <= 20; j++) {
            int tmp = (f[suf + buc[i][j] - 1] - (suf ? f[suf - 1] : 0)) % mod;
            ans = (ans - 1ll * j * tmp) % mod;
            tmp = (f[pre + buc[i][j] - 1] - (pre ? f[pre - 1] : 0)) % mod;
            ans = (ans + 1ll * j * tmp) % mod;
            pre += buc[i][j], suf -= buc[i][j + 1];
        }
    }
    printf("%d\n", (ans + mod) % mod);
    return 0;
}