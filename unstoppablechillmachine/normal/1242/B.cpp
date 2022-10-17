#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

const int N = 1e5 + 10;
vector<int> g[N];

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i = 1; i <= n; i++) {
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
	}
	unordered_set<int> all_ones;
	for (int i = 2; i <= n; i++) {
		all_ones.insert(i);
	}
	set<pair<int, int>> st;
	st.insert({0, 1});
	for (int i = 2; i <= n; i++) {
		st.insert({1, i});
	}
	int ans = 0;
	vector<int> kek;
	while (!st.empty()) {
		int v = st.begin()->S;
		ans += st.begin()->F;
		st.erase(st.begin());
		if (all_ones.find(v) != all_ones.end()) {
			all_ones.erase(v);
		}
		kek = {};
		for (auto it : all_ones) {
			if (find(all(g[v]), it) == g[v].end()) {
				kek.pb(it);
			}
		}
		for (auto it : kek) {
			all_ones.erase(it);
			if (st.find(make_pair(1, it)) != st.end()) {
				st.erase({1, it});
				st.insert({0, it});
			}
		}
	}
	cout << ans << '\n';
}