#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int N = 1e5 + 10;
const int LOG = 18;
vector<int> g[N];
int up[LOG][N], tin[N], tout[N], timer;

void dfs(int v, int p = 0) {
	up[0][v] = p ? p : v;
	tin[v] = ++timer;
	for (auto u : g[v]) {
		if (u != p) {
			dfs(u, v);
		}
	}
	tout[v] = ++timer;
}

bool anc(int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
	if (anc(a, b)) {
		return a;
	}
	if (anc(b, a)) {
		return b;
	}
	for (int i = LOG - 1; i >= 0; i--) {
		if (!anc(up[i][a], b)) {
			a = up[i][a];
		}
	}
	return up[0][a];
}

signed main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (auto &it : p) {
		cin >> it.F >> it.S;
	}	
	vector<int> ch;
	ch.pb(n - 1);
	if (n > 1) {
		ch.pb(n - 2);
		g[n].pb(n - 1);
	}
	for (int i = n - 3; i >= 0; i--) {
		while (SZ(ch) > 1) {
			int id1 = ch.back(), id2 = ch[SZ(ch) - 2];
			pair<int, int> p1 = {p[id1].F - p[i].F, p[id1].S - p[i].S}, 
			p2 = {p[id2].F - p[i].F, p[id2].S - p[i].S};
			if (p2.F * p1.S - p2.S * p1.F < 0) {
				ch.pop_back();
			}
			else {
				break;
			}
		}
		g[ch.back() + 1].pb(i + 1);
		ch.pb(i);
		//cout << ch.back() + 1 << ' ' << i + 1 << '\n';
	}
	//cout << '\n';
	dfs(n);
	for (int i = 1; i < LOG; i++) {
		for (int j = 1; j <= n; j++) {
			up[i][j] = up[i - 1][up[i - 1][j]];
		}
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << ' ';
	}
	cout << '\n';
	//cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}