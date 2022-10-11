#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, s;
	std::cin >> n >> s;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	long long ans = 0;
	if(a[n / 2] == s) {

	} else if(a[n / 2] > s) {
		// has to lower it and elements to the left
		for(int i = n / 2; i >= 0; i--) {
			ans += std::max(a[i] - s, 0);
		}
	} else {
		// lower it and right
		for(int i = n / 2; i < n; i++) {
			ans += std::max(s - a[i], 0);
		}
	}
	std::cout << ans << std::endl;
}