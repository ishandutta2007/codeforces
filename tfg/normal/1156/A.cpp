#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int ans = 0;
	for(int i = 1; i < n; i++) {
		int u = a[i-1], v = a[i];
		if(u > v) {
			std::swap(u, v);
		}
		if(u == 1 && v == 2) {
			ans += 3;
		} else if(u == 1 && v == 3) {
			ans += 4;
		} else {
			std::cout << "Infinite\n";
			return 0;
		}
		if(i >= 2 && a[i] == 2 && a[i-1] == 1 && a[i-2] == 3) {
			ans--;
		}
	}
	std::cout << "Finite\n" << ans << '\n';
}