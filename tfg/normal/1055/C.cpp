#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long l[2], r[2], t[2];
	std::cin >> l[0] >> r[0] >> t[0];
	std::cin >> l[1] >> r[1] >> t[1];
	long long g = gcd(t[0], t[1]);
	l[0] += t[0];
	r[0] += t[0];
	l[1] += t[1];
	r[1] += t[1];
	long long ans = 0;
	{
		long long s = l[1]%g + l[0] / g * g;
		if(s > l[0]) {
			s -= g;
		}
		ans = std::max(ans, std::min(r[0], s + r[1]-l[1]) - std::max(l[0], s) + 1);
	}
	{
		long long s = l[0]%g + l[1] / g * g;
		if(s > l[1]) {
			s -= g;
		}
		ans = std::max(ans, std::min(r[1], s + r[0]-l[0]) - std::max(l[1], s) + 1);
	}
	std::cout << ans << std::endl;
}