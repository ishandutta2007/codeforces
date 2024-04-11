#include <bits/stdc++.h>
using namespace std;

const int MX = 3e5;

vector<int> adj[MX + 1];
int fir[MX + 1], sec[MX + 1], dp[MX + 1];
int ans;

void dfs1(int u, int p) {
	fir[u] = sec[u] = 0;
	for (auto c : adj[u]) {
		if (c != p) {
			dfs1(c, u);
			if (dp[c] >= fir[u]) {
				sec[u] = max(sec[u], fir[u]);
				fir[u] = dp[c];
			}
		}
	}
	dp[u] = (int)adj[u].size() - !!fir[u] + fir[u];
}

void dfs2(int u, int p, int pd) {
	int res = dp[u] + max(pd, sec[u]);
	ans = max(ans, res);
	for (auto c : adj[u]) {
		if (c != p) {
			if (fir[u] < pd || dp[c] == fir[u]) {
				dfs2(c, u, res - fir[u]);
			} else {
				dfs2(c, u, dp[u]);
			}
		}
	}
}

void solve() {
	int n;
	cin >> n;
	fill(adj + 1, adj + n + 1, vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	ans = 0;
	dfs1(1, 0);
	dfs2(1, 0, 1);
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}