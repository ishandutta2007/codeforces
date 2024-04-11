#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	long long sum = 0;
	int mx = 0, mx2 = -1;
	for(int i = 0; i < n; i++) {
		int x;
		std::cin >> x;
		sum += x;
		if(x > mx) {
			mx2 = mx;
			mx = x;
		} else if(x > mx2) {
			mx2 = x;
		}
	}
	long long ans = 0;
	bool wtf = false;
	for(int i = 0; i < m; i++) {
		int x;
		std::cin >> x;
		if(x < mx) {
			std::cout << "-1\n";
			return 0;
		}
		if(x == mx) wtf = true;
		//std::cout << "first receives " << sum << " + " << std::max(x - mx, 0) << '\n';
		ans += sum + x - mx;
	}
	if(!wtf) ans += mx - mx2;
	std::cout << ans << '\n';
}