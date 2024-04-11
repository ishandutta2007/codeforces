#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

std::string fixLast(std::string str) {
	return str.size() > 10 ? str.substr(0, 5) + "..." + str.substr((int) str.size() - 2, 2) : str;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str;
	std::cin >> str;
	int n = (int) str.size();
	str += char('a' - 1);
	std::vector<int> to(n+1, n);
	std::vector<std::string> ans(n+1);
	std::vector<char> nxt(n+1);
	nxt[n] = nxt[n-1] = str[n];
	ans[n-1] = std::string(1, str[n-1]);
	std::vector<int> size(n+1, 0);
	size[n-1] = 1;
	for(int i = n - 2; i >= 0; i--) {
		// set without skipping
		if(str[i] != str[i+1]) {
			to[i] = i+1;
			ans[i] = fixLast(std::string(1, str[i]) + ans[i+1]);
			nxt[i] = (ans[i+1].empty() || ans[i+1][0] == str[i] ? nxt[i+1] : ans[i+1][0]);
			size[i] = 1 + size[i+1];
			continue;
		}
		to[i] = i+1;
		ans[i] = fixLast(std::string(1, str[i]) + std::string(1, str[i+1]) + ans[i+2]);
		nxt[i] = (ans[i+2].empty() || ans[i+2][0] == str[i] ? nxt[i+2] : ans[i+2][0]);
		size[i] = 2 + size[i+2];
		if(nxt[i] < str[i]) {
			to[i] = i+2;
			ans[i] = ans[i+2];
			nxt[i] = nxt[i+2];
			size[i] = size[i+2];
		}
	}
	for(int i = 0; i < n; i++) {
		std::cout << size[i] << ' ' << ans[i] << '\n';
	}
}