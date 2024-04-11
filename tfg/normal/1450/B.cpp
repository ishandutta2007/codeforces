#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, k;
		std::cin >> n >> k;
		std::vector<std::pair<int, int>> a;
		for(int i = 0; i < n; i++) {
			int x, y;
			std::cin >> x >> y;
			a.emplace_back(x, y);
		}
		bool good = false;
		for(int i = 0; i < n && !good; i++) {
			int got = 0;
			for(int j = 0; j < n; j++) {
				if(std::abs(a[i].first - a[j].first) + std::abs(a[i].second - a[j].second) <= k) {
					got++;
				}
			}
			if(got == n) {
				good = true;
			}
		}
		std::cout << (good ? 1 : -1) << '\n';
	}
}