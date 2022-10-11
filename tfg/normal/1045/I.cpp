#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	long long ans = 0;
	std::cin >> q;
	std::map<int, int> freq;
	while(q--) {
		std::string str;
		std::cin >> str;
		int msk = 0;
		for(auto c : str) {
			msk ^= 1 << (c - 'a');
		}
		for(int i = 0; i < 26; i++) {
			if(freq.count(msk ^ (1 << i))) ans += freq[msk ^ (1 << i)];
		}
		ans += freq[msk]++;
	}
	std::cout << ans << '\n';
}