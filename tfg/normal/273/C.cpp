#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 300300;

std::vector<int> edges[ms];
int c[ms];

void dfs(int on) {
	int same = 0;
	for(auto to : edges[on]) {
		if(c[to] == c[on]) same++;
	}
	if(same > 1) {
		c[on] ^= 1;
		for(auto to : edges[on]) {
			dfs(to);
		}
	}
}
int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	for(int i = 0; i < n; i++) {
		dfs(i);
	}
	for(int i = 0; i < n; i++) {
		std::cout << c[i];
	}
	std::cout << '\n';
}