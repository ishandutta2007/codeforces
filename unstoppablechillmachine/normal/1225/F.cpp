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

const int N = 1e5 + 10;
set<int> g[N];
vector<int> ans;
int p[N], nxt[N];
 
pair<int, int> dfs(int v, int par = 0) {
	p[v] = par;
	pair<int, int> res = {0, v};
	for (auto u : g[v]) {
		if (u != par) {
			pair<int, int> vl = dfs(u, v);
			res = max(res, make_pair(vl.F + 1, vl.S));
		}
	}
	return res;
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
 	int n;
 	cin >> n;
 	for (int i = 1; i < n; i++) {
 		int p;
 		cin >> p;
 		g[p].insert(i);
 	} 
 	int curV = dfs(0).S;
 	while (curV) {
 		g[p[curV]].erase(curV);
 		if (g[p[curV]].empty()) {
 			curV = p[curV];
 			continue;
 		}
 		ans.pb(curV);
 		p[curV] = *g[p[curV]].begin();
 	}
 	for (int i = 1; i < n; i++) {
 		nxt[p[i]] = i;
 	}
 	int v = 0;
 	for (int i = 0; i < n; i++) {
 		cout << v << ' ';
 		v = nxt[v];
 	}
 	cout << '\n' << SZ(ans) << '\n';
 	reverse(all(ans));
 	for (auto it : ans) {
 		cout << it << ' ';
 	}
 	cout << '\n';
}