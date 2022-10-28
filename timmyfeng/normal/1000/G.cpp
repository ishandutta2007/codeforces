#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 3e5 + 1;
const int MXQ = 4e5 + 1;
const int LOGN = 19;

int time_in[MX], time_out[MX], par[LOGN][MX], a[MX], t, logn;
ll dp_up[MX], dp_down[MX], pre_sum[MX], ans[MXQ];
vector<pair<int, int>> req[MX], adj[MX];

ll chd_cont(int c, int w) {
	return max(0LL, dp_down[c] + a[c] - 2 * w);
}

void dfs_down(int u) {
	time_in[u] = ++t;
	for (auto [c, w] : adj[u]) {
		if (c != par[0][u]) {
			par[0][c] = u;
			dfs_down(c);
			dp_down[u] += chd_cont(c, w);
		}
	}
	time_out[u] = t;
}

void dfs_up(int u) {
	for (auto [c, w] : adj[u]) {
		if (c != par[0][u]) {
			dp_up[c] = max(0LL, dp_up[u] + dp_down[u] - chd_cont(c, w) + a[u] - 2 * w);
			dfs_up(c);
		}
	}
}

void dfs(int u) {
	pre_sum[u] = pre_sum[par[0][u]] + dp_down[u];
	for (auto [c, w] : adj[u]) {
		if (c != par[0][u]) {
			pre_sum[u] -= chd_cont(c, w);
			pre_sum[u] += a[c] - w;
			dfs(c);
			pre_sum[u] -= a[c] - w;
			pre_sum[u] += chd_cont(c, w);
		}
	}

	for (auto [v, i] : req[u]) {
		ans[i] += pre_sum[u] - pre_sum[par[0][v]];
	}
}

bool is_anc(int u, int v) {
	return time_in[u] <= time_in[v] && time_out[v] <= time_out[u];
}

int lca(int u, int v) {
	if (is_anc(u, v))
		return u;
	if (is_anc(v, u))
		return v;
	for (int i = logn - 1; i >= 0; --i) {
		if (!is_anc(par[i][u], v)) {
			u = par[i][u];
		}
	}
	return par[0][u];
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	dfs_down(1);
	time_out[0] = t;
	dfs_up(1);

	for (logn = 1; (1 << logn) < n; ++logn) {
		for (int i = 1; i <= n; ++i) {
			par[logn][i] = par[logn - 1][par[logn - 1][i]];
		}
	}

	for (int i = 0; i < q; ++i) {
		int u, v;
		cin >> u >> v;
		int anc = lca(u, v);
		req[u].emplace_back(anc, i);
		req[v].emplace_back(anc, i);
		ans[i] = dp_up[anc] - dp_down[anc] + a[anc];
	}

	dfs(1);
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << '\n';
	}
}