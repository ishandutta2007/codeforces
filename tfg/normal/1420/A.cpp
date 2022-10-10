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
		std::vector<int> a(n), b(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			b[i] = a[i];
		}
		std::sort(b.rbegin(), b.rend());
		b.resize(std::unique(b.begin(), b.end()) - b.begin());
		std::cout << (a == b ? "NO\n" : "YES\n");
	}
}