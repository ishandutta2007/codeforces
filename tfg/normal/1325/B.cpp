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
		std::vector<int> a(n);
		for(auto &x : a) std::cin >> x;
		std::sort(a.begin(), a.end());
		std::cout << (int) (std::unique(a.begin(), a.end()) - a.begin()) << '\n';
	}
}