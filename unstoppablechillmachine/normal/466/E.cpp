#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second
const int MOD = 1e9 + 7;

const int N = 1e5 + 10;
const int LOG = 18;
vector<int> g[N];
int up[N][LOG], mx[N][LOG], tin[N], tout[N], h[N], timer;

void dfs(int v, int curh = 0) {
	tin[v] = ++timer;
	h[v] = curh;
	for (auto u : g[v]) {
		dfs(u, curh + 1);
	}
	tout[v] = ++timer;
}

bool ancestor(int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int get(int u, int v) {
	int vl = h[v] - h[u], res = -1;
	for (int i = 0; i < LOG; i++) {
		if ((vl >> i) & 1) {
			res = max(res, mx[v][i]);
			v = up[v][i];
		}
	}
	return res;
}

signed main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> arr, q;
	for (int i = 0; i < m; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int u, v;
			cin >> u >> v;
			swap(u, v);
			g[u].pb(v);
			up[v][0] = u;
			mx[v][0] = i;
		}
		else if (type == 2) {
			int v;
			cin >> v;
			arr.pb({v, i});
		}
		else {
			int u, num;
			cin >> u >> num;
			num--;
			q.pb({u, num});
		}
	}
	for (int i = 1; i <= n; i++) {
		if (up[i][0] == 0) {
			//cout << i << '\n';	
			dfs(i);
		}
	}
	for (int i = 1; i < LOG; i++) {
		for (int j = 1; j <= n; j++) {
			up[j][i] = up[up[j][i - 1]][i - 1];
			mx[j][i] = max(mx[j][i - 1], mx[up[j][i - 1]][i - 1]);
		}
	}
	for (auto it : q) {
		if (!ancestor(it.F, arr[it.S].F)) {
			cout << "NO\n";
		}
		else {
			if (get(it.F, arr[it.S].F) <= arr[it.S].S) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
}