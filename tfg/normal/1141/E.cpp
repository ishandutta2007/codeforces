#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long hp;
	int n;
	std::cin >> hp >> n;
	long long sum = 0;
	std::vector<long long> a(n + 1, 0);
	std::vector<long long> b(n, 0);
	for(int i = 1; i <= n; i++) {
		std::cin >> a[i];
		b[i-1] = a[i];
		a[i] += a[i-1];
		if(hp + a[i] <= 0) {
			std::cout << i << "\n";
			return 0;
		}
	}
	sum = a[n];
	if(sum >= 0) {
		std::cout << "-1\n";
		return 0;
	}
	long long INF = 1e18;
	long long l = n, r = INF;
	//std::cout << "sum is " << sum << '\n';
	auto test = [&](long long x) {
		//std::cout << "testing for " << x << '\n';
		assert(x >= n);
		if(hp + sum * (x / n - 1.0) < -1e8) {
			return true;
		}
		if(hp + sum * (x / n - 1) <= 0) {
			return true;
		}
		long long h = hp + sum * (x / n - 1);
		x -= (x / n - 1) * n;
		assert(x <= 2 * n);
		for(int i = 0; i < x; i++) {
			h += b[i % n];
			if(h <= 0) return true;
		}
		//std::cout << "false for it\n";
		return false;
	};
	while(l != r) {
		long long mid = (l + r) / 2;
		if(test(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	if(l >= INF) {
		l = -1;
	}
	std::cout << l << '\n';
}