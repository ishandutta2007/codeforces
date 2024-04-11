#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		std::string str;
		std::cin >> str;
		int n = (int) str.size();
		std::sort(str.begin(), str.end());
		bool ans = true;
		for(int i = 0; i + 1 < n; i++) {
			ans = ans && str[i] + 1 == str[i+1];
		}
		std::cout << (ans ? "Yes\n" : "No\n");
	}
}