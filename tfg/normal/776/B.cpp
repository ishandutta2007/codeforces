#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 100100;
	std::vector<bool> prime(ms, true);
	for(int i = 2; i < ms; i++) {
		if(!prime[i]) continue;
		for(int j = i+i; j < ms; j += i) {
			prime[j] = false;
		}
	}
	int n;
	std::cin >> n;
	std::cout << (n <= 2 ? 1 : 2) << '\n';
	for(int i = 1; i <= n; i++) {
		std::cout << (prime[i+1] ? 1 : 2) << (i == n ? '\n' : ' ');
	}
}