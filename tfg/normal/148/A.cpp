#include <iostream>
#include <vector>

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n = 4;
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int m;
	std::cin >> m;
	int ans = 0;
	for(int i = 1; i < (1 << n); i++) {
		int g = 1;
		int f = 0;
		for(int j = 0; j < n; j++) {
			if(i & (1 << j)) {
				g = g / gcd(g, a[j]) * a[j];
				f++;
			}
		}
		int cur = m / g;
		ans += (f % 2 == 1 ? 1 : -1) * cur;
	}
	std::cout << ans << std::endl;
}