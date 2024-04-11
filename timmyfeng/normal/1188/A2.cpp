#include <bits/stdc++.h> 
using namespace std;

const int MX = 1000 + 1;

vector<int> adj[MX];

int leaf(int u, int p) {
	for (auto c : adj[u]) {
		if (c != p) {
			return leaf(c, u);
		}
	}
	return u;
}

vector<int> get(int u, int v) {
	vector<int> res;
	for (auto i : adj[u]) {
		if (i != v) {
			res.push_back(leaf(i, u));
		}
	}
	while (res.size() < 2u) {
		res.push_back(u);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	vector<tuple<int, int, int>> edge;
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(v);
		adj[v].push_back(u);
		edge.emplace_back(u, v, w);
	}

	for (int i = 1; i <= n; ++i) {
		if (int(adj[i].size()) == 2) {
			cout << "NO\n";
			return 0;
		}
	}


	vector<tuple<int, int, int>> ans;
	for (auto [u, v, w] : edge) {
		vector<vector<int>> leaves = {get(u, v), get(v, u)};

		for (int i = 0; i < 2; ++i) {
			ans.emplace_back(leaves[0][i], leaves[1][i], w / 2);
			if (leaves[i][0] != leaves[i][1]) {
				ans.emplace_back(leaves[i][0], leaves[i][1], -w / 2);
			}
		}
	}

	cout << "YES\n";
	cout << ans.size() << "\n";
	for (auto [u, v, w] : ans) {
		cout << u << " " << v << " " << w << '\n';
	}
}