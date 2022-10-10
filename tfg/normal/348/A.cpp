#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	long long l = 0, r = 2e9;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		l = std::max(l, (long long) a[i]);
	}
	auto check = [&](long long x) {
		long long can = 0;
		for(int i = 0; i < n; i++) {
			can += x - a[i];
		}
		bool good = true;
		for(int i = 0; i < n; i++) {
			good = good && can - (x - a[i]) >= a[i];
		}
		return good;
	};
	while(l != r) {
		long long mid = (l + r) / 2;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	std::cout << l << std::endl;
}