#include <bits/stdc++.h> 
using namespace std;

const int MX = 5e5 + 1;

int a, b;
bool vstd[MX];
vector<int> adj[MX];

tuple<int, bool, bool> dfs(int u) {
	int cnt = 1;
	bool vstd_a = false;
	bool vstd_b = false;
	vstd[u] = true;
	for (auto v : adj[u]) {
		if (v == a) {
			vstd_a = true;
		} else if (v == b) {
			vstd_b = true;
		} else if (!vstd[v]) {
			auto [chd_cnt, chd_a, chd_b] = dfs(v);
			cnt += chd_cnt;
			vstd_a |= chd_a;
			vstd_b |= chd_b;
		}
	}
	return make_tuple(cnt, vstd_a, vstd_b);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m >> a >> b;

		fill(adj + 1, adj+ n + 1, vector<int>());
		while (m--) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int cnt_a = 0;
		int cnt_b = 0;
		fill(vstd + 1, vstd + n + 1, false);
		for (int i = 1; i <= n; ++i) {
			if (!vstd[i] && i != a && i != b) {
				auto [cnt, vstd_a, vstd_b] = dfs(i);
				if (vstd_a ^ vstd_b) {
					if (vstd_a) {
						cnt_a += cnt;
					} else {
						cnt_b += cnt; 
					}
				}
			}
		}

		cout << 1LL * cnt_a * cnt_b << "\n";
	}
}