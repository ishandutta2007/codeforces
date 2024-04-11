#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int tt;
	std::cin >> tt;
	while(tt--) {
		std::string s, t;
		std::cin >> s >> t;
		std::reverse(s.begin(), s.end());
		std::reverse(t.begin(), t.end());
		int n = 0;
		while(t[n] != '1') n++;
		int m = n;
		while(s[m] != '1') m++;
		std::cout << m-n << '\n';
	}
}