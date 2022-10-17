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
 
const int N = 2e5 + 10;
vector<int> best[4][N];
int dp1[N], dp2[N], dp3[N];
vector<int> g[N];
void dfs(int v, int p = 0) {
	best[1][v] = best[2][v] = best[3][v] = {v};
	vector<pair<int, int>> srt1, srt2;
	for (auto u : g[v]) {
		if (u != p) {
			dfs(u, v);
			if (dp1[u] + 1 > dp1[v]) {
				dp1[v] = dp1[u] + 1;
				best[1][v] = best[1][u];
			}
			if (dp2[u] + 1 > dp2[v]) {
				dp2[v] = dp2[u] + 1;
				best[2][v] = best[2][u];
			}
			if (dp3[u] > dp3[v]) {
				dp3[v] = dp3[u];
				best[3][v] = best[3][u];
			}
			srt1.pb({dp1[u], u});
			srt2.pb({dp2[u], u});
		}
	}
	sort(srt1.rbegin(), srt1.rend());
	sort(srt2.rbegin(), srt2.rend());
	if (SZ(srt1) > 1) {
		if (srt1[0].F + srt1[1].F + 2 > dp2[v]) {
			dp2[v] = srt1[0].F + srt1[1].F + 2;
			best[2][v] = {};
			best[2][v].pb(best[1][srt1[0].S][0]);
			best[2][v].pb(best[1][srt1[1].S][0]);
		}
	}
	if (SZ(srt1) > 2) {
		if (srt1[0].F + srt1[1].F + srt1[2].F + 3 > dp3[v]) {
			dp3[v] = srt1[0].F + srt1[1].F + srt1[2].F + 3;
			best[3][v] = {};
			best[3][v].pb(best[1][srt1[0].S][0]);
			best[3][v].pb(best[1][srt1[1].S][0]);
			best[3][v].pb(best[1][srt1[2].S][0]);		
		}
	}
	for (int i = 0; i < min(2, SZ(srt1)); i++) {
		for (auto it : srt2) {
			if (it.S != srt1[i].S) {
				if (srt1[i].F + it.F + 2 > dp3[v]) {
					dp3[v] = srt1[i].F + it.F + 2;
					best[3][v] = {};
					best[3][v].pb(best[1][srt1[i].S][0]);
					best[3][v].pb(best[2][it.S][0]);
					best[3][v].pb(best[2][it.S][1]); 
				}
			}
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
	vector<int> l;
	for (int i = 1; i <= n; i++) {
		if (SZ(g[i]) == 1) {
			l.pb(i);
		}
	}
	if (SZ(l) < 3) {
		for (int i = 1; i <= n; i++) {
			if (SZ(l) < 3 && find(all(l), i) == l.end()) {
				l.pb(i);
			}
		}
		cout << n - 1 << '\n';
		for (auto it : l) {
			cout << it << ' ';
		}
		cout << '\n';
		exit(0);
	}
	int root = -1;
	for (int i = 1; i <= n; i++) {
		if (SZ(g[i]) > 1) {
			root = i;
			break;
		}
	}
	assert(root != -1);
	dfs(root);
	cout << dp3[root] << '\n';
	for (auto it : best[3][root]) {
		cout << it << ' ';
	}
	cout << '\n';
}