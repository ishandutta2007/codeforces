#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <map>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int ms = 1001000;
	std::vector<int> group(ms, 1);
	std::vector<bool> prime(ms, true);
	for(int i = 2; i < ms; i++) {
		if(!prime[i]) continue;
		for(int j = i; j < ms; j += i) {
			prime[j] = false;
			int e = 0, x = j;
			while(x % i == 0) {
				x /= i, e++;
			}
			if(e % 2) {
				group[j] *= i;
			}
		}
	}
	int t;
	std::cin >> t;
	std::vector<int> f(ms, 0);
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<int> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i];
			a[i] = group[a[i]];
			f[a[i]]++;
		}
		int best[2] = {0, 0};
		for(auto x : a) {
			if(f[x]) {
				best[0] = std::max(best[0], f[x]);
				if(x == 1 || f[x] % 2 == 0) {
					best[1] += f[x];
				}
				f[x] = 0;
			}
		}
		best[1] = std::max(best[1], best[0]);
		int q;
		std::cin >> q;
		while(q--) {
			long long x;
			std::cin >> x;
			std::cout << best[x != 0] << '\n';
		}
	}
}