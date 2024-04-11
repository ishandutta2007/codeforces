#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, z;
	std::cin >> n >> z;
	std::vector<int> a(n);
	std::vector<bool> got(n, false);
	int ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	for(int i = 0, j = n / 2; i < n; i++) {
		if(got[i]) {
			continue;
		}
		while(j < n && (a[j] - a[i] < z || got[j])) {
			j++;
		}
		if(j < n) {
			ans++;
			got[i] = got[j] = true;
		}
	}
	std::cout << ans << '\n';
}