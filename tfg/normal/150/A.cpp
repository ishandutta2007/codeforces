#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::vector<long long> primes;
	long long x;
	std::cin >> x;
	for(long long i = 2; i * i <= x; i++) {
		while(x % i == 0) {
			primes.emplace_back(i);
			x /= i;
		}
	}
	if(x > 1) {
		primes.emplace_back(x);
	}
	if(primes.size() <= 1) {
		std::cout << "1\n0\n";
	} else if(primes.size() > 2) {
		std::cout << "1\n";
		std::cout << primes[0] * primes[1] << "\n";
	} else {
		std::cout << "2\n";
	}
}