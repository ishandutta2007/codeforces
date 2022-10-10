#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	long long ans = 0;
	std::vector<int> a(n);
	long long tot = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		tot += a[i];
	}
	long long cur = 0;
	int get = n/2;
	for(int i = 0; i < get; i++) {
		cur += a[2*i];
	}
	for(int i = 0; i < n; i++) {
		int pos = 2 * i % n;
		ans = std::max(ans, tot - cur);
		cur -= a[pos];
		cur += a[(pos + get*2) % n];
	}
	std::cout << ans << '\n';
}