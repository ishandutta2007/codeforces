#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long solve(long long a, long long b) {
	if(a == 0) { return 0; }
	if(a >= b) {
		return a / b + solve(a % b, b);
	} else {
		long long use = (b - 1) / a;
		return use + solve(a, b - use * a);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long a, b;
	std::cin >> a >> b;
	std::cout << solve(a, b) << '\n';
}