#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

ull ans;
const int N = 1e5 + 10;
vector<int> g[N], order;
int vert[N], down[N], up[N];

void dfs(int v, int par = 0) {
	vert[v] = 1;
	for (auto u : g[v]) {
		if (u != par) {
			dfs(u, v);
			down[v] += vert[v] * vert[u];
			vert[v] += vert[u];
		}
	}
	order.pb(v);
}

signed main() {
	int n;
	cin >> n;
	ans = ((ull)n * (ull)(n - 1)) / 2;
	ans *= ans;
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	reverse(all(order));
	for (auto i : order) {
		ans -= (ull)down[i] * (ull)down[i];
		ans -= (ull)2 * (ull)down[i] * (ull)up[i] * (ull)vert[i];
		for (auto u : g[i]) {
			up[u] = up[i] + vert[i] - vert[u];
		}
	}
	cout << ans << '\n';
}