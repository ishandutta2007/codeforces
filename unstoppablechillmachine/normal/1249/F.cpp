#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 310;
vector<int> g[N];
int dp[N][N], dp2[N], a[N];
int k;

void dfs(int v, int par = 0) {
	dp[v][0] = a[v];
	for (auto u : g[v]) {
		if (u != par) {
			dfs(u, v);
			dp[v][0] += dp[u][k - 1];
		}
	}
	for (int i = 1; i <= k; i++) {
		for (auto u : g[v]) {
			if (u != par) {
				int sum = 0;
				for (auto u2 : g[v]) {
					if (u2 == par) {
						continue;
					}
					if (u == u2) {
						sum += dp[u2][i - 1];
					}
					else {
						sum += dp[u2][max(i - 1, k - i - 1)];
					}
				}
				dp[v][i] = max(dp[v][i], sum);
			}
		}
	}
	for (int i = k - 1; i >= 0; i--) {
		dp[v][i] = max(dp[v][i], dp[v][i + 1]);
	}
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
	int n;
	cin >> n >> k;
	k++;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	} 	
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	cout << dp[1][0] << '\n';	
}