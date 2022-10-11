#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	if(n <= 2) {
		std::cout << "0\n";
		return 0;
	}
	std::vector<int> a(n);
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	int ans = 1e9;
	for(int i = -1; i <= 1; i++) {
		for(int j = -1; j <= 1; j++) {
			int cost = 0;
			int first = a[0] + i;
			int second = a[1] - a[0] - i + j;
			for(int k = 0; k < n; k++) {
				if(abs(first + second * k - a[k]) > 1) {
					//std::cout << "for " << first << ", " << second << " broke on " << k << std::endl;
					cost = 1e9;
					break;
				}
				if(first + second * k != a[k]) cost++;
			}
			ans = std::min(ans, cost);
		}
	}
	if(ans > n) ans = -1;
	std::cout << ans << std::endl;
}