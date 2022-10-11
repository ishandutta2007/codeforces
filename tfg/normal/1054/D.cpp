#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	int msk = (1 << k) - 1;
	std::map<int, int> freq;
	int x = 0;
	for(int i = 0; i < n; i++) {
		int v;
		std::cin >> v;
		x ^= v;
		//std::cout << "acumulated xor for " << i << " is " << x << ", group is " << std::min(x, x ^ msk) << std::endl;
		freq[std::min(x, x ^ msk)]++;
	}
	long long ans = (long long) n * (n + 1LL) / 2LL;
	//std::cout << "base ans is " << ans << std::endl;
	for(auto v : freq) {
		//std::cout << "for " << v.first << " got " << v.second << "\n";
		long long f1 = v.second / 2;
		long long f2 = v.second - f1;
		// if v.first == 0, eliminates f1 * (f1 + 1) / 2 + f2 * (f2 - 1) / 2
		ans -= f1 * (f1 - 1) / 2 + f2 * (f2 - 1) / 2;
		if(v.first == 0) ans -= f1;
		//std::cout << "now ans is " << ans << std::endl;
	}
	std::cout << ans << std::endl;
}