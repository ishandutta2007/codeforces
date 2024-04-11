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
		std::vector<int> f(10, 0);
		std::string str;
		std::cin >> str;
		for(auto c : str) {
			f[c - '0']++;
		}
		if(f[0] == 0) {
			std::cout << "cyan\n";
			continue;
		}
		f[0]--;
		bool even = false;
		int sum = 0;
		for(int i = 0; i < 10; i++) {
			if(i % 2 == 0 && f[i]) {
				even = true;
			}
			sum += i * f[i];
		}
		if(even && sum % 3 == 0) {
			std::cout << "red\n";
		} else {
			std::cout << "cyan\n";
		}
	}
}