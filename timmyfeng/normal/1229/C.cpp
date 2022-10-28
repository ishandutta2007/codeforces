#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> cap(n + 1);
	vector<vector<int>> adj(n + 1);
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		if (u > v) {
			swap(u, v);
		}

		adj[u].push_back(v);
		++cap[u];
		++cap[v];
	}

	auto get = [&](int v) {
		return 1LL * int(adj[v].size()) * (cap[v] - int(adj[v].size()));
	};

	ll ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += get(i);
	}

	cout << ans << "\n";

	int q;
	cin >> q;
	for (int i = 1; i <= q; ++i) {
		int v;
		cin >> v;

		for (auto u : adj[v]) {
			ans -= get(u);
			adj[u].push_back(v);
			ans += get(u);
		}

		ans -= get(v);
		adj[v].clear();

		cout << ans << "\n";
	}
}