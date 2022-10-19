#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m;
	cin >> n >> m;
	map<int, vector<int>> hh;
	vector<int> h;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> b >> a;
		if (a == n && b == n) {
			cout << -1;
			exit(0);
		}
		h.pb(a);
		if (a < n) {
			h.pb(a + 1);
		}
		if (a > 1) {
			h.pb(a - 1);
		}
		hh[a].pb(b);
	}
	h.pb(1);
	h.pb(n);
	sort(all(h));
	h.resize(unique(all(h)) - h.begin());
	int cnt = 0;
	map<pair<int, int>, int> to, close;
	map<int, vector<int>> open;
	for (int i : h) {
		hh[i].pb(0);
		sort(all(hh[i]));
		hh[i].resize(unique(all(hh[i])) - hh[i].begin());
		for (int j = 0; j < SZ(hh[i]); j++) {
			bool ok = true;
			if (j + 1 < SZ(hh[i]) && hh[i][j + 1] == hh[i][j] + 1) {
				ok = false;
			}
			if (hh[i][j] == n) {
				ok = false;
			}
			if (ok) {
				open[i].pb(hh[i][j] + 1);
				if (j + 1 == SZ(hh[i])) {
					close[{i, hh[i][j] + 1}] = n;
				}
				else {
					close[{i, hh[i][j] + 1}] = hh[i][j + 1] - 1;
				}
			}
		}
		for (int j : open[i]) {
			to[{i, j}] = ++cnt;
		}
	}
	vector<vector<int>> g(cnt + 1);
	map<pair<int, int>, int> lowest_hui;
	lowest_hui[{1, 1}] = 1; 
	for (int i = 0; i + 1 < SZ(h); i++) {
		int vl = h[i];
		for (int cur : open[vl]) {
			if (lowest_hui.find({vl, cur}) == lowest_hui.end()) {
				continue;
			}
			int cr = lowest_hui[{vl, cur}];
			int ind = lower_bound(all(open[h[i + 1]]), cr) - open[h[i + 1]].begin();
			if (ind > 0 && close[{h[i + 1], open[h[i + 1]][ind - 1]}] >= cr) {
				ind--;
			}
			while (ind < SZ(open[h[i + 1]]) && open[h[i + 1]][ind] <= close[{vl, cur}]) {
				g[to[{vl, cur}]].pb(to[{h[i + 1], open[h[i + 1]][ind]}]);
				if (lowest_hui.find({h[i + 1], open[h[i + 1]][ind]}) == lowest_hui.end()) {
					lowest_hui[{h[i + 1], open[h[i + 1]][ind]}] = max(cr, open[h[i + 1]][ind]);
				}
				else {
					lowest_hui[{h[i + 1], open[h[i + 1]][ind]}] = min(lowest_hui[{h[i + 1], open[h[i + 1]][ind]}], max(cr, open[h[i + 1]][ind]));
				}
				ind++;
			}
		}
	}
	vector<bool> used(cnt + 1);
	queue<int> q;
	q.push(1);
	used[1] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto u : g[v]) {
			if (!used[u]) {
				q.push(u);
				used[u] = true;
			}
		}
	}
	if (used[cnt]) {
		cout << 2 * (n - 1) << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}