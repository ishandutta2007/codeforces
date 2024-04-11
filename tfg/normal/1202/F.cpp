#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long a, b;
	std::cin >> a >> b;
	long long ans = 0;
	long long n = a + b;
	for(long long l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		long long g = n / l;
		if(g > a || g > b) continue;
		// a - g * x <= x
		// a <= x * (g + 1)
		// x >= a / (g + 1)
		long long al = (a + g) / (g + 1);
		long long bl = (b + g) / (g + 1);
		// a - g * x >= 0
		// a >= g * x
		// x <= a / g
		long long ar = a / g;
		long long br = b / g;
		if(al > ar || bl > br) continue;
		long long mn = al + bl;
		long long mx = ar + br;
		mn = std::max(mn, l);
		mx = std::min(mx, r);
		ans += std::max(0LL, mx-mn+1);
	}
	std::cout << ans << '\n';
}