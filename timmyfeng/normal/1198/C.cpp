#include <bits/stdc++.h>
using namespace std;

const int MX = 3e5 + 1;

vector<pair<int, int>> adj[MX];
vector<int> matching;
vector<int> ind_set;
bool vstd[MX];
bool heavy[MX];

void dfs(int u) {
	int cnt = 0;
	vstd[u] = true;
	for (auto [v, i] : adj[u]) {
		if (!vstd[v]) {
			if (!cnt && !heavy[u]) {
				heavy[v] = true;
				matching.push_back(i);
			}
			++cnt;
			dfs(v);
		}
	}

	if (!cnt) {
		ind_set.push_back(u);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		ind_set.clear();
		matching.clear();
		fill(vstd, vstd + 3 * n + 1, false);
		fill(heavy, heavy + 3 * n + 1, false);
		fill(adj, adj + 3 * n + 1, vector<pair<int, int>>());

		for (int i = 1; i <= m; ++i) {
			int u, v;
			cin >> u >> v;
			adj[u].emplace_back(v, i);
			adj[v].emplace_back(u, i);
		}

		for (int i = 1; i <= 3 * n; ++i) {
			if (!vstd[i]) {
				dfs(i);
			}
		}

		if (int(ind_set.size()) >= n) {
			cout << "IndSet\n";
			for (int i = 0; i < n; ++i) {
				cout << ind_set[i] << " ";
			}
		} else {
			cout << "Matching\n";
			for (int i = 0; i < n; ++i) {
				cout << matching[i] << " ";
			}
		}
		cout << "\n";
	}
}