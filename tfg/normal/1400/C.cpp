#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int x;
std::string go1(std::string s) {
	int n = (int) s.size();
	std::string w(n, '0');
	for(int i = 0; i < n; i++) {
		if(s[i] == '1' && i + x < n) {
			w[i + x] = '1';
		} if(s[i] == '1' && i - x >= 0) {
			w[i - x] = '1';
		}
	}
	for(int i = 0; i < n; i++) {
		if(s[i] == '0' && i + x < n) {
			w[i + x] = '0';
		} if(s[i] == '0' && i - x >= 0) {
			w[i - x] = '0';
		}
	}
	return w;
}
std::string go2(std::string s) {
	int n = (int) s.size();
	std::string w(n, '0');
	for(int i = 0; i < n; i++) {
		if(s[i] == '1' && i + x < n) {
			w[i + x] = '1';
		} if(s[i] == '1' && i - x >= 0) {
			w[i - x] = '1';
		}
	}
	return w;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		std::string s;
		std::cin >> s >> x;
		//std::cout << s << ", " << go(s) << ", " << go(go(s)) << '\n';
		std::cout << (go2(go1(s)) == s ? go1(s) : "-1") << '\n';
	}
}