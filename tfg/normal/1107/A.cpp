#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::string str;
		std::cin >> n >> str;
		if(n == 2 && str[0] >= str[1]) {
			std::cout << "NO\n";
		} else {
			std::cout << "YES\n2\n";
			std::cout << str[0] << ' ' << str.substr(1, n-1) << '\n';
		}
	}
}