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
	int f[2] = {0, 0};
	int wtf = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] != t[i]) {
			int pos = s[i] - '0';
			if(pos == 1) wtf++;
			else wtf--;
			if(f[1-pos]) {
				f[1-pos]--;
			}
			f[pos]++;
		}
	}
	std::cout << (wtf != 0 ? -1 : f[0] + f[1]) << '\n';
}