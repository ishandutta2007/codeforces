#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long k, b, n, t;
	std::cin >> k >> b >> n >> t;
	long long ans = n;
	long long cur = 1;
	while(cur * k + b <= t) {
		cur = cur * k + b;
		ans--;
		//std::cout << "got to " << cur << "\n";
	}
	std::cout << std::max(ans, 0LL) << '\n';
}