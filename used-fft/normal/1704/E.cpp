#include <bits/stdc++.h>
using namespace std;
#define int long long

const int Z = 1000, MOD = 998244353;

vector<int> g[Z], h[Z], o;
bool vis[Z];

void dfs(int u) {
	vis[u] = 1;
	for(int v : g[u]) if(!vis[v])
		dfs(v);
	o.push_back(u);
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int T; cin >> T;
	while(T--) {
		int n, m; cin >> n >> m;

		int a[n];
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			g[i].clear();
			h[i].clear();
		}

		while(m--) {
			int u, v; cin >> u >> v;
			--u, --v;

			g[u].push_back(v);
			h[v].push_back(u);
		}


		fill(vis, vis + n, 0);
		o.clear();
		for(int u = 0; u < n; ++u) if(!vis[u])
			dfs(u);

		int dp[n] {};
		++dp[o[0]];
		assert(empty(g[o[0]]));

		for(int u : o) {
			for(int v : h[u]) {
				(dp[v] += dp[u]) %= MOD;
			}
		}

		int ans {};

		if(!*max_element(a, a + n)) {
			cout << ans << '\n';
			continue;
		}

		int b[n];
		while(ans <= n) {
			copy(a, a + n, b);

			for(int u = 0; u < n; ++u) if(b[u]) {
				for(int v : g[u]) ++a[v];
				--a[u];
			}

			++ans;


			if(!*max_element(a, a + n))
				break;
		}

		for(int i = 0; i < n; ++i) {
			ans += (dp[i] * a[i]) % MOD;
			ans %= MOD;
		}

		cout << ans << '\n';
	}
}