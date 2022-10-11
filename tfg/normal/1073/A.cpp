#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	for(int l = 0; l < n; l++) {
		std::vector<int> freq(26, 0);
		int mx = 0;
		for(int r = l; r < n; r++) {
			freq[str[r] - 'a']++;
			mx = std::max(mx, freq[str[r] - 'a']);
			if(2 * mx <= r - l + 1) {
				std::cout << "YES\n";
				std::cout << str.substr(l, r - l + 1) << '\n';
				return 0;
			}
		}
	}
	std::cout << "NO\n";
}