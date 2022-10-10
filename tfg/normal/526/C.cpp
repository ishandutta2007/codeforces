#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long c, cost[2], weight[2];
	std::cin >> c >> weight[0] >> weight[1] >> cost[0] >> cost[1];
	const int ms = 1e5;
	long long ans = 0;
	for(int i = 0; i * cost[0] <= c && i < ms; i++) {
		ans = std::max(ans, i * weight[0] + (c - i * cost[0]) / cost[1] * weight[1]);
	}
	std::swap(cost[0], cost[1]);
	std::swap(weight[0], weight[1]);
	for(int i = 0; i * cost[0] <= c && i < ms; i++) {
		ans = std::max(ans, i * weight[0] + (c - i * cost[0]) / cost[1] * weight[1]);
	}
	std::cout << ans << '\n';
}