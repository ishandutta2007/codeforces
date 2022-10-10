#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	for(int i = 1; i <= 100; i++) for(int j = 1; j <= 100; j++) {
		//if(j % i == j / i) std::cout << i << ", " << j << "\n";
	}
	int t;
	std::cin >> t;
	while(t--) {
		long long x, y;
		std::cin >> y >> x;
		// sum for 2 <= i <= x of min(y / (i + 1), i-1)
		
		long long ans = 0;
		for(long long l = 3, r; l <= y && l <= x+1; l = r + 1) {
			if(l - 2 <= y / (l + 1)) {
				r = l;
				ans += l - 2;
				continue;
			}
			r = y / (y / l);
			//std::cout << "range [" << l << ", " << r << "] has result " << y / l << '\n';
			long long size = std::max(0LL, std::min(r, x+1) - l+1);
			//std::cout << "size is " << size << '\n';
			ans += size * (y / l);
		}
		std::cout << ans << '\n';
	}
}