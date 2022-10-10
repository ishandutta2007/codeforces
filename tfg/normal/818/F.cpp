#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int q;
	std::cin >> q;
	while(q--) {
		long long n;
		std::cin >> n;
		if(n == 1) {
			std::cout << "0\n";
			continue;
		}
		long long l = 1, r = n-1;
		long long ans = 0;
		while(l != r) {
			long long mid = (l + r + 1) / 2;
			long long inClique = mid * (mid - 1) / 2;
			long long bridges = n - 1 - (mid - 1);
			long long tot = inClique + bridges;
			if(tot <= bridges * 2) {
				l = mid;
				ans = tot;
			} else {
				r = mid - 1;
			}
		}
		// try with +1
		long long mid = l;
		long long inClique = mid * (mid - 1) / 2;
		long long bridges = n - 1 - (mid - 1);
		long long tot = inClique + bridges;
		ans = tot;
		mid++;
		bridges--;
		inClique++;
		inClique++;
		tot++;
		if(tot <= bridges * 2) {
			tot += bridges * 2 - tot;
			ans = std::max(ans, tot);
		}
		std::cout << ans << '\n';
	}
}