#include <bits/stdc++.h>
using namespace std;

const int MX = 70 + 1;
const int MX_MASK = 17;
const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[MX];
int dist[1 << MX_MASK][MX];
int color[MX];
int ans[MX];
int a;

struct dijkstra {
	int dist, mask, u;
};

bool operator<(dijkstra i, dijkstra j) {
	return make_tuple(i.dist, i.mask, i.u) > make_tuple(j.dist, j.mask, j.u);
}

int dfs(int u, int new_color) {
	int res = 1;
	color[u] = new_color;
	for (auto [v, w] : adj[u]) {
		if (w == a && color[v] != new_color) {
			res += dfs(v, new_color);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, b;
	cin >> n >> m >> a >> b;

	while (m--) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	int light_cnt = 0;
	int heavy_cnt = 0;
	memset(color, -1, sizeof color);
	for (int i = 1; i <= n; ++i) {
		if (color[i] == -1) {
			if (dfs(i, -2) > 3) {
				dfs(i, heavy_cnt);
				++heavy_cnt;
			} else {
				dfs(i, MX_MASK + light_cnt);
				++light_cnt;
			}
		}
	}

	memset(dist, INF, sizeof dist);
	memset(ans, INF, sizeof ans);
	priority_queue<dijkstra> pq;

	dijkstra init = {0, color[1] >= 17 ? 0 : 1 << color[1], 1};
	dist[init.mask][1] = 0;
	pq.push(init);

	while (!pq.empty()) {
		dijkstra state = pq.top();
		pq.pop();

		if (state.dist > dist[state.mask][state.u])
			continue;
		ans[state.u] = min(ans[state.u], state.dist);

		for (auto [v, w] : adj[state.u]) {
			int new_mask = state.mask;
			if (color[v] < MX_MASK) {
				if (w == b && (state.mask & (1 << color[v])))
					continue;
				new_mask |= 1 << color[v];
			} else {
				if (w == b && color[state.u] == color[v])
					continue;
			}

			if (state.dist + w < dist[new_mask][v]) {
				dist[new_mask][v] = state.dist + w;
				pq.push({state.dist + w, new_mask, v});
			}
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}