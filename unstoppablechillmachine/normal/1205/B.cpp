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

const int T = 61;

signed main() {
	assert((1ll << 61) > 1e18);
	int n;
	cin >> n;
	vector<vector<int>> have(T);
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 0; j < T; j++) {
			if ((x >> j) & 1) {
				have[j].pb(i);
				if (SZ(have[j]) == 3) {
					cout << 3 << '\n';
					exit(0);
				}
			}
		}
	}
	vector<int> srt;
	for (int j = 0; j < T; j++) {
		if (SZ(have[j]) == 2) {
			srt.pb(have[j][0]);
			srt.pb(have[j][1]);
		}
	}
	sort(all(srt));
	srt.resize(unique(all(srt)) - srt.begin());
	n = SZ(srt);
	unordered_map<int, int> to;
	for (int i = 0; i < SZ(srt); i++) {
		to[srt[i]] = i + 1;
	}
	vector<vector<int>> g(n + 1);
	for (int j = 0; j < T; j++) {
		if (SZ(have[j]) == 2) {
			int u = to[have[j][0]], v = to[have[j][1]];
			g[u].pb(v);
			g[v].pb(u);
		}
	}
	for (int i = 1; i <= n; i++) {
		sort(all(g[i]));
		g[i].resize(unique(all(g[i])) - g[i].begin());
		/*for (int j : g[i]) {
			cout << i << ' ' << j << '\n';
		}*/
	}
	int ans = 1e9 + 10;
	for (int v = 1; v <= n; v++) {
		for (int u : g[v]) {
			vector<int> dist(n + 1, 1e9 + 10);
			dist[v] = 0;
			queue<int> q;
			q.push(v);
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (int to : g[cur]) {
					if (cur == v && to == u) {
						continue;
					}
					if (dist[to] == 1e9 + 10) {
						dist[to] = dist[cur] + 1;
						q.push(to);
					}
				}
			}
			ans = min(ans, dist[u] + 1);
		}
	}
	if (ans == 1e9 + 10) {
		cout << -1 << '\n';
	}
	else {
		cout << ans << '\n';
	}
	//cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}