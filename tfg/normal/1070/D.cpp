#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	long long last = 0, ans = 0;
	while(n--) {
		long long v;
		std::cin >> v;
		ans += last / k;
		last %= k;
		if(last) {
			long long use = std::min(v, k - last);
			v -= use;
			ans++;
		}
		last = v;
	}
	ans += (last + k - 1) / k;
	std::cout << ans << '\n';
}