#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cassert>

using namespace std;

#define ll long long
inline ll read() {
	ll ret = 0, t = 1;
	char c = getchar();
	while ((c < '0' || c > '9') && c != '-') c = getchar();
	if (c == '-') t = -1, c = getchar();
	while (c >= '0' && c <= '9') ret = (ret * 10) + c - '0', c = getchar();
	return ret * t;
}

const ll inf = (1ll << 60) - 1, mod = 998244353, inv2 = (mod + 1) >> 1;
#define pii pair <ll, ll>
#define fr first
#define se second

vector <pii> A, B, res;

namespace solve {
	vector <ll> a[66], b[66];

	struct node { int ls, rs; } t[3003000];
	int top = 1;

	void ins_a (ll l, ll r, ll L, ll R, int d) {
		if (l <= L && R <= r) { a[d].push_back(L); return; }
		ll mid = (L + R) >> 1;
		if (l <= mid) ins_a(l, r, L, mid, d - 1);
		if (mid < r) ins_a(l, r, mid + 1, R, d - 1);
	}
	void ins_b (ll l, ll r, ll L, ll R, int x) {
		if (l <= L && R <= r) return;
		ll mid = (L + R) >> 1;
		if (l <= mid) ins_b(l, r, L, mid, t[x].ls ? t[x].ls : (t[x].ls = ++top));
		if (mid < r) ins_b(l, r, mid + 1, R, t[x].rs ? t[x].rs : (t[x].rs = ++top));
	}
	void claim (ll l, ll r, int x, int d) {
		b[d].push_back(l); ll mid = (l + r) >> 1;
		if (t[x].ls) claim(l, mid, t[x].ls, d - 1);
		if (t[x].rs) claim(mid + 1, r, t[x].rs, d - 1);
	}

	void main () {
		int i, j;
		for (i = 1; i <= top; i++) t[i].ls = t[i].rs = 0;
		for (i = 0; i <= 60; i++) a[i].clear(), b[i].clear();
		top = 1;
		for (auto i: A) ins_a(i.fr, i.se, 0, inf, 60);
		for (auto i: B) ins_b(i.fr, i.se, 0, inf, 1);
		claim(0, inf, 1, 60);
		for (i = 0; i <= 60; i++) for (auto u: a[i]) for (auto v: b[i]) {
			assert((u & -u) >= (1ll << i) || !u); assert((v & -v) >= (1ll << i) || !v);
			res.emplace_back(u ^ v, (u ^ v) + (1ll << i) - 1);
		}
	}
}

bool cmp (pii u, pii v) {
	if (u.fr == v.fr) return u.se < v.se;
	else return u.fr < v.fr;
}

int main () {
	int i, j, n = read();
	for (i = 1; i <= n; i++) { ll l = read(), r = read(); A.emplace_back(l, r); }
	n = read();
	for (i = 1; i <= n; i++) { ll l = read(), r = read(); B.emplace_back(l, r); }
	solve::main(); swap(A, B); solve::main();
	sort(res.begin(), res.end(), cmp);
	ll ans = 0, l = 0, r = -1;
	for (auto i: res) {
		if (i.fr > r) {
			if (r != -1) ans = (ans + 1ll * (l + r) % mod * ((r - l + 1) % mod) % mod * inv2) % mod;
			l = i.fr;
		}
		r = max(r, i.se);
	}
	if (r != -1) ans = (ans + 1ll * (l + r) % mod * ((r - l + 1) % mod) % mod * inv2) % mod;
	printf("%lld\n", ans);
	return 0;
}