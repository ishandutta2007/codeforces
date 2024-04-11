#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 3e5;

struct Node {
	ll sum = 0, pre = 0, suf = 0, res = 0;
} st[MX * 2];

int n, oth[MX], seg[MX], d[MX];

Node combine(Node a, Node b) {
	Node res;
	res.sum = a.sum + b.sum;
	res.pre = max(a.pre, a.sum + b.pre);
	res.suf = max(b.suf, a.suf + b.sum);
	res.res = max({a.res, b.res, a.suf + b.pre});
	return res;
}

Node qry(int a, int b) {
	Node resl, resr;
	for (a += n, b += n; a <= b; a /= 2, b /= 2) {
		if (a % 2 == 1) {
			resl = combine(resl, st[a++]);
		}
		if (b % 2 == 0) {
			resr = combine(st[b--], resr);
		}
	}
	return combine(resl, resr);
}

void upd(int a, int val) {
	a += n;
	st[a].sum = st[a].pre = st[a].suf = st[a].res = val;
	for (a /= 2; a; a /= 2) {
		st[a] = combine(st[a * 2], st[a * 2 + 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a;
	cin >> n >> a;
	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		int c;
		cin >> d[i] >> c;
		upd(i, a - c);
		ans = max(ans, (ll)a - c);
	}
	for (int i = n - 1; i; --i) {
		d[i] -= d[i - 1];
	}

	iota(oth, oth + n, 0);
	iota(seg, seg + n - 1, 1);
	sort(seg, seg + n - 1, [&](int a, int b) {
		return d[a] < d[b];
	});

	for (int i = 0; i < n - 1; ++i) {
		int l = oth[seg[i] - 1];
		int r = oth[seg[i]];
		oth[l] = r;
		oth[r] = l;
		ans = max(ans, qry(l, r).res - (ll)d[seg[i]] * d[seg[i]]);
	}
	cout << ans << '\n';
}