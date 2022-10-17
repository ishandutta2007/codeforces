#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

const int lim = 2e5, MAXN = lim + 50, mod = 998244353, G = 3, iG = (mod + 1) / G;
int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod, y >>= 1;
    }
    return ret;
}
int inv (int x) { return qpow(x, mod - 2); }

int pr[MAXN], mu[MAXN], top; bool np[MAXN];
int s_mu[MAXN];
void sieve () {
    int i, j; mu[1] = 1;
    for (i = 2; i <= lim; i++) {
        if (!np[i]) pr[++top] = i, mu[i] = -1;
        for (j = 1; j <= top; j++) {
            if (pr[j] * i > lim) break;
            np[i * pr[j]] = 1;
            if (i % pr[j] == 0) { mu[i * pr[j]] = 0; break; }
            mu[i * pr[j]] = -mu[i];
        }
    }
    for (i = 1; i <= lim; i++) s_mu[i] = s_mu[i - 1] + mu[i];
}

int fac[MAXN], ifac[MAXN];
inline int binom (int x, int y) { return (x < y || y < 0) ? 0 : (1ll * fac[x] * ifac[y] % mod * ifac[x - y] % mod); }

void init () {
    sieve(); fac[0] = ifac[0] = 1;
    for (int i = 1; i <= lim; i++) fac[i] = 1ll * i * fac[i - 1] % mod;
    ifac[lim] = inv(fac[lim]); for (int i = lim - 1; i >= 1; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
}

int rev[MAXN << 2];
void NTT (int *f, int N, bool dft) {
    int i, j, k;
    for (i = 0; i < N; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (N >> 1) : 0);
    for (i = 0; i < N; i++) if (i < rev[i]) swap(f[i], f[rev[i]]);
    for (i = 2; i <= N; i <<= 1) {
        int nex = qpow(dft ? G : iG, (mod - 1) / i);
        for (j = 0; j < N; j += i) {
            int now = 1;
            for (k = j; k < j + (i >> 1); k++) {
                int tmp = 1ll * now * f[k + (i >> 1)] % mod;
                f[k + (i >> 1)] = (f[k] - tmp) % mod;
                f[k] = (f[k] + tmp) % mod;
                now = 1ll * now * nex % mod;
            }
        }
    }
    if (!dft) { for (i = 0, j = inv(N); i < N; i++) f[i] = 1ll * f[i] * j % mod; }
}

int f[MAXN], g[MAXN], A[MAXN << 2], B[MAXN << 2];
int pre1[MAXN], pre2[MAXN];

#define qqpow(x) (1ll * pre2[(x) / sqrtn] * pre1[(x) % sqrtn] % mod)

int main () {
    init();

    int n = read(), K = read(), sqrtn = sqrt(n);
    if (n == 1 || K == 1) { puts("1"); return 0; }
    for (int V = 2; V <= K;  V++) {
        pre1[0] = pre2[0] = 1;
        for (int i = 1; i <= sqrtn; i++) pre1[i] = 1ll * pre1[i - 1] * V % mod;
        for (int i = 1; i * sqrtn <= n; i++) pre2[i] = 1ll * pre2[i - 1] * pre1[sqrtn] % mod;
        for (int L = 1, R; L <= n - 1; L = R + 1) {
            int tmp = (n - 1) / L; R = (n - 1) / tmp;
            g[V] = (g[V] + 1ll * (s_mu[R] - s_mu[L - 1]) % mod * (qqpow(tmp + 1) - V)) % mod;
        }
    }
    for (int i = 0; i <= K; i++) A[i] = 1ll * ifac[i] * g[i] % mod, B[i] = ((i & 1) ? -1ll : 1ll) * ifac[i] % mod;
    int N = 1; while (N < (K << 1)) N <<= 1;
    NTT(A, N, 1), NTT(B, N, 1);
    for (int i = 0; i < N; i++) A[i] = 1ll * A[i] * B[i] % mod;
    NTT(A, N, 0);
    for (int i = 1; i <= K; i++) f[i] = 1ll * fac[i] * A[i] % mod;
    int ans = 0;
    for (int i = 1; i <= K; i++)
        ans = (ans + 1ll * f[i] * ifac[i] % mod) % mod;
    printf("%d\n", (ans + mod) % mod);
    return 0;
}