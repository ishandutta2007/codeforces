#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int a, b, c, d;
	char x, y;
	std::cin >> a >> x >> b >> c >> y >> d;
	std::cout << ((a + c) * 60 + b + d) / 2 / 60 / 10 << ((a + c) * 60 + b + d) / 2 / 60 % 10 << ":" << ((a + c) * 60 + b + d) / 2 % 60 / 10 << ((a + c) * 60 + b + d) / 2 % 60 % 10 << '\n';
}