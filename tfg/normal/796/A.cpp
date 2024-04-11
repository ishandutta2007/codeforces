#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	int ans = n + n;
	for(int i = 1; i <= n; i++) {
	    int v;
	    std::cin >> v;
	    if(v != 0 && v <= k) {
	        ans = std::min(ans, abs(i - m));
	    }
	}
	std::cout << ans * 10 << '\n';
}