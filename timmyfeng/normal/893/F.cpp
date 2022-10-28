#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e5 + 1;
const int MXST = 5e6;

int seg_tree[MXST], chd[MXST][2], root[MX], sz;
int time_in[MX], time_out[MX], dep[MX], t;
vector<int> level[MX], adj[MX];
int a[MX], n;

int new_node(int chd_l, int chd_r, int val) {
	++sz;
	chd[sz][0] = chd_l;
	chd[sz][1] = chd_r;
	seg_tree[sz] = val;
	return sz;
}

int upd(int a, int val, int v, int l = 1, int r = n) {
	if (l == r)
		return new_node(0, 0, val);
	int m = (l + r) / 2;
	if (a <= m) {
		int new_chd = upd(a, val, chd[v][0], l, m);
		return new_node(new_chd, chd[v][1], min(seg_tree[v], val));
	}
	int new_chd = upd(a, val, chd[v][1], m + 1, r);
	return new_node(chd[v][0], new_chd, min(seg_tree[v], val));
}

int qry(int a, int b, int v, int l = 1, int r = n) {
	if (b < l || r < a)
		return 1e9;
	if (a <= l && r <= b)
		return seg_tree[v];
	int m = (l + r) / 2;
	return min(qry(a, b, chd[v][0], l, m), qry(a, b, chd[v][1], m + 1, r));
}

void dfs(int u, int p) {
	level[dep[u]].push_back(u);
	time_in[u] = ++t;
	for (auto c : adj[u]) {
		if (c != p) {
			dep[c] = dep[u] + 1;
			dfs(c, u);
		}
	}
	time_out[u] = t;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int r;
	cin >> n >> r;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(r, 0);

	seg_tree[0] = 1e9;
	for (int i = 0, cur = 0; i < n; ++i) {
		for (auto j : level[i]) {
			cur = upd(time_in[j], a[j], cur);
		}
		root[i] = cur;
	}

	int m;
	cin >> m;
	int last = 0;
	while (m--) {
		int p, q;
		cin >> p >> q;

		p = (p + last) % n + 1;
		q = (q + last) % n;
		int mx_dep = min(dep[p] + q, n - 1);

		last = qry(time_in[p], time_out[p], root[mx_dep]);
		cout << last << '\n';
	}
}