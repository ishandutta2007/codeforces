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

const int mod = 1e9 + 7, MAXN = 1001000, lim = 1e6;
inline int add (int u, int v) { u += v; if (u >= mod) u -= mod; return u; }
inline int dec (int u, int v) { u -= v; if (u < 0) u += mod; return u; }

struct node {
	int s[3];
	node (int x = 0) { s[0] = 2, s[1] = x, s[2] = 1ll * x * x % mod; }
	node operator + (const node &tmp) const {
		node ret = node();
		ret.s[0] = 1ll * s[0] * tmp.s[0] % mod;
		ret.s[1] = add(1ll * s[0] * tmp.s[1] % mod, 1ll * s[1] * tmp.s[0] % mod);
		ret.s[2] = add(add(1ll * s[0] * tmp.s[2] % mod, 1ll * s[1] * tmp.s[1] % mod), add(1ll * s[2] * tmp.s[0] % mod, 1ll * s[1] * tmp.s[1] % mod));
		return ret;
	}
} h[MAXN];
int s[MAXN];

int main () {
	int n = read(), i, j;
	for (i = 0; i <= lim; i++) h[i].s[0] = 1, h[i].s[1] = h[i].s[2] = 0;
	for (i = 1; i <= n; i++) {
		int x = read();
		h[x] = h[x] + node(x);
	}
	int now = 1;
	for (i = 0; i < 6; i++) {
		for (j = lim - 1; j >= 0; j--) if ((j / now) % 10 != 9) h[j] = h[j] + h[j + now]; 
		now *= 10;
	}
	for (i = 0; i < lim; i++) s[i] = h[i].s[2];
	now = 1;
	for (i = 0; i < 6; i++) {
		for (j = 0; j < lim; j++) if ((j / now) % 10 != 9) s[j] = dec(s[j], s[j + now]);
		now *= 10;
	}
	long long ans = 0;
	for (i = 0; i < lim; i++) ans ^= 1ll * i * s[i];
	printf("%lld\n", ans);
	return 0;
}