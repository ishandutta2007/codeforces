#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	const int ms = 8;
	const int INF = 1e9;
	std::vector<int> cost(ms, INF);
	cost[0] = 0;
	while(n--) {
		int x;
		std::string str;
		std::cin >> x >> str;
		int mask = 0;
		for(auto c : str) {
			mask |= 1 << (c - 'a');
		}
		for(int i = 0; i < 8; i++) {
			cost[i|mask] = std::min(cost[i|mask], cost[i] + x);
		}
	}
	int ans = cost[ms-1];
	if(ans == INF) {
		ans = -1;
	}
	std::cout << ans << '\n';
}