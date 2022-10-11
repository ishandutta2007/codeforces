#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int a, b;
	std::cin >> a >> b;
	if(a < b) {
		std::cout << "-1\n";
		return 0;
	}
	if(a == b) {
		std::cout << a << '\n';
		return 0;
	}
	long double ans = 1e12;
	{
		// solve first case
		long long x = a + b;
		long long l = 1, r = (long long) 4e9;
		while(l != r) {
			long long mid = (l + r + 1) / 2;
			// mid is number of peaks
			// 2 * x == length / mid
			// x == length / 2mid
			// length / 2mid >= b
			if(x / mid / 2 / b >= 1) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		ans = std::min(ans, (long double) x / l / 2.0);
	}
	{
		// solve second case
		long long x = a - b;
		long long l = 0, r = (long long) 4e9;
		while(l != r) {
			long long mid = (l + r + 1) / 2;
			// mid is number of peaks
			// 2 * x == length / mid
			if(x / mid / 2 / b >= 1) {
				l = mid;
			} else {
				r = mid - 1;
			}
		}
		if(l > 0) {
			ans = std::min(ans, (long double) x / l / 2.0);
		}
	}
	std::cout << std::fixed << std::setprecision(15) << (double) ans << '\n';
}