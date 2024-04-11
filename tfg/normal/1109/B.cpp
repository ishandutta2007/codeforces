#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int solve(std::string str) {
	int n = (int) str.size();
	bool valid = false;
	for(int i = 0; i < n / 2; i++) {
		valid = valid || str[i] != str[0];
	}
	if(!valid) {
		return -1;
	}
	for(int i = 1; i < n; i++) {
		std::string s = str.substr(i, n - i) + str.substr(0, i);
		std::string r = s;
		std::reverse(r.begin(), r.end());
		if(s == r && s != str) {
			return 1;
		}
	}
	return 2;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	int ans = solve(str);
	if(ans == -1) {
		std::cout << "Impossible\n";
	} else {
		std::cout << ans << '\n';
	}
}