#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		std::string txt;
		std::string ans;
		std::cin >> txt;
		for(auto ch : txt) {
			if(ch == 'B' && !ans.empty() && ans.back() == 'A') {
				ans.pop_back();
			} else {
				ans += ch;
			}
		}
		txt = ans;
		ans = "";
		for(auto ch : txt) {
			if(ch == 'B' && !ans.empty() && ans.back() == 'B') {
				ans.pop_back();
			} else {
				ans += ch;
			}
		}
		std::cout << ans.size() << '\n';
	}
}