#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <set>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

bool isSorted(const std::vector<int> &a) {
	int last = -1;
	for(auto &x : a) {
		if(last > x) return false;
		last = x;
	}
	return true;
}

void solve() {
	int n, x;
	std::cin >> n >> x;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int i = 0, ans = 0;
	while(!isSorted(a)) {
		while(i < n && a[i] <= x) {
			i++;
		}
		if(i == n) {
			ans = -1;
			break;
		}
		std::swap(a[i], x);
		ans++;
	}
	std::cout << ans << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		solve();
	}
}