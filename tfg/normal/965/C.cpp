#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, k;
	std::cin >> n >> k;
	long long limit;
	std::cin >> limit;
	int trips;
	std::cin >> trips;
	long long ans = 0;
	for(int i = 1; i <= trips; i++) {
		long long l = 1, r = limit;
		while(l != r) {
			long long mid = (l + r + 1) / 2;
			if(n / mid / k + ((n / mid) % k > 0 ? 1 : 0) >= i) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		//std::cout << "at " << i << " got answer " << l << ", and " << n / l / k + ((n / l) % k > 0 ? 1 : 0) << " trips\n";
		if(n / l / k + ((n / l) % k > 0 ? 1 : 0) == i) {
			ans = std::max(ans, l * i);
		}
	}
	std::cout << ans << '\n';
}