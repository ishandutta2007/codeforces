#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	const long long INF = 1e18;
	int n, m;
	long long x, y;
	int k;
	std::cin >> n >> m >> x >> k >> y;
	// spend x to kill k
	std::vector<int> buffer;
	auto solve = [&](int val) {
		int mx = -1;
		for(auto xx : buffer) {
			mx = std::max(mx, xx);
		}
		long long ans = INF;
		if(mx < val) {
			ans = (long long) buffer.size() * y;
		}
		for(int i = 1; i * k <= (int) buffer.size(); i++) {
			ans = std::min(ans, i * x + ((int) buffer.size() - (i * k)) * y);
		}
		buffer.clear();
		//std::cout << "cost is " << ans << '\n';
		return ans;
	};
	long long ans = 0;
	std::vector<int> a(n), b(m);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	int last = 0;
	for(int i = 0, j = 0; i <= n; i++) {
		if(i == n) {
			if(j != m) {
				std::cout << "-1\n";
				return 0;
			}
			ans += solve(last);
			if(ans >= INF) {
				std::cout << "-1\n";
				return 0;
			}
		} else {
			if(j < m && a[i] == b[j]) {
				j++;
				ans += solve(std::max(last, a[i]));
				if(ans >= INF) {
					std::cout << "-1\n";
					return 0;
				}
				last = a[i];
			} else {
				buffer.push_back(a[i]);
			}
		}
	}
	std::cout << ans << '\n';
}