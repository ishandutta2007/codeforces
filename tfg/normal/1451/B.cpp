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
		int n, q;
		std::string str;
		std::cin >> n >> q >> str;
		while(q--) {
			int l, r;
			std::cin >> l >> r;
			l--;
			auto pat = str.substr(l, r-l);
			int i = 0;
			while(str[i] != pat[0]) i++;
			if(i < l) {
				std::cout << "YES\n";
				continue;
			}
			i = n-1;
			while(str[i] != pat.back()) i--;
			if(i >= r) {
				std::cout << "YES\n";
			} else {
				std::cout << "NO\n";
			}
		}
	}
}