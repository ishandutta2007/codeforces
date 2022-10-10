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
		std::string str;
		std::cin >> str;
		std::vector<int> a;
		for(int l = 0, r = 0; l < (int) str.size(); l = r) {
			while(r < (int) str.size() && str[l] == str[r]) r++;
			if(str[l] == '1') {
				a.push_back(r - l);
			}
		}
		int ans = 0;
		std::sort(a.rbegin(), a.rend());
		for(int i = 0; i < (int) a.size(); i += 2) {
			ans += a[i];
		}
		std::cout << ans << '\n';
	}
}