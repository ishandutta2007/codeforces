#include <bits/stdc++.h>
using namespace std;

const int MX = 1e5;

int dp0[MX + 1], dp1[MX + 1];
vector<int> adj[MX + 1];
int ans = 0;

void dfs(int u, int p) {
	vector<int> chd1, chd0;
	for (auto c : adj[u]) {
		if (c == p) continue;
		dfs(c, u);
		chd0.push_back(max(dp0[c], dp1[c]));
		chd1.push_back(dp1[c]);
	}
	int cnt = chd0.size();
	sort(chd0.begin(), chd0.end(), greater<int>());
	sort(chd1.begin(), chd1.end(), greater<int>());

	if (cnt) {
		dp0[u] = chd1[0] + 1;
		dp1[u] = chd0[0] + cnt - 1;
		ans = max(ans, max(dp0[u], dp1[u]));
		if (cnt > 1) {
			ans = max(ans, 1 + chd1[0] + chd1[1]);
			ans = max(ans, chd0[0] + chd0[1] + cnt - 2 + !!p);
		}
	} else {
		dp1[u] = 0;
		dp0[u] = 1;
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
	cout << ans << '\n';
}