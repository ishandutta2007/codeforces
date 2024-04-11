#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 200200;

int leafs, buds;
std::vector<int> edges[ms];

bool dfs(int on, int par) {
	int below = 0;
	for(auto to : edges[on]) if(to != par) {
		if(dfs(to, on)) {
			below++;
		}
	}
	if(below) {
		if(on) buds++;
	} else {
		leafs++;
	}
	return below == 0;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		for(int i = 0; i < n; i++) {
			edges[i].clear();
		}
		for(int i = 1; i < n; i++) {
			int u, v;
			std::cin >> u >> v;
			u--;v--;
			edges[u].push_back(v);
			edges[v].push_back(u);
		}
		leafs = 0;
		buds = 0;
		dfs(0, -1);
		std::cout << leafs - buds << '\n';
	}
}