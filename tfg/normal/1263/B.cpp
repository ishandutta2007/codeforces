#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<std::string> a, b;
		std::vector<bool> wtf;
		for(int i = 0; i < n; i++) {
			std::string str;
			std::cin >> str;
			bool valid = true;
			for(auto x : b) {
				valid = valid && x != str;
			}
			if(valid) {
				b.push_back(str);
				wtf.push_back(true);
			} else {
				b.push_back(str);
				wtf.push_back(false);
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			std::string str = b[i];
			bool valid = wtf[i];
			if(valid) {
				a.push_back(str);
				continue;
			}
			for(int j = 0; j < 4; j++) {
				for(char c = '0'; c <= '9'; c++) {
					valid = true;
					auto cur = str;
					cur[j] = c;
					for(auto x : a) {
						valid = valid && x != cur;
					}
					for(int ii = 0; ii < n; ii++) {
						valid = valid && (!wtf[ii] || b[ii] != cur);
					}
					if(valid) {
						str = cur;
						break;
					}
				}
				if(valid) break;
			}
			assert(valid);
			a.push_back(str);
			ans++;
		}
		std::cout << ans << '\n';
		for(auto x : a) {
			std::cout << x << '\n';
		}
	}
}