#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int a, b, n;
	std::cin >> a >> b >> n;
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		int j = n - i;
		if(i <= a && j <= b) {
			ans++;
		}
	}
	std::cout << ans << '\n';
}