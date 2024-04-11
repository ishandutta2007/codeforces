#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 605;

long long dist[ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	/*
	(a, b) custo 0
	pode andar nos 2 grafos ao mesmo tempo
	*/
	struct Edge {
		int to, cost;
	};
	struct Query {
		int u, v, cost;
	};
	std::vector<std::vector<Edge>> edges(n);
	std::vector<Query> queries;
	for(int i = 0; i < m; i++) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		edges[u].push_back({v, c});
		edges[v].push_back({u, c});
		queries.push_back({u, v, c});
	}
	memset(dist, 0x3f, sizeof dist);
	int q;
	std::cin >> q;
	std::set<std::pair<long long, int>> hp;
	while(q--) {
		int u, v, l;
		std::cin >> u >> v >> l;
		u--;v--;
		dist[u][v] = dist[v][u] = -l;
	}
	for(int rep = 0; rep < 2; rep++) {
		for(int i = 0; i < n; i++) {
			std::vector<bool> vis(n, false);
			for(int j = 0; j < n; j++) {
				int best = -1;
				for(int k = 0; k < n; k++) if(!vis[k] && (best == -1 || dist[i][k] < dist[i][best])) {
					best = k;
				}
				vis[best] = true;
				for(auto edge : edges[best]) {
					int to = edge.to;
					auto toDist = dist[i][best] + edge.cost;
					dist[i][to] = std::min(dist[i][to], toDist);
				}
			}
		}
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				std::swap(dist[i][j], dist[j][i]);
			}
		}
	}
	int ans = 0;
	for(auto qry : queries) {
		if(dist[qry.u][qry.v] + qry.cost <= 0) {
			ans++;
		}
	}
	std::cout << ans << '\n';
}