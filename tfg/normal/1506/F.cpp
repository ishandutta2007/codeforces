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
		int n;
		std::cin >> n;
		std::vector<std::pair<int, int>> pts(n);
		for(int i = 0; i < n; i++) {
			std::cin >> pts[i].first;
		}
		for(int i = 0; i < n; i++) {
			std::cin >> pts[i].second;
		}
		pts.emplace_back(1, 1);
		std::sort(pts.begin(), pts.end());
		long long INF = 1e10;
		long long ans = 0;
		auto dist = [&](auto p1, auto p2) {
			if(p1 == p2) return 0LL;
			if(p2.second < p1.second) return INF;
			if(p2.second - p1.second > p2.first - p1.first) return INF;
			int deltaRow = p2.first - p1.first;
			int deltaCol = p2.second - p1.second;
			int parity = (p1.first + p1.second) % 2;
			if(deltaRow == deltaCol) {
				return parity == 0 ? (long long) deltaRow : 0LL;
			}
			int go = parity ? deltaRow : deltaRow - 1;
			//std::cout << "(" << p1.first << ", " << p1.second << "), (" << p2.first << ", " << p2.second << ") got " << (std::abs(go - deltaCol) + 1) / 2 << '\n';
			return (long long) (std::abs(go - deltaCol)+1) / 2LL;
		};
		for(int i = 0; i < n; i++) {
			ans += dist(pts[i], pts[i+1]);
		}
		assert(ans < INF);
		std::cout << ans << '\n';
	}
}