#include <bits/stdc++.h> 
using namespace std;

const int MXN = 51;
const int MX = 5000;

vector<tuple<int, int, int, int>> edge;
int dist[MX], pre[MX], ndx[MXN][MXN];
bool in_que[MX], block[MXN][MXN];
vector<int> adj[MX];

void add_edge(int u, int v, int w, int c) {
	adj[v].push_back(edge.size());
	edge.emplace_back(v, u, -w, 0);
	adj[u].push_back(edge.size());
	edge.emplace_back(u, v, w, c);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		block[v][u] = true;
	}

	int src = n * (n + 1) / 2 + 1;
	int sink = src + 1;

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < n; ++j) {
			add_edge(i, sink, j * 2 - 1, 1);
		}
	}

	int cur = n + 1;
	memset(ndx, -1, sizeof ndx);
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			add_edge(src, cur, 0, 1);
			if (!block[i][j]) {
				ndx[i][j] = edge.size();
				add_edge(cur, j, 0, 1);
			}
			if (!block[j][i]) {
				ndx[j][i] = edge.size();
				add_edge(cur, i, 0, 1);
			}
			++cur;
		}
	}

	for (int i = 0; i < n * (n - 1) / 2; ++i) {
		memset(in_que, false, sizeof in_que);
		memset(dist, 0x3f, sizeof dist);
		in_que[src] = true;
		queue<int> que;
		que.push(src);
		dist[src] = 0;

		while (!que.empty()) {
			int u = que.front();
			que.pop();
			in_que[u] = false;
			for (auto e : adj[u]) {
				auto [_, v, w, c] = edge[e];
				if (c && dist[u] + w < dist[v]) {
					dist[v] = dist[u] + w;
					pre[v] = e;
					if (!in_que[v]) {
						que.push(v);
						in_que[v] = true;
					}
				}
			}
		}

		int cur = sink;
		while (cur != src) {
			--get<3>(edge[pre[cur]]);
			++get<3>(edge[pre[cur] ^ 1]);
			cur = get<0>(edge[pre[cur]]);
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cout << (ndx[i][j] != -1 && get<3>(edge[ndx[i][j]]));
		}
		cout << "\n";
	}
}