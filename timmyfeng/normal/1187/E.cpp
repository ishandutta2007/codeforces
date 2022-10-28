#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 2e5;

vector<int> adj[MX + 1];
ll dp[MX + 1], ans;
int sz[MX + 1], n;

void dfs1(int u, int p) {
	sz[u] = 1;
	for (auto c : adj[u]) {
		if (c == p) continue;
		dfs1(c, u);
		sz[u] += sz[c];
		dp[u] += dp[c];
	}
	dp[u] += sz[u];
}

void dfs2(int u, int p, ll pd) {
	pd = dp[u] - sz[u] + pd + n;
	ans = max(ans, pd);
	for (auto c : adj[u]) {
		if (c == p) continue;
		dfs2(c, u, pd - sz[c] - dp[c]);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs1(1, 0);
	dfs2(1, 0, 0);

	cout << ans << '\n';
}