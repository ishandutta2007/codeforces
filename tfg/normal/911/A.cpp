#include <iostream>

int a[100100];

int main() {
	int min = 1e9 + 1;
	int n;
	std::cin >> n;
	int ans = n;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		min = std::min(min, a[i]);
	}
	int cur = - 2 * n;
	for(int i = 0; i < n; i++) {
		if(a[i] == min) {
			//std::cout << "on " << i << ", " << i - cur;
			ans = std::min(ans, i - cur);
			cur = i;
		}
	}
	std::cout << ans << '\n';
}