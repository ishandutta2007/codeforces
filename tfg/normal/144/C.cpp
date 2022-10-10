#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	std::string str, pat;
	std::cin >> str >> pat;
	if(pat.size() > str.size()) {
		std::cout << "0\n";
		return 0;
	}
	std::vector<int> f(26, 0);
	int g = 0;
	auto go = [&](char c, int x) {
		if(c != '?') f[c - 'a'] += x;
		else g += x;
	};
	for(int i = 0; i < (int) pat.size(); i++) {
		go(str[i], 1);
		go(pat[i], -1);
	}
	int ans = 0;
	for(int i = 0; i + (int) pat.size() <= (int) str.size(); i++) {
		int sum = 0;
		for(int j = 0; j < 26; j++) sum += std::min(f[j], 0);
		if(-sum == g) ans++;
		if(i + (int) pat.size() < (int) str.size()) {
			go(str[i], -1);
			go(str[i + (int) pat.size()], 1);
		}
	}
	std::cout << ans << '\n';
}