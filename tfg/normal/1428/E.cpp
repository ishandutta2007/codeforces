#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <queue>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	auto getCost = [&](int x, int f) {
		// dividing x by f
		assert(x >= f);
		int x0 = x / f;
		int x1 = x0 + 1;
		int f1 = x % f;
		int f0 = f - f1;
		return (long long) x0 * x0 * f0 + (long long) x1 * x1 * f1;
	};
	auto delta = [&](int x, int f) {
		return getCost(x, f) - getCost(x, f+1);
	};
	std::vector<int> a(n), f(n, 1);
	std::priority_queue<std::pair<long long, int>> hp;
	/*for(int kek = 1; kek <= 1000; kek++) {
		for(int wut = 1; wut+1 < kek; wut++) {
			assert(delta(kek, wut) >= delta(kek, wut+1));
		}
	}*/
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(a[i] != 1) {
			hp.push({delta(a[i], 1), i});
		}
	}
	for(int rep = n; rep < k; rep++) {
		assert(!hp.empty());
		int on = hp.top().second;
		hp.pop();
		f[on]++;
		if(f[on] != a[on]) {
			assert(delta(a[on], f[on]-1) >= delta(a[on], f[on]));
			hp.push({delta(a[on], f[on]), on});
		}
	}
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		ans += getCost(a[i], f[i]);
	}
	std::cout << ans << '\n';
}