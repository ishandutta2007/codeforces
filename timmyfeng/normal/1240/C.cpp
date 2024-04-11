#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

vector<pair<int, int>> adj[500000];
int k;

pair<ll, ll> dfs(int u, int p) {
	pair<ll, ll> res;
	vector<ll> neighbors;
	for (auto [c, w] : adj[u]) {
		if (c != p) {
			auto chd = dfs(c, u);
			neighbors.push_back(chd.second + w - chd.first);
			res.first += chd.first;
		}
	}
	neighbors.push_back(0);
	sort(neighbors.rbegin(), neighbors.rend());

	res.second = res.first;
	for (int i = 0; i < k && neighbors[i] > 0; ++i) {
		if (i < k - 1) {
			res.second += neighbors[i];
		}
		res.first += neighbors[i];
	}
	return res;
}

void solve() {
	int n;
	cin >> n >> k;
	fill(adj, adj + n, vector<pair<int, int>>());
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		cin >> u >> v >> w;
		--u, --v;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}
	cout << dfs(0, -1).first << "\n";
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