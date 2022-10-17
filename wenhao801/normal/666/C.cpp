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

const int MAXN = 100100, mod = 1e9 + 7;
union mint {
	int x;
	mint () { x = 0; }
	mint (int _x) { x = _x % mod; if (x < 0) x += mod; }
	mint operator + (const mint &t) const { return mint{x + t.x >= mod ? (x + t.x - mod) : (x + t.x)}; }
	mint operator - (const mint &t) const { return mint{x < t.x ? (x - t.x + mod) : (x - t.x)}; }
	mint operator * (const mint &t) const { return mint{1ll * x * t.x % mod}; }
	mint operator -() const { return x ? (mod - x) : x; }
	void operator += (const mint &t) { x += t.x; if (x >= mod) x -= mod; }
	void operator -= (const mint &t) { x -= t.x; if (x < 0) x += mod; }
	void operator *= (const mint &t) { x = 1ll * x * t.x % mod; }
	bool operator == (const mint &t) const { return x == t.x; }
	bool operator != (const mint &t) const { return x != t.x; }
	explicit operator int() const { return x; }
};
mint qpow (mint x, int y) { mint ret = 1; for (; y; x *= x, y >>= 1) if (y & 1) ret *= x; return ret; }
mint inv (mint x) { return qpow(x, mod - 2); }
mint fac[MAXN], ifac[MAXN];
mint binom (int x, int y) { return (x < y || y < 0) ? 0 : (fac[x] * ifac[y] * ifac[x - y]); }

const int lim = 316;
mint pre[lim + 5][MAXN], now[MAXN]; char s[MAXN];

int main () {
	int i, j; fac[0] = ifac[0] = 1;
	for (i = 1; i < MAXN; i++) fac[i] = fac[i - 1] * i;
	ifac[MAXN - 1] = inv(fac[MAXN - 1]); for (i = MAXN - 2; i >= 1; i--) ifac[i] = mint(i + 1) * ifac[i + 1];

	for (i = 1; i <= lim; i++) {
		mint A = 1, B = 1, C = mint(25) * inv(26);
		for (j = 0; j <= 100000 - i; j++) {
			pre[i][j] = (j ? pre[i][j - 1] : 0) * mint(26) + A * B * binom(j + i - 1, i - 1);
			A *= 26, B *= C;
		}
	}

	int T = read(), L;
	for (int it = 0; it <= T; it++) {
		int op = 1; if (it) op = read();
		if (op == 1) {
			scanf("%s", s); L = strlen(s);
			if (L > lim) {
				mint A = 1, B = 1, C = mint(25) * inv(26);
				for (j = 0; j <= 100000 - i; j++) {
					now[j] = (j ? now[j - 1] : 0) * mint(26) + A * B * binom(j + L - 1, L - 1);
					A *= 26, B *= C;
				}
			}
		}
		else {
			int x = read();
			if (x < L) puts("0");
			else printf("%d\n", L <= lim ? pre[L][x - L] : now[x - L]);
		}
	}
	return 0;
}