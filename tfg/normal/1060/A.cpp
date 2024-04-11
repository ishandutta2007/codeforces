#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	int ans = 0;
	std::string str;
	std::cin >> str;
	for(auto c : str) {
		if(c == '8') {
			ans++;
		}
	}
	ans = std::min(ans, n / 11);
	std::cout << ans << std::endl;
}