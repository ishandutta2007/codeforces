#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int M = (119 << 23) + 1;
const int MX = 3e5;

vector<int> adj[MX + 1];
ll dp0[MX + 1], dp1[MX + 1], dpx[MX + 1];

void dfs(int u, int p) {
	dp0[u] = dp1[u] = dpx[u] = 1;
	for (auto c : adj[u]) {
		if (c == p) continue;
		dfs(c, u);
		dp0[u] = dp0[u] * (2 * dp0[c] + 2 * dp1[c] - dpx[c] + M) % M;
		dp1[u] = dp1[u] * (2 * dp0[c] + dp1[c] - dpx[c] + M) % M;
		dpx[u] = dpx[u] * (dp0[c] + dp1[c] - dpx[c] + M) % M;
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
	dfs(1, 0);
	cout << (dp1[1] + dp0[1] - dpx[1] - 1 + 2 * M) % M << '\n';
}