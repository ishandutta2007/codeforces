#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n;
vector<vector<int>> d;
vector<vector<pair<int, int>>> g;

void dijkstra(int s, vector<int> &d) {
	d = vector<int>(n, INF);
	d[s] = 0;
	set<pair<int, int>> st;
	st.insert({d[s], s});
	while (!st.empty()) {
		int v = st.begin()->second;
		st.erase(st.begin());
		for (auto [to, w] : g[v]) {
			if (d[to] > d[v] + w) {
				auto it = st.find({d[to], to});
				if (it != st.end()) st.erase(it);
				d[to] = d[v] + w;
				st.insert({d[to], to});
			}
		}
	}
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
	
	int m, k;
	cin >> n >> m >> k;
	g = vector<vector<pair<int, int>>>(n);
	for (int i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;
		--x, --y;
		g[x].push_back({y, w});
		g[y].push_back({x, w});
	}
	
	vector<pair<int, int>> r(k);
	for (auto &[a, b] : r) {
		cin >> a >> b;
		--a, --b;
	}
	
	d = vector<vector<int>>(n);
	for (int v = 0; v < n; ++v) {
		dijkstra(v, d[v]);
	}
	
	int ans = INF;
	for (int v = 0; v < n; ++v) {
		for (auto [to, w] : g[v]) {
			int cur = 0;
			for (auto [a, b] : r) {
				cur += min({d[a][b], d[a][v] + d[to][b], d[a][to] + d[v][b]});
			}
			ans = min(ans, cur);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}