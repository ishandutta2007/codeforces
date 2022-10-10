#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	std::string ans(10, '0');
	for(auto v : str) {
		if(v == 'L') {
			int on = 0;
			while(ans[on] == '1') on++;
			ans[on] = '1';
		} else if(v == 'R') {
			int on = 9;
			while(ans[on] == '1') on--;
			ans[on] = '1';
		} else {
			ans[v-'0'] = '0';
		}
	}
	std::cout << ans << '\n';
}