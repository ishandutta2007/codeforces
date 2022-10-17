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
const int MOD = 1e9 + 7;
vector<int> g[N];
vector<pair<ll, ll>> kek[N];
int a[N], ans;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return (a * 1ll * b) % MOD;
}

void dfs(int v, int par = 0) {
	for (auto x : kek[par]) {
		int to = __gcd(x.F, a[v]);
		if (!kek[v].empty() && to == kek[v].back().F) {
			kek[v].back().S += x.S; 
		}
		else {
			kek[v].pb({to, x.S});
		}
	}
	if (!kek[v].empty() && kek[v].back().F == a[v]) {
		kek[v].back().S++;
	}
	else {
		kek[v].pb({a[v], 1});
	}
	for (auto it : kek[v]) {
		add(ans, mult(it.F, it.S));
	}
	for (auto u : g[v]) {
		if (u != par) {
			dfs(u, v);
		}
	}
}

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
 	cin >> n;
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
 	cout << ans << '\n';
}