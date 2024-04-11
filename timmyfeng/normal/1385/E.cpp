#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

vector<int> adj[N];
int time_out[N];
int color[N];
int timer;

bool dfs(int u) {
	color[u] = 1;
	bool ok = true;
	for (auto v : adj[u]) {
		if (color[v] == 1) {
			ok = false;
		} else if (color[v] == 0) {
			ok &= dfs(v);
		}
	}
	time_out[u] = ++timer;
	color[u] = 2;
	return ok;
}

void solve() {
	int n, m;
	cin >> n >> m;

	fill(adj, adj + n + 1, vector<int>());
	fill(color, color + n + 1, 0);
	vector<pair<int, int>> edges;
	timer = 0;

	while (m--) {
		int type, u, v;
		cin >> type >> u >> v;
		if (type == 1) {
			adj[u].push_back(v);
		}
		edges.emplace_back(u, v);
	}

	bool ok = true;
	for (int i = 1; i <= n; ++i) {
		if (color[i] == 0) {
			ok &= dfs(i);
		}
	}

	if (ok) {
		cout << "YES\n";
		for (auto [u, v] : edges) {
			if (time_out[u] < time_out[v]) {
				swap(u, v);
			}
			cout << u << " " << v << "\n";
		}
	} else {
		cout << "NO\n";
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