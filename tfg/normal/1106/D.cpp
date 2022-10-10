#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int> > edges(n);
	for(int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	std::set<int> visit, q;
	q.insert(0);
	while(!q.empty()) {
		int on = *q.begin();
		q.erase(on);
		if(visit.count(on)) continue;
		visit.insert(on);
		if(on) std::cout << ' ';
		std::cout << on + 1;
		for(auto to : edges[on]) {
			q.insert(to);
		}
	}
	std::cout << '\n';
}