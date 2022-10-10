#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long a, b, c;
	std::cin >> a >> b >> c;
	long long d = (a + b) / c;
	std::cout << d << ' ' << (d == a/c + b/c ? 0LL : std::min((c - a % c) % c , (c - b % c) % c)) << '\n';
}