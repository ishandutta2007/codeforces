#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int ans = 0;
	for(int i = 1; i + i <= n; i++) {
		if((n - i) % i == 0) {
			ans++;
		}
	}
	std::cout << ans << '\n';
}