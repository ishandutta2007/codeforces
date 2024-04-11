#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 202;
const int INF = 1e9;
int dist[ms][ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	memset(dist, 0x3f, sizeof dist);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> edges;
	for(int i = 0; i < m; i++) {
		int u, v, t;
		std::cin >> u >> v >> t;
		u--;v--;
		edges.emplace_back(u, v);
		dist[u][v] = 1;
		dist[v][u] = t == 1 ? -1 : 1;
	}
	for(int i = 0; i < n; i++) {
		dist[i][i] = 0;
	}
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int best[2] = {0, 0};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(dist[i][j] + dist[j][i] < 0 || (dist[i][j] + dist[j][i]) % 2 != 0) {
				std::cout << "NO\n";
				return 0;
			}
			if(dist[i][j] > dist[best[0]][best[1]]) {
				best[0] = i, best[1] = j;
			}
		}
	}
	for(auto e : edges) {
		if((dist[best[0]][e.first] + dist[best[0]][e.second]) % 2 == 0) {
			std::cout << "NO\n";
			return 0;
		}
	}
	std::cout << "YES\n" << dist[best[0]][best[1]] << '\n';
	for(int i = 0; i < n; i++) {
		std::cout << dist[best[0]][i] << (i + 1 == n ? '\n' : ' ');
	}
}