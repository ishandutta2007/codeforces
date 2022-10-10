#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cstring>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MOD = 1e9 + 7;
const int ms = 3001000;

long long fexp(long long x, long long e) {
	long long ans = 1;
	for(; e > 0; e /= 2) {
		if(e & 1) ans = ans * x % MOD;
		x = x * x % MOD;
	}
	return ans;
}

std::vector<std::pair<int, int>> edges[ms];
int id[ms], cost[ms];
int dist[ms];
bool visit[ms];

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	int c = n+1;
	auto createRoad = [&](int u, int v, int i) {
		std::vector<int> str;
		int x = i;
		while(x != 0) {
			str.push_back(x % 10);
			x /= 10;
		}
		std::reverse(str.begin(), str.end());
		int last = str.back();
		str.pop_back();
		int on = u;
		//std::cout << "for edge " << u << ", " << v << ", " << i << '\n';
		for(auto x : str) {
			//std::cout << "adding (" << on << ", " << c << ", " << x << ")\n";
			edges[on].emplace_back(c++, x);
			on = c - 1;
		}
		edges[on].emplace_back(v, last);
	};
	for(int i = 1; i <= m; i++) {
		int u, v;
		std::cin >> u >> v;
		createRoad(u, v, i);
		createRoad(v, u, i);
	}
	dist[1] = 0;
	std::vector<std::vector<int>> que, nxt;
	que.emplace_back(1, 1);
	visit[1] = true;
	while(!que.empty()) {
		int sum = 0;
		for(auto &v : que) {
			std::vector<int> nxtt[10];
			for(auto i : v) {
				for(auto to : edges[i]) {
					if(!visit[to.first]) {
						nxtt[to.second].push_back(to.first);
						dist[to.first] = dist[i];
						//std::cout << "to " << to.first << " from " << i << " with dist " << (10LL * dist[i] + to.second) << '\n';
					}
				}
			}
			for(int i = 0; i < 10; i++) {
				std::vector<int> ha;
				for(auto on : nxtt[i]) {
					if(!visit[on]) {
						visit[on] = true;
						dist[on] = ((long long) dist[on] * 10 + i) % MOD;
						ha.push_back(on);
					}
				}
				if(!ha.empty()) {
					nxt.push_back(ha);
				}
			}
		}
		que.swap(nxt);
		nxt.clear();
	}
	for(int i = 2; i <= n; i++) {
		std::cout << dist[i] << '\n';
	}
}