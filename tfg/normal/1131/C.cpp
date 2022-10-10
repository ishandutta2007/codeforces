#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	/*auto check = [&](int x) {
		
	};
	int l = 0, r = 1e9;
	while(l != r) {
		int mid = (l + r) / 2;
		if(check(mid).empty()) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	std::vector<int> ans = check(l);*/
	std::vector<int> ans;
	for(int i = 0; i + 1 < n; i += 2) {
		ans.push_back(a[i]);
	}
	ans.push_back(a.back());
	for(int i = (n-2) - (n%2==0?1:0); i > 0; i -= 2) {
		ans.push_back(a[i]);
	}
	for(int i = 0; i < n; i++) {
		std::cout << ans[i] << (i + 1 == n ? '\n' : ' ');
	}
}