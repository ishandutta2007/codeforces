#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, k;
		std::cin >> n >> k;
		std::string str;
		std::cin >> str;
		std::vector<std::pair<int, int>> ans;
		int on = 0;
		auto op = [&](int l, int r) {
			ans.emplace_back(l+1, r+1);
			std::reverse(str.begin() + l, str.begin() + r + 1);
		};
		while(k != 1) {
			if(str[on] != '(') {
				int i = on;
				while(str[i] != '(') {
					i++;
				}
				op(on, i);
			}
			on++;
			if(str[on] != ')') {
				int i = on;
				while(str[i] != ')') {
					i++;
				}
				op(on, i);
			}
			on++;
			k--;
		}
		int rest = n - on;
		for(int j = 0; j < rest; j++) {
			if(j < rest / 2) {
				if(str[on] != '(') {
					int i = on;
					while(str[i] != '(') {
						i++;
					}
					op(on, i);
				}
				on++;
			} else {
				if(str[on] != ')') {
					int i = on;
					while(str[i] != ')') {
						i++;
					}
					op(on, i);
				}
				on++;
			}
		}
		std::cout << ans.size() << '\n';
		for(auto p : ans) {
			std::cout << p.first << ' ' << p.second << '\n';
		}
	}
}