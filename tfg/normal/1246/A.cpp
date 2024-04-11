#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, p;
	std::cin >> n >> p;
	for(int ans = 1; ans < 100100 && n - p * ans > 0; ans++) {
		long long val = n - p * ans;
		int bits = 0;
		long long x = val;
		while(x) {
			bits += x & 1;
			x >>= 1;
		}
		if(bits <= ans && ans <= val) {
			std::cout << ans << '\n';
			return 0;
		}
	}
	std::cout << "-1\n";
}