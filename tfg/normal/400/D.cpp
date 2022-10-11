#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 550;
const int INF = 1e9 + 9;

int par[100100], wtf[100100];
int getPar(int x) { return x == par[x] ? x : par[x] = getPar(par[x]); }
int dist[ms][ms];


struct Edge {
	int u, v, c;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> sum(k+1, 0);
	for(int i = 1; i <= k; i++) {
		std::cin >> sum[i];
		sum[i] += sum[i-1];
	}
	for(int i = 0; i < n; i++) {
		par[i] = i;
	}
	std::vector<Edge> edges;
	while(m--) {
		int u, v, c;
		std::cin >> u >> v >> c;
		u--;v--;
		assert(0 <= std::min(u, v) && std::max(u, v) < n);
		if(c == 0) {
			par[getPar(u)] = getPar(v);
		} else {
			Edge e;
			e.u = u, e.v = v, e.c = c;
			edges.push_back(e);
		}
	}
	for(int i = 0; i < k; i++) {
		for(int x = sum[i]; x < sum[i+1]; x++) {
			if(getPar(x) != getPar(sum[i])) {
				std::cout << "No\n";
				return 0;
			}
		}
	}
	int c = 0;
	for(int i = 0; i < n; i++) {
		if(par[i] == i) wtf[i] = c++;
	}
	for(int i = 0; i < n; i++) {
		wtf[i] = wtf[getPar(i)];
	}
	for(int i = 0; i < c; i++) {
		for(int j = 0; j < c; j++) {
			dist[i][j] = i == j ? 0 : INF;
		}
	}
	for(auto e : edges) {
		int u = wtf[e.u], v = wtf[e.v], cost = e.c;
		dist[u][v] = dist[v][u] = std::min(dist[u][v], cost);
	}
	for(int x = 0; x < c; x++) {
		for(int i = 0; i < c; i++) {
			for(int j = 0; j < c; j++) {
				dist[i][j] = std::min(dist[i][j], dist[i][x] + dist[x][j]);
			}
		}
	}
	std::cout << "Yes\n";
	for(int i = 0; i < k; i++) {
		for(int j = 0; j < k; j++) {
			std::cout << (dist[wtf[sum[i]]][wtf[sum[j]]] >= INF ? -1 : dist[wtf[sum[i]]][wtf[sum[j]]]) << (j + 1 == c ? '\n' : ' ');
		}
	}
}