#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	std::vector<int> freq(26, 0);
	for(auto c : str) freq[c - 'A']++;
	int mx = 0;
	int f = 0;
	for(auto x : freq) {
		if(x > mx) {
			mx = x;
			f = 0;
		}
		if(x == mx) {
			f++;
		}
	}
	const int MOD = 1e9 + 7;
	int ans = 1;
	for(int i = 0; i < n; i++) {
		ans = (long long) ans * f % MOD;
	}
	std::cout << ans << std::endl;
}