#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int tt;
	std::cin >> tt;
	while(tt--) {
		int n;
		std::cin >> n;
		std::string s, t;
		std::cin >> s;
		t = s;
		std::sort(t.begin(), t.end());
		int ans = 0;
		for(int i = 0; i < n; i++) if(t[i] != s[i]) {
			ans++;
		}
		std::cout << ans << '\n';
	}
}