#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int bits(long long x) {
	return x == 0 ? 0 : bits(x / 2) + int(x&1);
}

long long solve() {
	long long l, r;
	std::cin >> l >> r;
	long long pref = 0;
	for(int i = 60; i >= 0; i--) {
		if(((l >> i) & 1) == ((r >> i) & 1)) {
			pref += l & (1LL << i);
		} else {
			long long a = pref + (r & ((1LL << (i + 1)) - 1)), b = pref + ((1LL << i) - 1);
			if(bits(b) >= bits(a)) {
				return b;
			} else {
				return a;
			}
		}
	}
	return pref;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		std::cout << solve() << '\n';
	}
}