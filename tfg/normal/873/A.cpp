#include <iostream>

int main() {
	int n, k, x;
	std::cin >> n >> k >> x;
	int ans = k * x;
	for(int i = 0; i < n - k; i++) {
		int temp;
		std::cin >> temp;
		ans += temp;
	}
	std::cout << ans << '\n';
}