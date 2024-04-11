#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	auto check = [&](int x) {
		int bal = 0;
		for(auto v : a) {
			if(v > x) return false;
			bal += x - v;
			bal -= v;
		}
		return bal > 0;
	};
	int l = 0, r = 1000;
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << '\n';
}