#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	int ans = n;
	for(int l = 0, r = 0; l < n; l = r) {
		while(r < n && a[l] == a[r]) r++;
		if(r < n && a[r] <= a[l] + k) {
			ans -= r - l;
		}
	}
	std::cout << ans << std::endl;
}