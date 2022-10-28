#include <bits/stdc++.h> 
using namespace std;

const int MX = 4000 + 5;

int deg[MX], mat[MX], lim[MX], pre_edge[MX], pre_node[MX], flow;
vector<int> ans[MX], adj[MX];
vector<pair<int, int>> edges;

void add_edge(int u, int v, int w) {
	adj[u].push_back(edges.size());
	edges.emplace_back(v, w);
	adj[v].push_back(edges.size());
	edges.emplace_back(u, 0);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n1, n2, m;
	cin >> n1 >> n2 >> m;
	int src = n1 + n2 + 1;
	int sink = n1 + n2 + 2;
	for (int i = 1; i <= m; ++i) {
		int u, v;
		cin >> u >> v;
		v += n1;
		++deg[u];
		++deg[v];
		mat[i] = edges.size();
		add_edge(u, v, 1);
	}

	int mx_k = *min_element(deg + 1, deg + 1 + n1 + n2);
	for (int i = 1; i <= n1; ++i) {
		lim[i] = edges.size();
		add_edge(src, i, deg[i] - mx_k);
	}
	for (int i = n1 + 1; i <= n1 + n2; ++i) {
		lim[i] = edges.size();
		add_edge(i, sink, deg[i] - mx_k);
	}

	for (int k = mx_k; k; --k) {
		while (true) {
			queue<int> que;
			que.push(src);
			memset(pre_edge, -1, sizeof pre_edge);
			memset(pre_node, -1, sizeof pre_node);
			while (!que.empty()) {
				int u = que.front();
				que.pop();
				for (auto e : adj[u]) {
					auto [v, w] = edges[e];
					if (w && pre_node[v] == -1) {
						pre_node[v] = u;
						pre_edge[v] = e;
						que.push(v);
					}
				}
			}

			if (pre_node[sink] != -1) {
				for (int u = sink; u != src; u = pre_node[u]) {
					--edges[pre_edge[u]].second;
					++edges[pre_edge[u] ^ 1].second;
				}
				++flow;
			} else
				break;
		}

		for (int i = 1; i <= m; ++i) {
			if (edges[mat[i]].second) {
				ans[k].push_back(i);
			}
		}

		for (int i = 1; i <= n1 + n2; ++i) {
			++edges[lim[i]].second;
		}
	}

	for (int i = 0; i <= mx_k; ++i) {
		cout << ans[i].size();
		for (auto j : ans[i]) {
			cout << ' ' << j;
		}
		cout << '\n';
	}
}