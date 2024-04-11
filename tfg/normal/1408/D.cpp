#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<std::pair<int, int>> pts(n), lights(m);
	for(auto &pt : pts) {
		std::cin >> pt.first >> pt.second;
	}
	for(auto &pt : lights) {
		std::cin >> pt.first >> pt.second;
	}
	std::vector<std::pair<int, int>> events;
	for(auto pt : pts) {
		for(auto li : lights) {
			if(!(pt.first <= li.first && pt.second <= li.second)) {
				continue;
			}
			int cost = li.second - pt.second + 1;
			events.emplace_back(li.first - pt.first + 1, cost);
		}
	}
	std::sort(events.rbegin(), events.rend());
	int ans = 1e9;
	int cur = 0;
	for(auto e : events) {
		ans = std::min(ans, cur + e.first);
		cur = std::max(cur, e.second);
	}
	ans = std::min(ans, cur);
	std::cout << ans << '\n';
}