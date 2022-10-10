#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::string s, t;
	std::cin >> s >> t;
	std::vector<int> wtf(n, 0);
	for(int i = 0; i < n; i++) {
		wtf[i] = s[i] - 'a' + t[i] - 'a';
	}
	for(int i = n-1; i > 0; i--) {
		while(wtf[i] >= 26) {
			wtf[i] -= 26;
			wtf[i-1]++;
		}
	}
	int r = 0;
	for(int i = 0; i < n; i++) {
		wtf[i] += r * 26;
		r = wtf[i] % 2;
		wtf[i] /= 2;
		std::cout << char(wtf[i] + 'a');
	}
	assert(r == 0);
	std::cout << '\n';
}