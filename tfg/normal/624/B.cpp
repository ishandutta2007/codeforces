#include <iostream>
#include <algorithm>

int a[125];

int main() {
	int n;
	std::cin >> n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a, a + n);
	long long ans = 0;
	for(int i = n - 1, c = 1e9; i >= 0 && c > 0; i--) {
		c = std::min(c, a[i]);
		ans += c;
		c--;
	}
	std::cout << ans << '\n';
}