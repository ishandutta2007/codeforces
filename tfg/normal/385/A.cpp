#include <iostream>

int a[1010];

int main() {
	int n, c;
	std::cin >> n >> c;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		if(i) {
			ans = std::max(ans, a[i - 1] - a[i] - c);
		}
	}
	std::cout << ans << '\n';
}