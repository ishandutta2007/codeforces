#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long x, s;
	std::cin >> x >> s;
	if(s < x || x % 2 != s % 2) {
		std::cout << "-1\n";
	} else if(x == s) {
		if(x == 0) {
			std::cout << "0\n";
		} else {
			std::cout << "1\n" << x << '\n';
		}
	} else {
		std::vector<long long> a(2, 0);
		const int me = 61;
		for(int i = me; i >= 0; i--) {
			long long b = 1LL << i;
			if(b <= x && b <= s) {
				a[0] ^= b;
				x ^= b;
				s -= b;
			}
		}
		for(int i = me; i >= 0; i--) {
			long long b = 1LL << i;
			if(!(b & a[0]) && ((2*b) & s)) {
				a[0] ^= b;
				a[1] ^= b;
				s -= b*2;
			}
		}
		if(s == x && x == 0) {
			std::cout << "2\n" << a[0] << ' ' << a[1] << '\n';
		} else {
			s += a[0] + a[1];
			x ^= a[0] ^ a[1];
			a.resize(3);
			a[0] = x;
			s -= x;
			x = 0;
			assert(s % 2 == 0);
			a[1] = s / 2;
			a[2] = s / 2;
			std::cout << "3\n" << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
		}
	}
}