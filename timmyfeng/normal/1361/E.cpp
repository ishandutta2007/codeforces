#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e5 + 1;
const int MAG = 100;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int col[MX], dp[MX], up[MX], dep[MX];
vector<int> adj[MX];
bool bad[MX];

bool dfs_tree(int u) {
	bool res = true;
	col[u] = 1;
	up[u] = u;
	for (auto c : adj[u]) {
		if (col[c] == 1) {
			++dp[u];
			--dp[c];
			if (dep[c] < dep[up[u]]) {
				up[u] = c;
			}
		} else if (col[c] == 2) {
			res = false;
		} else {
			dep[c] = dep[u] + 1;
			res &= dfs_tree(c);
			dp[u] += dp[c];
			if (dep[up[c]] < dep[up[u]]) {
				up[u] = up[c];
			}
		}
	}
	col[u] = 2;
	return res;
}

void dfs(int u) {
	col[u] = 3;
	bad[u] = (dp[u] >= 2 || bad[up[u]]);
	for (auto c : adj[u]) {
		if (col[c] != 3) {
			dfs(c);
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	fill(adj, adj + n + 1, vector<int>());
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 0; i < MAG; ++i) {
		int rt = uniform_int_distribution<int>(1, n)(rng);
		fill(bad, bad + n + 1, false);
		fill(col, col + n + 1, 0);
		fill(dp, dp + n + 1, 0);
		dep[rt] = 0;

		if (dfs_tree(rt)) {
			dfs(rt);
			vector<int> ans;
			for (int i = 1; i <= n; ++i) {
				if (!bad[i]) {
					ans.push_back(i);
				}
			}

			if ((int)ans.size() * 5 < n) {
				cout << -1 << '\n';
			} else {
				for (auto i : ans) {
					cout << i << ' ';
				}
				cout << '\n';
			}
			return;
		}
	}
	cout << -1 << '\n';
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