#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int getCost(int x) { x = abs(x); return std::min(x, 26 - x); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	int n;
	std::cin >> n >> str;
	int ans = 10203891;
	for(int i = 0; i + 4 <= n; i++) {
		int cost = getCost(str[i+0] - 'A') + getCost(str[i+1] - 'C') + getCost(str[i+2] - 'T') + getCost(str[i+3] - 'G');
		ans = std::min(ans, cost);
	}
	std::cout << ans << '\n';
}