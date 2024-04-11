#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 400400, mod = 998244353, g = 3, invg = (mod + 1) / g, inv2 = (mod + 1) >> 1;

int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = 1ll * ret * x % mod;
        x = 1ll * x * x % mod;
        y >>= 1;
    }
    return ret;
}

int rev[MAXN];
void NTT (int *f, bool t, int N) {
    int i, j, k;
    for (i = 0; i < N; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (N >> 1) : 0);
    for (i = 0; i < N; i++) if (i < rev[i]) swap(f[i], f[rev[i]]);
    for (i = 2; i <= N; i <<= 1) {
        int step = qpow(t ? g : invg, (mod - 1) / i);
        for (j = 0; j < N; j += i) {
            int now = 1;
            for (k = j; k < j + (i >> 1); k++) {
                int tmp = 1ll * f[k + (i >> 1)] * now % mod;
                f[k + (i >> 1)] = (f[k] - tmp) % mod;
                f[k] = (f[k] + tmp) % mod;
                now = 1ll * now * step % mod;
            }
        }
    }
}
void Fmulti (int *f, int *g, int N) {
    NTT(f, 1, N); NTT(g, 1, N);
    for (int i = 0; i < N; i++) g[i] = 1ll * f[i] * g[i] % mod;
    NTT(g, 0, N);
    for (int i = 0, j = qpow(N, mod - 2); i < N; i++) g[i] = 1ll * g[i] * j % mod;
}
int F[MAXN], G[MAXN], H[MAXN], P[MAXN];
void Finv (int *f, int *g, int N) {
    int i, j, len;
    g[0] = qpow(f[0], mod - 2);
    for (len = 2; len <= N; len <<= 1) {
        for (i = 0; i < len; i++) F[i] = f[i], F[i + len] = 0;
        NTT(F, 1, len << 1); NTT(g, 1, len << 1);
        for (i = 0; i < (len << 1); i++) g[i] = ((g[i] << 1) % mod - 1ll * g[i] * g[i] % mod * F[i] % mod) % mod;
        NTT(g, 0, len << 1);
        for (i = 0, j = qpow(len << 1, mod - 2); i < len; i++) g[i] = 1ll * g[i] * j % mod, g[i + len] = 0;
    }
}

void Fderi (int *f, int N) {
    for (int i = 0; i < N; i++)
        f[i] = 1ll * (i + 1) * f[i + 1] % mod;
}
void Finter (int *f, int N) {
    for (int i = N - 1; i > 0; i--)
        f[i] = 1ll * qpow(i, mod - 2) * f[i - 1] % mod;
    f[0] = 0;
}

void Fln (int *f, int *g, int N) {
    Finv(f, g, N); Fderi(f, N);
    Fmulti(f, g, N << 1);
    Finter(g, N << 1);
    for (int i = 0; i < N; i++) f[i + N] = g[i + N] = 0;
}

void Fexp (int *f, int *g, int N) {
    int i, j, len;
    for (i = 0; i < N; i++) G[i] = 0;
    g[0] = 1;
    for (len = 2; len <= N; len <<= 1) {
        for (i = 0; i < (len >> 1); i++) G[i] = g[i], G[i + (len >> 1)] = 0;
        Fln(G, H, len);
        for (i = 0; i < len; i++) H[i] = (f[i] - H[i]) % mod; ++H[0];
        Fmulti(H, g, len << 1);
        for (i = 0; i < len; i++) H[i] = H[i + len] = 0, g[i + len] = 0;
    }
}

void Fpow (int *f, int *g, int k, int N) {
    for (int i = 0; i < N; i++) P[i] = 0;
    Fln(f, P, N);
    for (int i = 0; i < N; i++) P[i] = 1ll * P[i] * k % mod;
    Fexp(P, g, N);
}

void Fsqrt (int *f, int *g, int N) { Fpow(f, g, inv2, N); }
void Fadd (int *f, int *g, int N) { for (int i = 0; i < N; i++) g[i] = (g[i] + f[i]) % mod; }
void FmultiN (int *f, int k, int N) { for (int i = 0; i < N; i++) f[i] = 1ll * f[i] * k % mod; }
void Fcopy (int *f, int *g, int N) { for (int i = 0; i < N; i++) f[i] = g[i]; }

int S[MAXN] = {1, 6, 1}, Sq[MAXN], iSq[MAXN];
int n, k;
int Z1[MAXN];
int S1[MAXN];

int main () {
    scanf("%d%d", &n, &k);
    int i, N;
    for (i = 1; i <= k; i <<= 1); N = i;
    Fsqrt(S, Sq, N); Finv(Sq, iSq, N);
    Fcopy(Z1, Sq, N); ++Z1[0], ++Z1[1]; FmultiN(Z1, inv2, N);
    Fpow(Z1, S1, n + 1, N);
    Fmulti(S1, iSq, N << 1);
    for (i = 1; i <= min(n, k); i++) printf("%d ", (iSq[i] + mod) % mod);
    for (i = min(n, k) + 1; i <= k; i++) putchar('0'), putchar(' ');
    return 0;
}