#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const int me = 20;
	std::vector<int> f(me, 0);
	int n;
	std::cin >> n;
	while(n--) {
		int x;
		std::cin >> x;
		for(int i = 0; i < me; i++) {
			if(x & (1 << i)) {
				f[i]++;
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < me; i++) {
		for(int j = 0; j < me; j++) {
			ans += (1LL << (i + j)) * std::min(f[i], f[j]);
		}
	}
	std::cout << ans << '\n';
}