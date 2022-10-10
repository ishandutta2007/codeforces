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
	long long m;
	std::cin >> m;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	long long sum = 0;
	long long ans[2] = {-1, -1};
	for(int l = 0, r = 0; l < n; l++) {
		while(r < n && (r + 1LL - l) * a[r] - (sum + a[r]) <= m) {
			sum += a[r++];
		}
		if(r - l > ans[0]) {
			ans[0] = r - l;
			ans[1] = a[r-1];
		}
		sum -= a[l];
	}
	std::cout << ans[0] << ' ' << ans[1] << '\n';
}