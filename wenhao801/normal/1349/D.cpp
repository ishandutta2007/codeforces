#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cassert>

using namespace std;

inline int read() {
	int ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
	return ret * t;
}

const int MAXN = 300300, mod = 998244353;
union mint {
	int x;
	mint () { x = 0; }
	mint (int _x) { x = _x % mod; if (x < 0) x += mod; }
	void operator += (const mint &t) { x += t.x; if (x >= mod) x -= mod; }
	void operator -= (const mint &t) { x -= t.x; if (x < 0) x += mod; }
	void operator *= (const mint &t) { x = 1ll * x * t.x % mod; }
	bool operator == (const mint &t) const { return x == t.x; }
	bool operator != (const mint &t) const { return x != t.x; }
	mint operator + (const mint &t) const { mint tmp = *this; tmp += t; return tmp; }
	mint operator - (const mint &t) const { mint tmp = *this; tmp -= t; return tmp; }
	mint operator * (const mint &t) const { mint tmp = *this; tmp *= t; return tmp; }
	mint operator -() const { return x ? (mod - x) : x; }
	explicit operator int() const { return x; }
};
mint qpow(mint x, int y) { mint ret = 1; for (; y; x *= x, y >>= 1) if (y & 1) ret *= x; return ret; }
mint inv(mint x) { assert(x.x); return qpow(x, mod - 2); }
int n, a[MAXN]; mint c[MAXN], u[MAXN], v[MAXN], w[MAXN];

int main() {
	n = read(); int i, j, S = 0;
	for (i = 1; i <= n; i++) a[i] = read(), S += a[i];
	u[0] = inv(n - 1), v[0] = -u[0], w[0] = 1;
	for (i = 1; i <= S - 1; i++) {
		mint p = -mint(i) * inv(S), q = mint(1) - mint(S - i) * inv(S) * mint(n - 2) * inv(n - 1), r = -mint(S - i) * inv(S) * inv(n - 1), s = 1;
		q -= inv(u[i - 1]) * p * v[i - 1]; s -= inv(u[i - 1]) * p * w[i - 1];
		u[i] = q, v[i] = r, w[i] = s;
	}
	for (i = S - 1; i >= 0; i--) {
		w[i] -= v[i] * c[i + 1]; c[i] = w[i] * inv(u[i]);
	}
	mint ans = 0;
	for (i = 1; i <= n; i++) ans += c[a[i]];
	ans -= c[0] * (n - 1); ans *= inv(n);
	printf("%d\n", ans);
	return 0;
}