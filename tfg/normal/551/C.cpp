#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	auto test = [&](long long x) {
		int used = 0;
		long long rest = 0;
		for(int i = n-1; i >= 0; i--) {
			if(a[i] == 0) {
				continue;
			}
			while(rest < a[i] && used < m) {
				used++;
				rest += x - i - 1;
			}
			if(rest >= a[i]) {
				rest -= a[i];
			} else {
				return false;
			}
		}
		return true;
	};
	long long l = 0, r = 1e18;
	while(l != r) {
		long long mid = (l + r) / 2;
		if(test(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	std::cout << l << '\n';
}