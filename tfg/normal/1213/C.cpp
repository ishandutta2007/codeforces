#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		long long n, m;
		std::cin >> n >> m;
		long long tot = 0, ans = 0;
		n /= m;
		for(int i = 0; i < 10; i++) {
			if(i <= n % 10) {
				ans += i * m % 10;
			}
			tot += i * m % 10;
		}
		ans += n / 10 * tot;
		std::cout << ans << '\n';
	}
}