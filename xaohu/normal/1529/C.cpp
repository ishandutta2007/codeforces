#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = b; i >= a; i--)
#define gao(x) cerr << #x << " " << x << "\n"
#define pb push_back
#define sz(x) (int)x.size()
#define fi first
#define se second
#define ll long long
 
using namespace std;

const int N = 1 << 20;

int t, n, e[N][2];
vector<int> g[N];
ll dp[N][2];

void dfs(int v, int p) {
	dp[v][0] = dp[v][1] = 0;
	for (auto u : g[v]) {
		if (u != p) {
			dfs(u, v);
			rep(i, 0, 1)
				dp[v][i] += max(dp[u][0] + abs(e[v][i] - e[u][0]), dp[u][1] + abs(e[v][i] - e[u][1]));
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> n;
		rep(i, 1, n) cin >> e[i][0] >> e[i][1], g[i].clear();
		rep(i, 1, n - 1) {
			int a, b;
			cin >> a >> b;
			g[a].pb(b);
			g[b].pb(a);
		}
		dfs(1, 0);
		cout << max(dp[1][0], dp[1][1]) << "\n";
	}	
	return 0;
}