#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int a, b;
	std::cin >> a >> b;
	if(b % a != 0) {
		std::cout << "-1\n";
		return 0;
	}
	int ans = 0;
	b /= a;
	while(b % 3 == 0) {
		ans++;
		b /= 3;
	}
	while(b % 2 == 0) {
		ans++;
		b /= 2;
	}
	if(b != 1) {
		ans = -1;
	}
	std::cout << ans << '\n';
}