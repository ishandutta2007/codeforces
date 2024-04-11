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
vector<int> g[N];
int cc[N], a[N];
bool used[N];

int calc(int v) {
	used[v] = 1;
	int res = a[v];
	for (auto u : g[v]) {
		if (!used[u]) {
			res += calc(u);
		}
	}
	return res;
}

vector<int> ans;
int ok[N];
void dfs(int v, int p = 0) {
	used[v] = 1;
	ans.pb(v);
	ok[v] ^= 1;
	for (auto u : g[v]) {
		if (!used[u]) {
			dfs(u, v);
			ans.pb(v);
			ok[v] ^= 1;
		}
	}
	if (ok[v] != a[v]) {
		if (p == 0) {
			ans.erase(ans.begin());
		}
		else {
			ans.pb(p);
			ok[p] ^= 1;
			ans.pb(v);
		}
	}
}

signed main() {
	int n, m;
	cin >> n >> m;
	for	(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!used[i]) {
			cc[i] = calc(i);
			if (cc[i]) {
				cnt++;
				if (cnt > 1) {
					cout << -1 << '\n';
					exit(0);
				}
			}
		}
	}
	if (!cnt) {
		cout << 0 << '\n';
		exit(0);
	}
	for (int i = 1; i <= n; i++) {
		used[i] = false;
	}
	for (int i = 1; i <= n; i++) {
		if (cc[i]) {
			dfs(i);
			cout << SZ(ans) << '\n';
			for (auto it : ans) {
				cout << it << ' ';
			}
			exit(0);
		}
	}
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}