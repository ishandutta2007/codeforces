#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

#define int long long


int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * b / gcd(a, b); }

main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	int a, b;
	std::cin >> a >> b;
	int mn = n * k + 10, mx = -1;
	for(int rep = 0; rep < 2; rep++) {
		int s, t;
		a = (k - a) % k;
		s = b, t = (k - b) % k;
		s = std::max(a-s, s-a), t = std::max(t-a, a-t);
		s = gcd(s, k), t = gcd(t, k);
		for(int i = 0; i < n; i++) {
			int val1 = (i * k + s);
			val1 = gcd(val1, n * k);
			val1 = val1 == 0 ? 1 : n * k / val1;
			mn = std::min(mn, val1);
			mx = std::max(mx, val1);
			val1 = (i * k + t);
			val1 = gcd(val1, n * k);
			val1 = val1 == 0 ? 1 : n * k / val1;
			mn = std::min(mn, val1);
			mx = std::max(mx, val1);
		}
		assert(mn <= n*k && mx > 0);
	}
	std::cout << mn << ' ' << mx << '\n';
}