#include <cstdio>
#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int ans = 0;
	while(n--) {
		int d;
		scanf("%i", &d);
		ans = std::max(ans, std::min(d - 1, 1000000 - d));
	}
	std::cout << ans << '\n';
}