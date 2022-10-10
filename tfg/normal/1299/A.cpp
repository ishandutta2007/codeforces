#include <iostream>
#include <vector>
#include <chrono>
#include <random>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> pref(n+1, 0);
	std::vector<int> suf(n+1, 0);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for(int i = 0; i < n; i++) {
		pref[i+1] = pref[i] | a[i];
		suf[n-i-1] = suf[n-i] | a[n-i-1];
	}
	int ans[2] = {-1, -1};
	for(int i = 0; i < n; i++) {
		int x = pref[i] | suf[i+1];
		int cur = (a[i] | x) - x;
		if(cur > ans[0]) {
			ans[0] = cur;
			ans[1] = i;
		}
	}
	std::swap(a[0], a[ans[1]]);
	for(int i = 0; i < n; i++) {
		std::cout << a[i] << (i+1 == n ? '\n' : ' ');
	}
	//std::cout << ans[0] << std::endl;
}