#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for(auto &v : a) {
		std::cin >> v;
	}
	std::sort(a.begin(), a.end());
	auto test = [&](long long x) {
		long long cost = 0;
		for(int i = n / 2; i < n; i++) {
			if(a[i] <= x) {
				cost += x - a[i];
			}
		}
		return cost;
	};
	long long l = 0, r = 1e10;
	while(l != r) {
		long long mid = (l + r + 1) / 2;
		if(test(mid) <= k) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	std::cout << l << '\n';
}