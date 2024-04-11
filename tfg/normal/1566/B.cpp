#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		std::string str;
		std::cin >> str;
		int l = 0, r = (int) str.size();
		while(l < r && str[l] != '0') l++;
		while(r > l && str[r-1] != '0') r--;
		if(l == r) {
			std::cout << "0\n";
		} else if(l == r+1) {
			std::cout << "1\n";
		} else {
			bool got = false;
			for(int i = l; i < r; i++) {
				got = got || str[i] == '1';
			}
			std::cout << (got ? 2 : 1) << '\n';
		}
	}
}