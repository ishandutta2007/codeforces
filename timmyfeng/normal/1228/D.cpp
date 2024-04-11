#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;

vector<int> adj[MX + 1];
bitset<MX + 1> ct;
int ans[MX + 1];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int cur = 0;
	for (int i = 1; i <= n; ++i) {
		if (!ans[i]) {
			if (cur == 3) {
				cout << -1 << '\n';
				return 0;
			}
			++cur;
			ct.reset();
			for (auto j : adj[i]) {
				ct[j] = true;
			}
			for (int j = 1; j <= n; ++j) {
				if (!ct[j]) {
					if (adj[j].size() != adj[i].size() || ans[j]) {
						cout << -1 << '\n';
						return 0;
					}
					ans[j] = cur;
				}
			}
			for (int j = 1; j <= n; ++j) {
				if (ans[j] != cur) continue;
				for (auto k : adj[j]) {
					if (ans[k] == cur) {
						cout << -1 << '\n';
						return 0;
					}
				}
			}
		}
	}
	if (cur < 3) {
		cout << -1 << '\n';
		return 0;
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}