#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n;
	std::cin >> n;
	for(long long i = 1; i * i + i + 1 + 2 * i <= n; i++) {
		long long got = i * i + 3 * i + 1;
		if((n - got) % (2 * i) == 0) {
			std::cout << i << ' ' << (n - got) / (2 * i) + 1 << std::endl;
			return 0;
		}
	}
	std::cout << "NO\n";
}