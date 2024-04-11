#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long f(long long x) {
	if(x <= 9) {
		return x;
	}
	x -= 9;
	long long p = 10;
	while(x > p / 10 * 9) {
		x -= (p / 10) * 9;
		p *= 10;
	}
	//std::cout << "power is " << p << "\n";
	int i = 1;
	while(x > p/10) {
		x -= p/10;
		i++;
	}
	return i * (p + 1) + (x - 1) * 10;
}

long long g(long long x) {
	long long l = 0, r = 2e17;
	while(l != r) {
		long long mid = (l + r + 1) / 2;
		if(f(mid) > x) {
			r = mid - 1;
		} else {
			l = mid;
		}
	}
	return l;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long l, r;
	std::cin >> l >> r;
	std::cout << g(r) - g(l-1) << '\n';
}