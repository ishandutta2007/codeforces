#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	int last = -1;
	std::vector<long long> ans(n + 1, 0);
	auto process = [&](int l, int r) {
		if(l == -1 || r == -1 || l == r) return;
		if(l > r) std::swap(l, r);
		l--;r--;
		// for < l it's as usual
		ans[0] += (r - l);
		ans[l] -= (r - l);
		// for == l it's r - 1
		ans[l] += (r - 1) + 1;
		ans[l+1] -= (r - 1) + 1;
		// for between it's as usual - 1
		ans[l+1] += (r - l - 1);
		ans[r] -= (r - l - 1);
		// for r it's l
		ans[r] += l + 1;
		ans[r+1] -= l + 1;
		// last is usual
		ans[r+1] += (r - l);
		ans[n] -= (r - l);
	};
	while(m--) {
		int x;
		std::cin >> x;
		process(last, x);
		last = x;
	}
	for(int i = 0; i < n; i++) {
		if(i) {
			ans[i] += ans[i-1];
		}
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}