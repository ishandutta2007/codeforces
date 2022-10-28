#include <bits/stdc++.h> 
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n + 1);
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	vector<int> ans, path(n + 1, 0);
	for (int i = 1; i <= n; ++i) {
		if (path[i] == 2) {
			ans.push_back(i);
			path[i] = -1;
		}
		for (auto j : adj[i]) {
			path[j] = max(path[j], path[i] + 1);
		}
	}

	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i << " ";
	}
	cout << "\n";
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