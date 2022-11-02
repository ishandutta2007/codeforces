#include <bits/stdc++.h>

typedef long long ll;

const int N = 200000;
const int P = 998244353;

int read() {
	int x = 0, ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while ('0' <= ch && ch <= '9') x = 10 * x + ch - '0', ch = getchar();
	return x;
}

namespace BIT{
	int a[N + 5], n;

	void init(int _n) {
		n = _n;
		for (int i = 1; i <= n; i++)
			a[i] = 0;
	}
	void add(int p) {
		for (int i = p; i <= n; i += (i & -i)) a[i]++;
	}
	int sum(int p) {
		int ans = 0;
		for (int i = p; i; i ^= (i & -i)) ans += a[i];
		return ans;
	}
}

struct node{
	ll s; int i; bool t;
	friend bool operator < (const node &a, const node &b) {
		return (a.s == b.s) ? (a.t < b.t) : (a.s < b.s);
	}
};
std::vector<node>v[2];

int a[N + 5], n;
void solve() {
	n = read(); for (int i = 1; i <= n; i++) a[i] = read();
	
	ll ans = 0, s1 = 0, s2 = 0, s3 = 0;
	v[0].clear(), v[1].clear();
	for (int i = 1; i <= n; i++) s3 += a[i];
	for (int i = 0; i <= n; i++) {
		s2 = -(s2 + a[i]), s1 += a[i], s3 -= a[i];
		v[i & 1].push_back((node){s3 + s2, i, 0});
		if (n - i >= 3) v[i & 1].push_back((node){s3 - a[n] - a[n] + s2, i, 0});
		v[i & 1].push_back((node){s1 + s2, i, 1});
		if (i >= 3) v[i & 1].push_back((node){s1 - a[1] - a[1] + s2, i, 1});

		if (2 <= i && i <= n - 2) ans += (s1 - s3 > 0);
	}

	for (int o = 0; o < 2; o++) {
		BIT::init(n + 1), std::sort(v[o].begin(), v[o].end());
		for (auto k : v[o]) {
			if (k.t) BIT::add(k.i + 1);
			else ans += BIT::sum(k.i + 1);
		}
	}
	printf("%lld\n", ans % P);
}

int main() {
	for (int t = read(); t; t--) solve();
}