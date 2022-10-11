#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	std::vector<bool> good(n, false);
	for(long long p = 1; p <= (1 << 30); p += p) {
		for(int l = 0, r = n - 1; l < n; l++) {
			while(r > 0 && a[l] + a[r] > p) r--;
			if(a[l] + a[r] == p && l != r) {
				good[l] = good[r] = true;
			}
		}
	}
	int ans = n;
	for(int i = 0; i < n; i++) {
		if(good[i]) {
			ans--;
		}
	}
	std::cout << ans << std::endl;
}