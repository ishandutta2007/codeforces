#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;

vector<int> adj[MX + 1];
vector<pair<int, int>> ans;
int mx = 0;

void dfs(int u, int p, int val) {
	if (p) {
		adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
	}

	int cur = val, chd = adj[u].size();
	ans.emplace_back(u, cur);
	for (int i = 0; i < chd; ++i) {
		if (++cur == mx) {
			cur = val - chd + i;
			ans.emplace_back(u, cur - 1);
		}
		dfs(adj[u][i], u, cur);
		ans.emplace_back(u, cur);
	}

	if (cur != val - 1) {
		ans.emplace_back(u, val - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; ++i) {
		mx = max(mx, (int)adj[i].size() + 1);
	}

	dfs(1, 0, 0);
	ans.pop_back();
	cout << ans.size() << '\n';
	for (auto [a, b] : ans) {
		cout << a << ' ' << b << '\n';
	}
}