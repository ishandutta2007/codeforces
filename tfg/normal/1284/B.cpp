#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a;
	const int ms = 1001000;
	std::vector<int> sum(ms, 0);
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		int l;
		std::cin >> l;
		int mn = 1e9;
		bool good = false;
		std::cin >> mn;
		l--;
		int mx = mn;
		while(l--) {
			int x;
			std::cin >> x;
			good = good || x > mn;
			mn = x;
		}
		if(good) {
			ans += n;
			n--;
			ans += n;
			i--;
		} else {
			a.emplace_back(mn, mx);
			sum[mx]++;
		}
	}
	for(int i = 1; i < ms; i++) {
		sum[i] += sum[i-1];
	}
	for(auto p : a) {
		ans += n - sum[p.first];
	}
	std::cout << ans << '\n';
}