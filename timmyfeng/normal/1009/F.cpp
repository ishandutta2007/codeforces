#include <bits/stdc++.h> 
using namespace std;

const int MX = 1e6 + 1;

pair<int, int> mx[MX];
map<int, int> mp[MX];
vector<int> adj[MX];
int ans[MX], dep;

void dfs(int u, int p) {
	mp[u][dep] = 1;
	mx[u] = {1, dep};
	for (auto c : adj[u]) {
		if (c == p)
			continue;
		++dep;
		dfs(c, u);
		--dep;

		if (mp[c].size() > mp[u].size()) {
			swap(mp[c], mp[u]);
			swap(mx[c], mx[u]);
		}
		for (auto [a, b] : mp[c]) {
			int tmp = mp[u][a] += b;
			if (tmp > mx[u].first || (tmp == mx[u].first && a < mx[u].second)) {
				mx[u] = {tmp, a};
			}
		}
		mp[c].clear();
	}
	ans[u] = mx[u].second - dep;
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
	
	dfs(1, 0);

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << '\n';
	}
}