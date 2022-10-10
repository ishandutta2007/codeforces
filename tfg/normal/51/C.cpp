#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<long long> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	auto check = [&](long long dist) {
		std::vector<long long> ans;
		for(int l = 0, r = 0; l < n; l = r) {
			while(r < n && a[r] - a[l] <= dist) {
				r++;
			}
			ans.push_back((a[r-1] + a[l]));
		}
		return ans;
	};
	long long l = 0, r = 2e9;
	while(l != r) {
		long long mid = (l + r) / 2;
		if((int) check(mid).size() > 3) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	auto ans = check(l);
	std::cout << l / 2 << '.' << l % 2 * 5 << "00000\n";
	while((int) ans.size() < 3) {
		ans.push_back(1);
	}
	for(int i = 0; i < (int) ans.size(); i++) {
		std::cout << ans[i] / 2 << '.' << ans[i] % 2 * 5 << "00000" << (i + 1 == (int) ans.size() ? '\n' : ' ');
	}
}