#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

inline int dist(const std::pair<int, int> &a, const std::pair<int, int> &b) { return abs(a.first - b.first) + abs(a.second - b.second); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int trash, n;
	const int MAGIC = 1010;
	std::cin >> trash >> n;
	std::vector<std::pair<int, int>> pts(n+1);
	std::vector<int> t(n+1);
	t[0] = 0;
	pts[0] = std::pair<int, int>(1, 1);
	std::vector<int> dp(n+1, -2*n);
	std::vector<int> other(n+1, 0);
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		std::cin >> t[i] >> pts[i].first >> pts[i].second;
		for(int j = 1; j <= MAGIC && j <= i; j++) {
			if(dist(pts[i], pts[i-j]) <= t[i] - t[i-j]) {
				//std::cout << dist(pts[i], pts[i-j]) << ", " << t[i] - t[i-j] << '\n';
				dp[i] = std::max(dp[i], 1 + dp[i-j]);
			}
			if(j == MAGIC) {
				dp[i] = std::max(dp[i], 1 + other[i-j]);
			}
		}
		other[i] = std::max(dp[i], other[i-1]);
	}
	std::cout << other.back() << '\n';
}