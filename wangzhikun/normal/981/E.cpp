#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int MX = 10010;

bitset<MX> ans;
vector<int> rmq[50000];

void go(int v, int tl, int tr, bitset<MX> now) {
	for (int x: rmq[v]) {
		now |= (now << x);
	}
	if (tl + 1 == tr) {
		ans |= now;
		return;
	}
	int m = (tl + tr) >> 1;
	go(v * 2 + 1, tl, m, now);
	go(v * 2 + 2, m, tr, now);
}

void add(int v, int tl, int tr, int l, int r, int x) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		rmq[v].push_back(x);
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, x);
	add(v * 2 + 2, m, tr, l, r, x);
}

int n, q;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n >> q;
	for (int i = 0; i < q; ++i) {
		int l, r, x;
		cin >> l >> r >> x;
		--l;
		add(0, 0, n, l, r, x);
	}
	bitset<MX> bs;
	bs[0] = 1;
	go(0, 0, n, bs);
	vector<int> vv;
	for (int i = 1; i <= n; ++i)
		if (ans[i])
			vv.push_back(i);
	cout << vv.size() << "\n";
	for (int i: vv)
		cout << i << " ";
	cout << "\n";
	return 0;
}