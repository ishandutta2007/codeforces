#include <bits/stdc++.h>
using namespace std;

const int MX = 3e5 + 1;

int col[MX], up[MX], down[MX], dp[MX], ans;
vector<int> adj[MX], chd[MX];

void dfs_back(int u, int p) {
	col[u] = 1;
	for (auto c : adj[u]) {
		if (c == p || col[c] == 2)
			continue;
		if (col[c]) {
			++down[c];
			++up[u];
		} else {
			chd[u].push_back(c);
			dfs_back(c, u);
		}
	}
	col[u] = 2;
}

int dfs(int u) {
	dp[u] = up[u] - down[u];
	int mx = 0, mx2 = 0;
	for (auto c : chd[u]) {
		int res = dfs(c);
		if (res > mx) {
			mx2 = mx;
			mx = res;
		} else {
			mx2 = max(mx2, res);
		}
		dp[u] += dp[c];
	}
	int res = mx + !dp[u];
	ans = max(ans, mx + mx2);
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs_back(1, 0);
	dfs(1);
	cout << ans << '\n';
}