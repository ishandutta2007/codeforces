#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::string str;
		std::cin >> str;
		auto ans = str;
		int wtf = 1;
		for(int i = 2; i <= n; i++) {
			auto cur = str.substr(i-1, n-(i-1)) + str.substr(0, i-1);
			if((n - i) % 2 == 0) {
				std::reverse(cur.begin() + n-i+1, cur.end());
			}
			//std::cout << "at " << i << " got " << cur << '\n';
			if(ans > cur) {
				ans = cur;
				wtf = i;
			}
		}
		std::cout << ans << '\n' << wtf << '\n';
	}
}