#include <bits/stdc++.h> 
using namespace std;

const int MX = 201;

int dp[MX][MX], a[MX], k;
vector<int> adj[MX];

void dfs(int u, int p) {
	if (p) {
		adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
	}

	for (auto c : adj[u]) {
		dfs(c, u);
	}

	for (int i = k; i; --i) {
		dp[u][i] = (i < k ? dp[u][i + 1] : 0);
		int j = max(k - i, i);
		int sum = 0;
		for (auto c : adj[u]) {
			sum += dp[c][j - 1];
		}
		for (auto c : adj[u]) {
			dp[u][i] = max(dp[u][i], sum + dp[c][i - 1] - dp[c][j - 1]);
		}
	}

	dp[u][0] = max(dp[u][1], a[u] + dp[u][k]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n >> k;
	++k;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	
	int ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= k; ++j) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << '\n';
}