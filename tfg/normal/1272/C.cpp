#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::string str;
	std::cin >> str;
	std::vector<int> can(26, 0);
	while(k--) {
		char c;
		std::cin >> c;
		can[c-'a'] = true;
	}
	long long ans = 0;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && can[str[l]-'a'] == can[str[r]-'a']) r++;
		if(can[str[l]-'a']) {
			ans += (long long) (r - l) * (r - l + 1) / 2; 
		}
	}
	std::cout << ans << '\n';
}