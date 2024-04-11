#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int MOD = 1e9 + 7;
	std::string str;
	std::cin >> str;
	std::vector<long long> potS(str.size() + 1, 0);
	auto pot = potS;
	for(int i = 1; i <= (int) str.size(); i++) {
		potS[i] = (potS[i-1] * 10 + 1) % MOD;
		pot[i-1] = (potS[i] - potS[i-1] + MOD) % MOD;
	}
	long long ans = 0, sum = 0;
	for(int i = 0; i < (int) str.size(); i++) {
		sum = (sum * 10 + str[i] - '0') % MOD;
		ans = (ans + potS[(int) str.size() - i - 1] * sum) % MOD;
	}
	sum = 0;
	for(int i = (int) str.size() - 1; i > 0; i--) {
		sum = (sum + (str[i] - '0') * pot[(int) str.size() - i - 1]) % MOD;
		ans = (ans + sum * i) % MOD;
	}
	std::cout << ans << '\n';
}