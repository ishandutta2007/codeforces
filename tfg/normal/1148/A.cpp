#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long a, b, c;
	std::cin >> a >> b >> c;
	long long ans = 2 * c;
	long long use = std::min(a, b);
	ans += 2 * use;
	a -= use;
	b -= use;
	if(a || b) {
		ans++;
	}
	std::cout << ans << '\n';
}