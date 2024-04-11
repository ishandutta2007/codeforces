#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n, k;
		std::string a, b;
		std::cin >> n >> k >> a >> b;
		std::vector<int> f(26, 0);
		for(auto c : a) f[c - 'a']++;
		for(auto c : b) f[c - 'a']--;
		bool good = true;
		int sum = 0;
		for(int i = 0; i < 26; i++) {
			sum += f[i];
			good = good && sum % k == 0 && sum >= 0;
		}
		std::cout << (good ? "YES\n" : "NO\n");
	}
}