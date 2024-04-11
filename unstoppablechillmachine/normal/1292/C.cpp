#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int N = 3010;
int calc[N][N], sub[N];
short pr[N][N], dst[N][N];
ll dp[N][N];
vector<pair<int, int>> kek[N];
vector<int> g[N], have;

void dfs(int root, int v, int curh) {
	have.pb(v);
	dst[root][v] = curh;
	sub[v] = 1;
	for (auto u : g[v]) {
		if (u != pr[root][v]) {
			pr[root][u] = v;
			dfs(root, u, curh + 1);
			sub[v] += sub[u];
		}
	}
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int v = 1; v <= n; v++) {
		for (auto u : g[v]) {
			have = {};
			pr[v][u] = v;
			dfs(v, u, 1);
			for (auto it : have) {
				calc[v][it] = sub[it] * (n - sub[u]); 
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = -1e12;
			kek[dst[i][j]].pb({i, j}); 
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto j : g[i]) {
			dp[i][j] = calc[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (auto it : kek[i]) {
			int u = it.F, v = it.S;
			for (auto k : g[v]) {
				if (pr[u][v] != k) {
					dp[u][k] = max(dp[u][k], dp[u][v] + calc[u][k]);
				}
			}
			for (auto k : g[u]) {
				if (pr[v][u] != k) {
					dp[k][v] = max(dp[k][v], dp[u][v] + calc[k][v]);
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(ans, dp[i][j]);
			//cout << i << ' ' << j << ' ' << dp[i][j] << '\n';
		}
	}
	cout << ans << '\n';
}