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
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	unsigned long long ans = 0;
	for(int l = 0; l+1 < n; l += 2) {
		long long bal = a[l];
		long long other[2] = {0, bal};
		for(int r = l+1; r < n; r++) {
			if(r % 2 == 1) {
				assert(bal > 0);
				long long range[2] = {bal - a[r], bal};
				ans += (unsigned long long) std::max(0LL, std::min(range[1], other[1]) - std::max(range[0], other[0]));
				bal -= a[r];
				if(bal < 0) {
					break;
				}
				other[1] = std::min(other[1], bal + 1);
			} else {
				bal += a[r];
			}
		}
	}
	std::cout << ans << '\n';
}