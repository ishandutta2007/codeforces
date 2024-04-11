#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int MX = 3e5 + 1;

vector<pair<int, int>> req[MX];
ll ans[MX], cur[MX], delta;
vector<int> adj[MX];
int dep;

void dfs(int u, int p) {
	for (auto [d, x] : req[u]) {
		cur[min(MX, d + dep)] += x;
		delta += x;
	}
	ans[u] = delta;

	for (auto c : adj[u]) {
		if (c == p)
			continue;
		delta -= cur[dep];
		++dep;
		dfs(c, u);
		--dep;
		delta += cur[dep];
	}

	for (auto [d, x] : req[u]) {
		cur[min(MX, d + dep)] -= x;
		delta -= x;
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
	int m;
	cin >> m;
	while (m--) {
		int v, d, x;
		cin >> v >> d >> x;
		req[v].emplace_back(d, x);
	}

	dfs(1, 0);

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}