#include <bits/stdc++.h> 
using namespace std;

const int MX = 2e5 + 1;

map<int, int> dp[MX];
vector<int> adj[MX];
int a[MX], ans;

void dfs(int u, int p) {
	for (int i = 2; i * i <= a[u]; ++i) {
		if (a[u] % i)
			continue;
		dp[u][i] = 1;
		while (a[u] % i == 0) {
			a[u] /= i;
		}
	}
	if (a[u] > 1) {
		dp[u][a[u]] = 1;
	}

	for (auto c : adj[u]) {
		if (c == p)
			continue;
		dfs(c, u);
		for (auto [p, l] : dp[c]) {
			if (dp[u].count(p)) {
				ans = max(ans, l + dp[u][p]);
				dp[u][p] = max(dp[u][p], l + 1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
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

	for (int i = 1; i <= n; ++i) {
		for (auto [p, l] : dp[i]) {
			ans = max(ans, l);
		}
	}
	cout << ans << '\n';
}