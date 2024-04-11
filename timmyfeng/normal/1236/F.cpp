#include <bits/stdc++.h>
using namespace std;

const int MX = 5e5 + 5;
const int M = 1e9 + 7;

int inv2[MX];

int pre_sum[MX];
int pre_edge[MX];

int col[MX];
int dep[MX];
int par[MX];
vector<int> adj[MX];

int sum_cyc;
vector<pair<int, int>> cycles;

int add(int a, int b) {
	return (a += b) < M ? a : a - M;
}

int sub(int a, int b) {
	return (a -= b) < 0 ? a + M : a;
}

int mul(int a, int b) {
	return 1LL * a * b % M;
}

void dfs(int u) {
	col[u] = 1;
	for (auto c : adj[u]) {
		if (c == par[u]) {
			continue;
		} else if (col[c] == 1) {
			cycles.emplace_back(c, u);
			int len = dep[u] - dep[c] + 1;
			pre_sum[u] = add(pre_sum[u], inv2[len]);
			pre_sum[par[c]] = sub(pre_sum[par[c]], inv2[len]);
			sum_cyc = add(sum_cyc, inv2[len]);
		} else if (!col[c]) {
			dep[c] = dep[u] + 1;
			par[c] = u;
			dfs(c);
			pre_sum[u] = add(pre_sum[u], pre_sum[c]);
		}
	}
	col[u] = 2;
}

void dfs_sum(int u) {
	col[u] = 3;
	pre_edge[u] += adj[u].size();
	for (auto c : adj[u]) {
		if (col[c] != 3) {
			pre_sum[c] = add(pre_sum[c], pre_sum[u]);
			pre_edge[c] = pre_edge[u];
			dfs_sum(c);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	inv2[0] = 1;
	for (int i = 1; i < MX; ++i) {
		inv2[i] = mul(inv2[i - 1], (M + 1) / 2);
	}

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1);
	dfs_sum(1);
	pre_sum[0] = 0;

	// E[X]^2
	int ans = mul(n, inv2[1]);
	ans = add(ans, sum_cyc);
	ans = sub(ans, mul(m, inv2[2]));
	ans = sub(0, mul(ans, ans));

	// E[nodes^2]
	ans = add(ans, mul(n, mul(n - 1, inv2[2])));
	ans = add(ans, mul(n, inv2[1]));

	// E[edges^2]
	for (int i = 1; i <= n; ++i) {
		for (auto j : adj[i]) {
			if (i < j) {
				int cnt = adj[i].size() + adj[j].size() - 1u;
				ans = add(ans, inv2[2]);
				ans = add(ans, mul(cnt - 1, inv2[3]));
				ans = add(ans, mul(m - cnt, inv2[4]));
			}
		}
	}

	// E[cycles^2]
	for (auto [u, v] : cycles) {
		int len = dep[v] - dep[u] + 1;
		int cnt = sub(sub(pre_sum[v], pre_sum[par[u]]), mul(len - 1, inv2[len]));
		ans = add(ans, mul(sub(sum_cyc, cnt), inv2[len]));
		ans = add(ans, mul(sub(cnt, inv2[len]), inv2[len - 1]));
		ans = add(ans, inv2[len]);
	}

	// E[nodes*edges]
	for (int i = 1; i <= n; ++i) {
		int cnt = adj[i].size();
		int res = mul(cnt, inv2[2]);
		res = add(res, mul(m - cnt, inv2[3]));
		ans = sub(ans, add(res, res));
	}

	// E[edges*cycles]
	for (auto [u, v] : cycles) {
		int len = dep[v] - dep[u] + 1;
		int cnt = pre_edge[v] - pre_edge[par[u]] - len;
		int res = mul(m - cnt, inv2[len + 2]);
		res = add(res, mul(cnt - len, inv2[len + 1]));
		res = add(res, mul(len, inv2[len]));
		ans = sub(ans, add(res, res));
	}

	// E[nodes*cycles]
	for (auto [u, v] : cycles) {
		int len = dep[v] - dep[u] + 1;
		int res = mul(n - len, inv2[len + 1]);
		res = add(res, mul(len, inv2[len]));
		ans = add(ans, add(res, res));
	}

	cout << ans << "\n";
}