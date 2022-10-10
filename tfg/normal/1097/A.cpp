#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string a;
	std::cin >> a;
	for(int i = 0; i < 5; i++) {
		std::string b;
		std::cin >> b;
		if(a[0] == b[0] || a[1] == b[1]) {
			std::cout << "YES\n";
			return 0;
		}
	}
	std::cout << "NO\n";
}