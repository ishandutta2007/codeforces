#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	int ans = 0;
	int got = 0;
	int one = 0;
	while(k--) {
		int x;
		std::cin >> x;
		if(x % 2 != 0) {
			x--;
			one++;
		}
		got += x / 4;
		if(x % 4 == 2) {
			ans++;
		}
	}
	//std::cout << got << ' ' << ans << '\n';
	int use = std::min(n, got);
	got -= use;
	ans += 2 * got;
	got = 0;
	//std::cout << got << ' ' << ans << '\n';
	int wtf = n - use;
	use = wtf;
	use = std::min(use, one);
	one -= use;
	ans += one;
	one = 0;
	use = std::min(2 * ans, wtf - use);
	ans -= use / 2;
	use = wtf;
	use = std::min(use, ans);
	ans -= use;
	//std::cout << got << ' ' << ans << '\n';
	use = std::min(ans, 2 * n);
	ans -= use;
	//std::cout << got << ' ' << ans << '\n';
	if(ans + got != 0) {
		std::cout << "NO\n";
	} else {
		std::cout << "YES\n";
	}
}