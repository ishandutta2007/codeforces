#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, L, t;
	std::cin >> n >> L >> t;
	t *= 2;
	long long ans = 0;
	{
		int use = t / L;
		ans += (n-1LL) * (long long) n * use;
		t -= use * L;
	}
	std::vector<int> a(2*n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i+n] = a[i] + L;
	}
	for(int l = 0, r = 0; l < n; l++) {
		while(r - l < n && (a[r] - a[l]) <= t) {
			r++;
		}
		ans += r - l - 1;
	}
	std::cout << ans / 4 << "." << (ans % 4 * 100) / 4 << '\n';
}