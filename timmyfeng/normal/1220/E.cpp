#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
const int MX = 2e5 + 1;

vector<int> adj[MX];
long long best;
long long ans;
int col[MX];
int a[MX];

long long dfs(int u, int p) {
	col[u] = 1;
	long long res = 0;
	for (auto c : adj[u]) {
		if (c != p) {
			if (col[c] == 1) {
				res = INF;
			} else if (!col[c]) {
				long long chd = dfs(c, u);
				res = max(res, chd);
			}
		}
	}

	if (res != INF) {
		res += a[u];
		best = max(best, res);
	} else {
		ans += a[u];
	}
	col[u] = 2;
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	while (m--) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int s;
	cin >> s;
	dfs(s, 0);

	ans += best;
	cout << ans << "\n";
}