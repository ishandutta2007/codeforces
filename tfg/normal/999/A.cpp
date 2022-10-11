#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, k;
	std::cin >> n >> k;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int ans = 0;
	for(int l = 0, r = n - 1; l <= r; ) {
		if(a[l] <= k) {
			ans++;
			l++;
		} else if(a[r] <= k) {
			ans++;
			r--;
		} else {
			break;
		}
	}
	std::cout << ans << std::endl;
}