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

const int MAXN = 400400, mod = 998244353, g = 3, invg = (mod + 1) / 3, inv2 = (mod + 1) >> 1;
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
int F[MAXN], G[MAXN], H[MAXN];
void NTT (int *f, bool t, int N) {
	int i, j, k;
	for (i = 0; i < N; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) ? (N >> 1) : 0);
	for (i = 0; i < N; i++) if (i < rev[i]) swap(f[i], f[rev[i]]);
	for (i = 2; i <= N; i <<= 1) {
		int st = qpow(t ? g : invg, (mod - 1) / i);
		for (j = 0; j < N; j += i) {
			int now = 1;
			for (k = j; k < j + (i >> 1); k++) {
				int tmp = 1ll * now * f[k + (i >> 1)] % mod;
				f[k + (i >> 1)] = (f[k] - tmp) % mod;
				f[k] = (f[k] + tmp) % mod;
				now = 1ll * now * st % mod;
			}
		}
	}
}

int invTmp[MAXN];
void Finv (int *f, int *g, int N) {
	int i, j, len;
	for (i = 0; i < N; i++) g[i] = 0;
	g[0] = qpow(f[0], mod - 2);
	for (len = 2; len <= N; len <<= 1) {
		for (i = 0; i < len; i++) invTmp[i] = f[i], invTmp[i + len] = 0;
		NTT(invTmp, 1, len << 1); NTT(g, 1, len << 1);
		for (i = 0; i < (len << 1); i++) g[i] = ((g[i] << 1) % mod - 1ll * g[i] * g[i] % mod * invTmp[i] % mod) % mod;
		NTT(g, 0, len << 1);
		for (i = 0, j = qpow(len << 1, mod - 2); i < len; i++) g[i] = 1ll * g[i] * j % mod, g[i + len] = 0;
	}
}

void Fsqrt (int *f, int *g, int N) {
	int i, j, len;
	for (i = 0; i < N; i++) g[i] = 0;
	g[0] = 1;
	for (len = 2; len <= N; len <<= 1) {
		for (i = 0; i < len; i++) F[i] = f[i], G[i] = (g[i] << 1) % mod, H[i] = 0;
		Finv(G, H, len); NTT(F, 1, len << 1), NTT(H, 1, len << 1);
		for (i = 0; i < (len << 1); i++) H[i] = 1ll * H[i] * F[i] % mod;
		NTT(H, 0, len << 1);
		for (i = 0, j = qpow(len << 1, mod - 2); i < len; i++) F[i] = (1ll * inv2 * g[i] % mod + 1ll * j * H[i] % mod) % mod;
		for (i = 0; i < len; i++) g[i] = F[i], g[i + len] = 0;
	}
}

int A[MAXN], B[MAXN];

int main () {
	int N = read(), M = read(), i, j;
	for (i = 0; i < N; i++) j = read(), A[j] = (A[j] - 4) % mod;
	++A[0];
	for (i = 1; i < 100000; i <<= 1);
	Fsqrt(A, B, i); ++B[0]; Finv(B, A, i);
	for (i = 1; i <= M; i++) printf("%d\n", ((A[i] << 1) % mod + mod) % mod);
	return 0;
}