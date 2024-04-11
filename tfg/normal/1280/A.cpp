#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void solve() {
	int x;
	std::string str;
	std::cin >> x >> str;
	const long long MOD = 1e9 + 7;
	long long r = (int) str.size();
	long long ans = 0;
	for(int i = 1; i <= x && i <= (int) str.size(); i++) {
		ans++;
		r--;
		int use = std::max(0, x - (int) str.size());
		use = std::min(use, (int) str.size() - i);
		auto wtf = str.substr(i, use);
		for(int j = 1; j < str[i-1] - '0'; j++) str += wtf;
		//std::cout << str << std::endl;
		r = (long long) (str[i-1] - '0') * r % MOD;
	}
	//std::cout << str << std::endl;
	std::cout << (r + ans) % MOD << std::endl;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}