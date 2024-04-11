#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <set>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long trash;
	int n, m, k;
	std::cin >> trash >> n >> m >> k;
	std::vector<long long> pos(n);
	std::vector<int> cost(n);
	std::vector<bool> can(n, false);
	for(int i = 0; i < n; i++) {
		std::cin >> pos[i] >> cost[i];
		pos[i]--;
	}
	std::vector<long long> dist(k, trash + 1);
	dist[0] = 0;
	std::set<std::pair<int, int>> wtf;
	auto dij = [&](long long gap) {
		std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> hp;
		for(int i = 0; i < k; i++) {
			hp.push({dist[i], i});
		}
		while(!hp.empty()) {
			long long curDist = hp.top().first;
			int on = hp.top().second;
			hp.pop();
			if(curDist != dist[on]) {
				continue;
			}
			int to = (int)((on + gap) % k);
			if(dist[to] > curDist + gap) {
				dist[to] = curDist + gap;
				hp.push({dist[to], to});
			}
		}
		for(int i = 0; i < n; i++) {
			if(!can[i] && pos[i] >= dist[pos[i] % k]) {
				can[i] = true;
				wtf.insert({cost[i], -i});
			}
		}
	};
	dij(k);
	while(m--) {
		int t;
		std::cin >> t;
		if(t == 1) {
			long long x;
			std::cin >> x;
			dij(x);
		} else if(t == 2) {
			int x, y;
			std::cin >> x >> y;
			x--;
			if(can[x]) {
				wtf.erase({cost[x], -x});
			}
			cost[x] -= y;
			if(can[x]) {
				wtf.insert({cost[x], -x});
			}
		} else {
			std::cout << (wtf.empty() ? 0 : wtf.rbegin()->first) << '\n';
			if(!wtf.empty()) {
				wtf.erase(*wtf.rbegin());
			}
		}
	}
}