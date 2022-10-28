#include <bits/stdc++.h> 
using namespace std;

bool vstd[1000000];

void dfs(int u, const vector<vector<int>>& adj) {
	vstd[u] = true;
	for (auto v : adj[u]) {
		if (!vstd[v]) {
			dfs(v, adj);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(n);
	vector<vector<int>> jda(n);
	while (m--) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		if (u != v) {
			adj[u].push_back(v);
			jda[v].push_back(u);
		}
	}

	fill(vstd, vstd + n, false);
	dfs(0, adj);

	if (count(vstd, vstd + n, true) == n) {
		fill(vstd, vstd + n, false);
		dfs(0, jda);
		for (int i = 0; i < n; ++i) {
			vstd[i] ^= true;
		}
	}

	int cnt = count(vstd, vstd + n, true);
	if (!cnt || cnt == n) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		cout << cnt << " " << n - cnt << "\n";

		for (int i = 0; i < n; ++i) {
			if (vstd[i]) {
				cout << i + 1 << " ";
			}
		}
		cout << "\n";

		for (int i = 0; i < n; ++i) {
			if (!vstd[i]) {
				cout << i + 1 << " ";
			}
		}
		cout << "\n";
	}
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