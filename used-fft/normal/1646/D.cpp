#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define sz(X) int(X.size())

const int Z = 2e5+1;

int n;
array<int, 2> dp[Z][2];
vector<int> g[Z];

void dfs(int u, int p) {

	dp[u][1] = {1, 1-sz(g[u])};
	for(int v : g[u]) if(v != p) {
		dfs(v, u);

		dp[u][1][0] += dp[v][0][0];
		dp[u][1][1] += dp[v][0][1];

		auto x = max(dp[v][0], dp[v][1]);
		dp[u][0][0] += x[0];
		dp[u][0][1] += x[1];
	}
}

bool take[Z];

void build(int u, int p, bool t) {
	take[u] = t;

	for(int v : g[u]) if(v != p) {
		if(t) {
			build(v, u, 0);
		} else {
			build(v, u, dp[v][1] > dp[v][0]);
		}
	}
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v;
		--u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}


	if(n == 2) {
		cout << "2 2\n1 1";
	} else {
		dfs(0, 0);

		auto x = max(dp[0][0], dp[0][1]);
		cout << x[0] << ' ' << n-x[1] << '\n';

		build(0, 0, x == dp[0][1]);

		for(int i = 0; i < n; ++i) {
			cout << (take[i] ? sz(g[i]) : 1) << ' ';
		}
	}
}