#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

void work(std::vector<int> &a) {
	int n = (int) a.size() - 1;
	for(int i = n-1; i >= 0; i--) {
		a[i] = a[i] ? 1 + a[i+1] : 0;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<int> a(n+1, 0), b(m+1, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	work(a);
	work(b);
	long long ans = 0;
	auto go = [&](int d) {
		int other = 0;
		for(int i = 0; i < n; i++) {
			if(a[i] >= k / d) other++;
		}
		for(int i = 0; i < m; i++) {
			if(b[i] >= d) ans += other;
		}
	};
	for(int d = 1; d * d <= k; d++) {
		if(k % d != 0) continue;
		go(d);
		if(k / d != d) go(k / d);
	}
	std::cout << ans << '\n';
}