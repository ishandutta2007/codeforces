#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct Edge {
	int u, v, c = -1;
};

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<Edge> edges;
	int c = 0;
	std::vector<int> deg(n, 0);
	for(int i = 0; i + 1 < n; i++) {
		int u, v;
		std::cin >> u >> v;
		Edge cur;
		u--;v--;
		cur.u = u;
		cur.v = v;
		edges.push_back(cur);
		deg[u]++;
		deg[v]++;
	}
	for(int i = 0; i+1 < n; i++) {
		if(std::min(deg[edges[i].u], deg[edges[i].v]) == 1) {
			edges[i].c = c++;
		}
	}
	for(int i = 0; i+1 < n; i++) {
		if(edges[i].c == -1) {
			edges[i].c = c++;
		}
		std::cout << edges[i].c << (i+2 == n ? '\n' : ' ');
	}

}