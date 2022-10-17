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

const int mod = 1e9 + 7, lim = 1e7, MAXN = lim + 50;
int qpow (int x, int y) {
    y = (y + mod - 1) % (mod - 1);
	int ret = 1;
	while (y) {
		if (y & 1) ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod; y >>= 1;
	}
	return ret;
}
int inv (int x) { return qpow(x, mod - 2); }

int pr[MAXN], tp; short mu[MAXN]; bool np[MAXN];

void sieve () {
	int i, j; mu[1] = 1;
	for (i = 2; i <= lim; i++) {
		if (!np[i]) pr[++tp] = i, mu[i] = -1;
		for (j = 1; j <= tp; j++) if (pr[j] * i <= lim) {
			np[pr[j] * i] = 1;
			if (i % pr[j] == 0) { mu[i * pr[j]] = 0; break; }
			mu[i * pr[j]] = -mu[i];
		} else break;
	}
}

int n, h[MAXN], c[MAXN], f[MAXN], p2[MAXN];

int main () {
    sieve();
    n = read(); int i, j;
    for (i = 1; i <= n; i++) ++c[read()];
    p2[0] = 1; for (i = 1; i <= lim; i++) p2[i] = (p2[i - 1] << 1) % mod;
    for (i = 1; i <= tp; i++) for (j = lim / pr[i]; j >= 1; j--) c[j] += c[pr[i] * j];
    for (i = 1; i <= lim; i++) h[i] = mu[i] * c[i];
    for (i = 1; i <= tp; i++) for (j = 1; pr[i] * j <= lim; j++) h[pr[i] * j] += h[j];
    for (i = 1; i <= lim; i++) c[i] = p2[c[i]] - 1;
    // actually g[], reuse c to cut down memory use
    for (i = 1; i <= lim; i++) for (j = 1; i * j <= lim; j++) f[i] = (f[i] + mu[j] * c[i * j]) % mod;
    int ans = 0;
    for (i = 2; i <= lim; i++) ans = (ans + 1ll * h[i] * f[i]) % mod;
    printf("%d\n", (ans + mod) % mod);
    return 0;
}