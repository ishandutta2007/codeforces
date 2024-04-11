#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MX = 5e5 + 1;

struct lazy_segment_tree {

	struct node {
		long long val = INF;

		node() {}

		node(long long _val) : val(_val) {}
	};

	vector<node> tree;
	vector<long long> lazy;
	int n;

	node combine(const node& a, const node& b) {
		return node(min(a.val, b.val));
	}

	void push(long long v) {
		for (int i = 0; i < 2; ++i) {
			tree[v * 2 + i].val += lazy[v];
			lazy[v * 2 + i] += lazy[v];
		}
		lazy[v] = 0;
	}

	void build(int v, int l, int r) {
		if (l == r) {
			tree[v] = node();
		} else {
			int m = (l + r) / 2;
			build(v * 2, l, m);
			build(v * 2 + 1, m + 1, r);
			tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
		}
	}

	void upd(int a, int b, int val, int v, int l, int r) {
		if (b < l || r < a) {
			return;
		} else if (a <= l && r <= b) {
			tree[v].val += val;
			lazy[v] += val;
		} else {
			push(v);
			int m = (l + r) / 2;
			upd(a, b, val, v * 2, l, m);
			upd(a, b, val, v * 2 + 1, m + 1, r);
			tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
		}
	}

	void upd(int a, int b, int val) {
		upd(a, b, val, 1, 1, n);
	}

	void set(int a, long long val, int v, int l, int r) {
		if (l == r) {
			tree[v] = node(val);
		} else {
			push(v);
			int m = (l + r) / 2;
			if (a <= m) {
				set(a, val, v * 2, l, m);
			} else {
				set(a, val, v * 2 + 1, m + 1, r);
			}
			tree[v] = combine(tree[v * 2], tree[v * 2 + 1]);
		}
	}

	void set(int a, long long val) {
		set(a, val, 1, 1, n);
	}

	node qry(int a, int b, int v, int l, int r) {
		if (b < l || r < a) {
			return node();
		} else if (a <= l && r <= b) {
			return tree[v];
		}

		push(v);
		int m = (l + r) / 2;
		return combine(
				qry(a, b, v * 2, l, m),
				qry(a, b, v * 2 + 1, m + 1, r)
		);
	}

	node qry(int a, int b) {
		return qry(a, b, 1, 1, n);
	}

	lazy_segment_tree(int _n) : tree(4 * _n), lazy(4 * _n), n(_n) {
		build(1, 1, n);
	}

} st(MX);

vector<tuple<int, int, int>> req[MX];
vector<pair<int, int>> adj[MX];
long long ans[MX];
int time_out[MX];
int n;

void dfs_dist(int u, long long cur) {
	if (adj[u].empty()) {
		st.set(u, cur);
	}
	time_out[u] = u;
	for (auto [c, w] : adj[u] ){
		dfs_dist(c, cur + w);
		time_out[u] = time_out[c];
	}
}

void dfs(int u) {
	for (auto [l, r, i] : req[u]) {
		ans[i] = st.qry(l, r).val;
	}
	for (auto [c, w] : adj[u]) {
		st.upd(1, n, w);
		st.upd(c, time_out[c], -2 * w);
		dfs(c);
		st.upd(c, time_out[c], 2 * w);
		st.upd(1, n, -w);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> n >> q;

	for (int i = 2; i <= n; ++i) {
		int par, w;
		cin >> par >> w;
		adj[par].emplace_back(i, w);
	}

	for (int i = 0; i < q; ++i) {
		int v, l, r;
		cin >> v >> l >> r;
		req[v].emplace_back(l, r, i);
	}

	dfs_dist(1, 0);
	dfs(1);

	for (int i = 0; i < q; ++i) {
		cout << ans[i] << "\n";
	}
}