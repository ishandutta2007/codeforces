#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5;

ll seg_tree[MX * 4], lazy[MX * 4];
vector<array<int, 2>> adj[MX];
int x[MX], y[MX], n;
ll res[MX];

void push(int v) {
	for (int i = 0; i < 2; ++i) {
		seg_tree[v * 2 + i] += lazy[v];
		lazy[v * 2 + i] += lazy[v];
	}
	lazy[v] = 0;
}

void upd(int a, int b, ll val, int v = 1, int l = 0, int r = n - 1) {
	if (b < l || r < a)
		return;
	if (a <= l && r <= b) {
		seg_tree[v] += val;
		lazy[v] += val;
		return;
	}
	push(v);
	int m = (l + r) / 2;
	upd(a, b, val, v * 2, l, m);
	upd(a, b, val, v * 2 + 1, m + 1, r);
	seg_tree[v] = min(seg_tree[v * 2], seg_tree[v * 2 + 1]);
}

ll qry(int a, int b, int v = 1, int l = 0, int r = n - 1) {
	if (b < l || r < a)
		return 1e18;
	if (a <= l && r <= b)
		return seg_tree[v];
	push(v);
	int m = (l + r) / 2;
	return min(qry(a, b, v * 2, l, m),
			qry(a, b, v * 2 + 1, m + 1, r));
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m, q;
	cin >> n >> m >> q;

	for (int i = 0; i < n - 1; ++i) {
		cin >> x[i] >> y[i];
	}

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u - 1].push_back({v - 1, w});
	}

	for (int i = 0; i < n - 1; ++i) {
		upd(i + 1, i + 1, y[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (auto e : adj[i]) {
			upd(0, e[0], e[1]);
		}
		res[i] = seg_tree[1];
	}

	memset(seg_tree, 0, sizeof seg_tree);
	memset(lazy, 0, sizeof lazy);
	for (int i = 0; i < n; ++i) {
		upd(i, i, x[i] + res[i]);
	}

	cout << seg_tree[1] << '\n';
	while (q--) {
		int v, w;
		cin >> v >> w;
		--v;
		upd(v, v, w - x[v]);
		x[v] = w;
		cout << seg_tree[1] << '\n';
	}
}