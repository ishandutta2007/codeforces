#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <cstdlib>
#include <set>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int ms = 100100;

int n, sq;
std::set<int> ind;
std::vector<int> path;
bool visit[ms];
std::vector<int> edges[ms];

void dfs(int on) {
	assert(!visit[on]);
	visit[on] = true;
	path.push_back(on);
	bool good = true;
	for(auto to : edges[on]) {
		good = good && !ind.count(to);
	}
	if(good) {
		ind.insert(on);
		if((int) ind.size() == (sq + 1) / 2) {
			std::cout << "1\n";
			for(auto x : ind) std::cout << x+1 << '\n';
			exit(0);
		}
	}
	std::shuffle(edges[on].begin(), edges[on].end(), rng);
	for(auto to : edges[on]) {
		if(to == path[0] && (int) path.size() <= sq && (int) path.size() > 2) {
			std::cout << "2\n" << path.size() << '\n';
			for(auto x : path) std::cout << x+1 << '\n';
			exit(0);
		}
		if(!visit[to]) dfs(to);
	}
	path.pop_back();
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int m;
	std::cin >> n >> m >> sq;
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	while(1) {
		ind.clear();
		for(int i = 0; i < n; i++) {
			visit[i] = false;
		}
		dfs(rng() % n);
	}
	assert(0);
}