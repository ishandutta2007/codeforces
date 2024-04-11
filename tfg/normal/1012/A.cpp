#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::vector<long long> a(2 * n);
	for(int i = 0; i < 2 * n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());
	long long ans = (a[n-1] - a[0]) * (a[2*n-1] - a[n]);
	if(n == 1) ans = 0;
	for(int i = n; i < 2 * n - 1; i++) {
		int right = 2 * n - i - 1;
		int left = i;
		ans = std::min(ans, (a[i] - a[i - (n-1)]) * (a[2*n-1] - a[0]));
		ans = std::min(ans, (a[i] - a[0]) * (a[2*n-1] - a[n-1]));
	}
	std::cout << ans << std::endl;
}