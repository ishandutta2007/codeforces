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
 
const int N = 1e6 + 10;
vector<int> g[N], rg[N], order;
bool used[N];
int c[N];

void dfs(int v) {
	used[v] = true;
	for (auto u : g[v]) {
		if (!used[u]) {
			dfs(u);
		}
	}
	order.pb(v);
}

void dfs2(int v, int color) {
	c[v] = color;
	for (auto u : rg[v]) {
		if (!c[u]) {
			dfs2(u, color);
		}
	}
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 	int T;
 	cin >> T;
 	while (T--) {
 		int n, m;
 		cin >> n >> m;
 		for (int i = 1; i <= n; i++) {
 			g[i] = {};
 			rg[i] = {};
 			c[i] = 0;
 			used[i] = false;
 		}
 		order = {};
 		for (int i = 0; i < m; i++) {
 			int u, v;
 			cin >> u >>  v;
 			g[u].pb(v);
 			rg[v].pb(u);
 		}
 		for (int i = 1; i <= n; i++) {
 			if (!used[i]) {
 				dfs(i);
 			}
 		}
 		reverse(all(order));
 		int cnt = 0;
 		for (auto it : order) {
 			if (!c[it]) {
 				dfs2(it, ++cnt);
 			}
 		}
 		if (cnt == 1) {
 			cout << "No\n";
 		}
 		else {
 			int cats_comp = 0;
 			vector<int> kek(cnt + 1);
 			for (int i = 1; i <= n; i++) {
 				for (auto u : g[i]) {
 					if (c[i] != c[u]) {
 						kek[c[u]] = true;	
 					}
 				}
 			}
 			for (int i = 1; i <= cnt; i++) {
 				if (!kek[i]) {
 					cats_comp = i;
 					break;
 				}
 			}
 			cout << "Yes\n";
 			vector<int> ans1, ans2;
 			for (int i = 1; i <= n; i++) {
 				if (c[i] != cats_comp) {
 					ans1.pb(i);
 				}
 				else {
 					ans2.pb(i);
 				}
 			}
 			cout << SZ(ans1) << ' ' << SZ(ans2) << '\n';
 			for (auto it : ans1) {
 				cout << it << ' ';
 			}
 			cout << '\n';
 			for (auto it : ans2) {
 				cout << it << ' ';
 			}
 			cout << '\n';
 		}
 	} 
}