#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	int ans = 0;
	std::cin >> str;
	for(auto c : str) if(c == 'a') ans++;
	ans = std::min(ans * 2 - 1, (int) str.size());
	if(ans < 0) ans = 0;
	std::cout << ans << '\n';
}