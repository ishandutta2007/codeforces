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

const int N = 1e6 + 10;
const int INF = 1e9 + 10;
vector<int> g[N], rg[N], gg[N], order;
pair<int, int> vl[N], f[N];
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

pair<int, int> get(string s) {
	pair<int, int> res;
	for (auto it : s) {
		if (it == 'r') {
			res.F++;
		}
	}
	res.S = SZ(s);
	return res;
}

string sm(string s) {
	string res;
	for (auto it : s) {
		if (it >= 'a' && it <= 'z') {
			res.pb(it);
		}
		else {
			res.pb(it - 'A' + 'a');
		}
	}
	return res;
}

bool was[N];

pair<int, int> calc(int v) {
	if (was[v]) {
		return vl[v];
	}
	was[v] = true;
	for (auto u : gg[v]) {
		vl[v] = min(vl[v], calc(u));
	}
	return vl[v];
}

signed main() {
	int n;
	cin >> n;
	int cnt = 0;
	vector<int> arr;
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		s = sm(s);
		//cout << s << ' ';
		if (mp.find(s) == mp.end()) {
			mp[s] = ++cnt;
			f[cnt] = get(s);
		}
		arr.pb(mp[s]);
	}	
	//cout << '\n';
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		s1 = sm(s1);
		s2 = sm(s2);
		//cout << s1 << ' ' << s2 << '\n';
		int u, v;
		if (mp.find(s1) == mp.end()) {
			mp[s1] = ++cnt;
			f[cnt] = get(s1);
		}
		if (mp.find(s2) == mp.end()) {
			mp[s2] = ++cnt;
			f[cnt] = get(s2);
		}
		u = mp[s1], v = mp[s2];
		g[u].pb(v);
		rg[v].pb(u);
	}
	for (int i = 1; i <= cnt; i++) {
		if (!used[i]) {
			dfs(i);
		}
	}
	reverse(all(order));
	int cp = 0;
	for (int v : order) {
		if (!c[v]) {
			dfs2(v, ++cp);
		}
	}
	//cout << "CP " << cp << '\n';
	for (int i = 1; i <= cp; i++) {
		vl[i] = {INF, INF};
	}
	for (int i = 1; i <= cnt; i++) {
		vl[c[i]] = min(vl[c[i]], f[i]);
		for (auto u : g[i]) {
			if (c[i] != c[u]) {
				gg[c[i]].pb(c[u]);
			}
		}
	}
	for (int i = 1; i <= cp; i++) {
		sort(all(gg[i]));
		gg[i].resize(unique(all(gg[i])) - gg[i].begin());
	}
	pair<int, int> ans;
	for (int v : arr) {
		pair<int, int> cur = calc(c[v]);
		//cout << c[v] << '\n';
		ans.F += cur.F;
		ans.S += cur.S;
	}
	cout << ans.F << ' ' << ans.S << '\n';
	cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}