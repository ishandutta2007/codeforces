#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
const int MX = 2e5;

vector<int> adj[MX  +1];
int sub[MX + 1], dep[MX + 1], val[MX + 1];

void dfs(int u, int p) {
	sub[u] = 1;
	for (auto c : adj[u]) {
		if (c == p) continue;
		dep[c] = dep[u] + 1;
		dfs(c, u);
		sub[u] += sub[c];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1, 0);
	
	for (int i = 1; i <= n; ++i) {
		val[i] = dep[i] - sub[i] + 1;
	}
	sort(val + 1, val + 1 + n);

	ll ans = 0;
	for (int i = 0; i < k; ++i) {
		ans += val[n - i];
	}
	cout << ans << '\n';
}