#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 3000 + 1;

vector<pair<int, ll>> dp[MX];
vector<int> adj[MX];
int val[MX];

void dfs(int u, int p) {
	dp[u] = {{0, val[u]}};
	for (auto c : adj[u]) {
		if (c != p) {
			dfs(c, u);
			vector<pair<int, ll>> chd(dp[u].size() + dp[c].size(), {0, ll(-1e18)});
			for (int i = 0; i < int(dp[u].size()); ++i) {
				for (int j = 0; j < int(dp[c].size()); ++j) {
					chd[i + j] = max(chd[i + j], 
							{dp[u][i].first + dp[c][j].first, dp[u][i].second + dp[c][j].second});
					chd[i + j + 1] = max(chd[i + j + 1], 
							{dp[u][i].first + dp[c][j].first + (dp[c][j].second > 0), dp[u][i].second});
				}
			}
			swap(dp[u], chd);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> val[i];
		val[i] *= -1;
	}

	for (int i = 1; i <= n; ++i) {
		int w;
		cin >> w;
		val[i] += w;
	}

	fill(adj + 1, adj + n + 1, vector<int>());
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	cout << dp[1][m - 1].first + (dp[1][m - 1].second > 0) << "\n";
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