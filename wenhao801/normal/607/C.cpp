#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define pii pair<int, int>
#define fr first
#define se second
const int MAXN = 1001000, base1 = 998244353, mod1 = 1e9 + 9, base2 = 10007, mod2 = 1004535809;
int qpow (int x, int y, int mod) {
	int ret = 1;
	while (y) {
		if (y & 1) ret = 1ll * ret * x % mod;
		x = 1ll * x * x % mod; y >>= 1;
	}
	return ret;
}
int inv (int x, int mod) { return qpow(x, mod - 2, mod); }

int _[505]; char s[MAXN];

int n, a[MAXN], b[MAXN];

pii qry (int l, int r, pii *f) {
	pii ret = f[r];
	ret.fr = (ret.fr - 1ll * qpow(base1, r - l + 1, mod1) * f[l - 1].fr) % mod1;
	ret.se = (ret.se - 1ll * qpow(base2, r - l + 1, mod2) * f[l - 1].se) % mod2;
	ret.fr = (ret.fr + mod1) % mod1; ret.se = (ret.se + mod2) % mod2;
	return ret;
}
pii f[MAXN], g[MAXN];

int main () {
	_['N'] = 0, _['S'] = 3, _['W'] = 1, _['E'] = 2;
	scanf("%d", &n); --n; int i, j;
	scanf("%s", s + 1);
	for (i = 1; i <= n; i++) a[i] = _[s[i]] ^ 3;
	reverse(a + 1, a + n + 1);
	scanf("%s", s + 1);
	for (i = 1; i <= n; i++) b[i] = _[s[i]];
	for (i = 1; i <= n; i++) f[i].fr = (1ll * f[i - 1].fr * base1 + a[i] + 1) % mod1, f[i].se = (1ll * f[i - 1].se * base2 + a[i] + 1) % mod2;
	for (i = 1; i <= n; i++) g[i].fr = (1ll * g[i - 1].fr * base1 + b[i] + 1) % mod1, g[i].se = (1ll * g[i - 1].se * base2 + b[i] + 1) % mod2;
	for (i = 1; i <= n; i++) if (qry(i, n, g) == qry(1, n - i + 1, f)) { puts("NO"); return 0; }
	puts("YES");
	return 0;
}