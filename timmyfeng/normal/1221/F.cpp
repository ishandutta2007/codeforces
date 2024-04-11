#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5;
using ll = long long;

int og[MX];
ll lazy[4 * MX];
pair<ll, int> st[4 * MX]; 
tuple<int ,int , int> seg[MX];

void build(int u, int l, int r) {
	if (l == r) {
		st[u].second = l;
		return;
	}
	int m = (l + r) / 2;
	build(u * 2, l, m);
	build(u * 2 + 1, m + 1, r);
}

void push(int u) {
	st[u * 2].first += lazy[u];
	lazy[u * 2] += lazy[u];
	st[u * 2 + 1].first += lazy[u];
	lazy[u * 2 + 1] += lazy[u];
	lazy[u] = 0;
}

void update(int u, int l, int r, int a, int b, ll val) {
	if (a > b) return;
	if (l == a && r == b) {
		st[u].first += val;
		lazy[u] += val;
		return;
	}
	push(u);
	int m = (l + r) / 2;
	update(u * 2, l, m, a, min(b, m), val);
	update(u * 2 + 1, m + 1, r, max(a, m + 1), b, val);
	st[u] = max(st[u * 2], st[u * 2 + 1]);
}

pair<ll, int> query(int u, int l, int r, int a, int b) {
	if (a > b) return {-1e18, -1};
	if (l == a && r == b) {
		return st[u];
	}
	push(u);
	int m = (l + r) / 2;
	return max(query(u * 2, l, m, a, min(b, m)),
			query(u * 2 + 1, m + 1, r, max(a, m + 1), b));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		seg[i] = make_tuple(min(x, y), max(x, y), c);
	}

	build(1, 0, n - 1);
	sort(seg, seg + n, [](tuple<int, int, int> a, tuple<int, int, int> b) {return get<1>(a) < get<1>(b);});
	int prev = -1, sz = 0;
	for (int i = 0; i < n; ++i) {
		auto&[x, y, c] = seg[i];
		if (y == prev) {
			y = sz - 1;
		} else {
			prev = y;
			og[sz++] = y;
			y = sz - 1;
		}
		update(1, 0, n - 1, y, n - 1, c);
	}

	for (int i = 0; i < sz; ++i) {
		update(1, 0, n - 1, i, i, -(og[i] + 1));
	}

	sort(seg, seg + n);	
	int cur = 0;
	prev = -1;
	ll ans = 0;
	int ansx = og[sz - 1] + 1, ansy = og[sz - 1] + 1;
	for (int i = 0; i < n; ++i) {
		auto[x, y, c] = seg[i];
		if (x == prev) {
			update(1, 0, n - 1, y, sz - 1, -c);
			continue;
		}
		for ( ; x > og[cur]; ++cur);
		update(1, 0, n - 1, cur, sz - 1, x - prev);
		auto q = query(1, 0, n - 1, cur, sz - 1);
		if (q.first > ans) {
			ans = q.first;
			ansx = x;
			ansy = og[q.second];
		}
		prev = x;
		update(1, 0, n - 1, y, sz - 1, -c);
	}
	cout << ans << '\n';
	cout << ansx << ' ' << ansx << ' ' << ansy << ' ' << ansy << '\n';
}