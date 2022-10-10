#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	int n = (int) str.size();
	std::vector<int> ans;
	for(int l = 0, r = n-1; 1; l++, r--) {
		while(l < r && str[l] != '(') l++;
		while(r > l && str[r] != ')') r--;
		if(l >= r) break;
		ans.push_back(l + 1);
		ans.push_back(r + 1);
	}
	std::sort(ans.begin(), ans.end());
	if(ans.empty()) {
		std::cout << "0\n";
	} else {
		std::cout << "1\n";
		std::cout << ans.size() << '\n';
		for(int i = 0; i < (int) ans.size(); i++) {
			std::cout << ans[i] << (i + 1 == (int) ans.size() ? '\n' : ' ');
		}
	}
}