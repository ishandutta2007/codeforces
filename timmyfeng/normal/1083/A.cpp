#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int gas[N];
long long ans;
long long dp[N];
vector<pair<int, int>> adj[N];

void dfs(int u, int p) {
	long long chd_a = 0;
	long long chd_b = 0;
	for (auto [c, w] : adj[u]) {
		if (c != p) {
			dfs(c, u);
			if (dp[c] - w > chd_a) {
				chd_b = chd_a;
				chd_a = dp[c] - w;
			} else {
				chd_b = max(chd_b, dp[c] - w);
			}
		}
	}
	ans = max(ans, chd_a + chd_b + gas[u]);
	dp[u] = gas[u] + chd_a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> gas[i];
	}
	for (int i = 0;i  < n -1 ;++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	dfs(1, 0);

	cout << ans << "\n";
}