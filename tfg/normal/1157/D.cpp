#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const long long INF = 1e10;

long long getMax(long long l, long long r, int n) {
	long long ans = 0;
	while(n > 0) {
		n--;
		ans += r;
		r += r;
		if(ans > INF) {
			return INF;
		}
	}
	return ans;
}

long long getMin(long long l, long long r, int n) {
	return l * n + (long long) n * (n - 1) / 2;
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, k;
	std::cin >> k >> n;
	long long l = 1, r = k;
	for(int i = 0; i < n; i++) {
		while(l != r) {
			long long mid = (l + r + 1) / 2;
			if(getMin(mid, mid, n - i) <= k) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		if(getMax(l, l, n - i) < k || getMin(l, l, n - i) > k) {
			std::cout << "NO\n";
			assert(i == 0);
			return 0;
		}
		if(i == 0) {
			std::cout << "YES\n";
		}
		k -= l;
		std::cout << l << ' ';
		r = 2 * l;
		l = l + 1;
	}
	assert(k == 0);
	std::cout << '\n';
}