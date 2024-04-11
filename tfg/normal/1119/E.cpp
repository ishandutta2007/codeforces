#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	long long prv = 0;
	long long same = 0;
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		long long x;
		std::cin >> x;
		{
			// 2-1
			long long use = std::min(prv, x / 2);
			x -= 2 * use;
			prv -= use;
			ans += use;
		}
		{
			// 3
			long long use = x / 3;
			x -= 3 * use;
			ans += use;
		}
		prv += x;
	}
	ans += same;
	std::cout << ans << '\n';
}