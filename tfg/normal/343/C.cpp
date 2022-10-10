#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<long long> a(n), b(m);
	for(auto &x : a) std::cin >> x;
	for(auto &x : b) std::cin >> x;
	auto check = [&](long long x) {
		int j = 0;
		for(int i = 0; i < n && j < m; i++) {
			long long prv = 0;
			if(b[j] <= a[i]) {
				// has to go back
				if(a[i] - b[j] > x) return false;
				prv = a[i] - b[j];
				while(j < m && b[j] <= a[i]) j++;
			}
			while(j < m && prv + b[j] - a[i] + std::min(b[j] - a[i], prv) <= x) j++;
		}
		return j == m;
	};
	long long l = 0, r = 1e11;
	while(l != r) {
		long long mid = (l + r) / 2;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << '\n';
}