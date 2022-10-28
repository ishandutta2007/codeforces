#include <bits/stdc++.h>
using namespace std;

const int MX = 250;
const int INF = 2e9;

struct edge {
	int u, v, cap;
};

vector<int> adj[MX];
vector<edge> edges;
int ptr[MX];
int lvl[MX];
int sink;
int src;

int x_end[MX];
int x_start[MX];
int y_end[MX];
int y_start[MX];

void compress(vector<int>& a) {
	sort(a.begin(), a.end());
	a.resize(unique(a.begin(), a.end()) - a.begin());
}

void add_edge(int u, int v, int cap) {
	adj[u].push_back(edges.size());
	edges.push_back({u, v, cap});
	adj[v].push_back(edges.size());
	edges.push_back({v, u, 0});
}

int dfs(int u, int cnt) {
	if (!cnt)
		return 0;
	if (u == sink)
		return cnt;
	for ( ; ptr[u] < int(adj[u].size()); ++ptr[u]) {
		int i = adj[u][ptr[u]];
		if (lvl[edges[i].v] == lvl[u] + 1 && edges[i].cap) {
			int res = dfs(edges[i].v, min(cnt, edges[i].cap));
			if (res) {
				edges[i].cap -= res;
				edges[i ^ 1].cap += res;
				return res;
			}
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	if (!m) {
		cout << 0 << "\n";
		return 0;
	}

	vector<int> all_x;
	vector<int> all_y;
	for (int i = 0; i < m; ++i) {
		cin >> x_start[i] >> y_start[i] >> x_end[i] >> y_end[i];
		++x_end[i], ++y_end[i];
		all_x.push_back(x_start[i]);
		all_x.push_back(x_end[i]);
		all_y.push_back(y_start[i]);
		all_y.push_back(y_end[i]);
	}

	compress(all_x);
	compress(all_y);

	int cnt_x = all_x.size() - 1u;
	int cnt_y = all_y.size() - 1u;

	src = cnt_x + cnt_y;
	sink = src + 1;

	for (int i = 0; i < cnt_x; ++i) {
		add_edge(src, i, all_x[i + 1] - all_x[i]);
	}

	for (int i = 0; i < cnt_y; ++i) {
		add_edge(cnt_x + i, sink, all_y[i + 1] - all_y[i]);
	}

	for (int i = 0; i < cnt_x; ++i) {
		for (int j = 0; j < cnt_y; ++j) {
			bool colored = false;
			for (int k = 0; k < m; ++k) {
				colored |=
						(all_x[i] >= x_start[k] &&
						all_x[i] < x_end[k] &&
						all_y[j] >= y_start[k] &&
						all_y[j] < y_end[k]);
			}
			if (colored) {
				add_edge(i, cnt_x + j, INF);
			}
		}
	}

	int ans = 0;
	while (true) {
		memset(lvl, -1, sizeof lvl);
		queue<int> que;
		que.push(src);
		lvl[src] = 0;

		while (!que.empty()) {
			int u = que.front();
			que.pop();
			for (auto i : adj[u]) {
				if (!edges[i].cap || lvl[edges[i].v] != -1) {
					continue;
				}
				lvl[edges[i].v] = lvl[u] + 1;
				que.push(edges[i].v);
			}
		}

		if (lvl[sink] == -1)
			break;

		memset(ptr, 0, sizeof ptr);
		int cnt = -1;

		while (cnt) {
			cnt = dfs(src, INF);
			ans += cnt;
		}
	}
	cout << ans << "\n";
}