#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> bal(n);
	std::vector<std::vector<std::pair<int, int>>> edges(n);
	for(int i = 0; i < n; i++) {
		std::cin >> bal[i];
	}
	const int INF = 1e9;
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].emplace_back(v, i);
		edges[v].emplace_back(u, i);
		bal[u]--;
		bal[v]--;
	}
	std::vector<int> topo;
	std::vector<int> ans;
	std::vector<bool> wtf(n, false);
	for(int i = 0; i < n; i++) {
		if(bal[i] >= 0) {
			bal[i] = INF;
			topo.push_back(i);
		}
	}
	for(int i = 0; i < (int) topo.size(); i++) {
		int on = topo[i];
		for(auto to : edges[on]) {
			if(!wtf[to.first]) {
				ans.push_back(to.second);
			}
		}
		wtf[on] = true;
		for(auto to : edges[on]) {
			if(bal[to.first] == INF) continue;
			bal[to.first]++;
			if(bal[to.first] >= 0) {
				topo.push_back(to.first);
				bal[to.first] = INF;
			}
		}
	}
	if((int) topo.size() == n) {
		assert((int) ans.size() == m);
		std::cout << "ALIVE\n";
		for(int i = 0; i < m; i++) {
			std::cout << ans[m-i-1] + 1 << (i + 1 == m ? '\n' : ' ');
		}
	} else {
		std::cout << "DEAD\n";
	}
}