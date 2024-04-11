#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	// 1 <= a <= b <= c <= n
	// a^2 = c + b = c^2 - b^2
	// c + b = c^2 - b^2
	// c + b = (c + b) * (c - b)
	// c - b = 1
	// for a certain a, we want c = a^2 / 2 + 0.5 and b = a^2 / 2 - 0.5
	std::vector<int> kek;
	const int INF = 1e9 + 10;
	for(int i = 3; i*i/2+1 <= INF; i += 2) {
		kek.push_back(i*i/2+1);
	}
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::cout << std::upper_bound(kek.begin(), kek.end(), n) - kek.begin() << '\n';
	}
}