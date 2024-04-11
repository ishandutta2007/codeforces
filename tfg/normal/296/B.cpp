#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::string s, t;
	std::cin >> s >> t;
	const int MOD = 1e9 + 7;
	int wtf[4] = {1, 1, 1, 1};
	for(int i = 0; i < n; i++) {
		char c1, c2;
		c1 = s[i];
		c2 = t[i];
		int cur[4];
		cur[3] = 0;
		if(c1 == '?' && c2 == '?') {
			cur[0] = 10;
			cur[1] = cur[2] = 10 * 9 / 2;
		} else if(c1 == '?') {
			cur[0] = 1;
			cur[1] = c2 - '0';
			cur[2] = '9' - c2;
		} else if(c2 == '?') {
			cur[0] = 1;
			cur[1] = '9' - c1;
			cur[2] = c1 - '0';
		} else {
			cur[0] = cur[1] = cur[2] = 0;
			if(c1 < c2) {
				cur[1] = 1;
			} else if(c1 > c2) {
				cur[2] = 1;
			} else {
				cur[0] = 1;
			}
		}
		cur[1] += cur[0];
		cur[3] += cur[2];
		cur[2] += cur[0];
		cur[3] += cur[1];
		for(int j = 0; j < 4; j++) {
			wtf[j] = (long long) cur[j] * wtf[j] % MOD;
		}
	}
	std::cout << ((long long) wtf[3] - wtf[2] - wtf[1] + wtf[0] + 3LL * MOD) % MOD << '\n';
}