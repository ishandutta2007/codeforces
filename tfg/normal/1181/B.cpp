#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	std::vector< std::pair<int, int> > ha;
	for(int i = 1; i < n; i++) {
		if(str[i] != '0') {
			ha.emplace_back(std::max(i, n-i), i);
		}
	}
	std::sort(ha.begin(), ha.end());
	while(ha.size() > 4) ha.pop_back();
	std::string ans(n + 1, '1');
	auto solve = [&](int pos) {
		std::string ans;
		for(int i = pos-1, j = n-1, k = 0; i >= 0 || j >= pos || k > 0; i--, j--, k /= 10) {
			if(i >= 0) {
				k += str[i] - '0';
			}
			if(j >= pos) {
				k += str[j] - '0';
			}
			ans += char('0' + k % 10);
		}
		std::reverse(ans.begin(), ans.end());
		return ans;
	};
	for(auto p : ha) {
		auto got = solve(p.second);
		if(got.size() < ans.size() || (got.size() == ans.size() && got < ans)) {
			ans = got;
		}
	}
	std::cout << ans << '\n';
}