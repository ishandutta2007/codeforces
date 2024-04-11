#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <bitset>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::string str;
	std::cin >> n >> str;
	std::vector<int> mask(n + 1, 0);
	std::vector<int> a;
	std::vector<int> f(26, 0);
	for(auto c : str) {
		while(mask[f[c-'a']] & (1 << (c-'a'))) {
			f[c-'a']++;
		}
		a.push_back(f[c-'a'] + 1);
		if(a.back() >= 3) {
			std::cout << "NO\n";
			return 0;
		}
		mask[f[c-'a']] |= (1 << (c-'a')) - 1;
	}
	std::cout << "YES\n";
	for(int i = 0; i < n; i++) {
		std::cout << a[i] - 1;
	}
	std::cout << std::endl;
}