#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::vector<int> topologicalOrder(const std::vector<std::vector<int>> &graph) {
	int n = (int) graph.size();
	std::vector<int> deg(n, 0);
	for(int i = 0; i < n; i++) {
		for(auto j : graph[i]) {
			deg[j]++;
		}
	}
	std::vector<int> order;
	for(int i = 0; i < n; i++) {
		if(deg[i] == 0) {
			order.push_back(i);
		}
	}
	for(int i = 0; i < (int) order.size(); i++) {
		int on = order[i];
		for(auto to : graph[on]) {
			if(--deg[to] == 0) {
				order.push_back(to);
			}
		}
	}
	return order;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> rank(n), mx(n, k), mn(n, 1);
	std::vector<std::vector<int>> graph(n);
	for(int i = 0; i < n; i++) {
		std::cin >> rank[i];
		if(rank[i]) {
			rank[i] = k - rank[i] + 1;
		}
	}
	while(m--) {
		int u, v;
		std::cin >> u >> v;
		u--;v--;
		graph[u].push_back(v);
	}
	auto ord = topologicalOrder(graph);
	if((int) ord.size() != n) {
		std::cout << "-1\n";
		return 0;
	}
	for(auto i : ord) {
		if(rank[i]) {
			if(rank[i] < mn[i]) {
				std::cout << "-1\n";
				return 0;
			}
			mn[i] = rank[i];
		}
		if(mn[i] > k) {
			std::cout << "-1\n";
			return 0;
		}
		for(auto j : graph[i]) {
			//std::cout << "to " << j << " from " << i << " with " << mn[i]+1 << '\n';
			mn[j] = std::max(mn[j], mn[i]+1);
		}
	}
	std::reverse(ord.begin(), ord.end());
	for(auto i : ord) {
		for(auto j : graph[i]) {
			mx[i] = std::min(mx[i], mx[j]-1);
		}
		if(rank[i]) {
			assert(mx[i] >= rank[i]);
			mx[i] = rank[i];
		}
		assert(mn[i] <= mx[i]);
	}
	//std::cout << "got here\n";
	std::reverse(ord.begin(), ord.end());
	std::vector<std::vector<int>> events(k+1);
	std::vector<int> rev(n);
	for(int i = 0; i < n; i++) {
		rev[ord[i]] = i;
	}
	for(int i = 0; i < n; i++) {
		events[mx[i]].push_back(i);
	}
	std::priority_queue<std::pair<int, int>> hp;
	for(int i = k; i > 0; i--) {
		for(auto id : events[i]) {
			hp.push({mn[id], rev[id]});
		}
		if(hp.empty()) {
			std::cout << "-1\n";
			return 0;
		}
		do {
			rank[ord[hp.top().second]] = i;
			//std::cout << "for " << ord[hp.top().second] << " setting as " << i << std::endl;
			hp.pop();
		} while(!hp.empty() && hp.top().first == i);
	}
	for(int i = 0; i < n; i++) {
		std::cout << k - rank[i] + 1 << (i + 1 == n ? '\n' : ' ');
	}
}