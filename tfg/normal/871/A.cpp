#include <iostream>

int a[4] = {0, 9, 6, 15};
int b[4] = {0, 1, 1, 2};

int main() {
	int q;
	std::cin >> q;
	while(q--) {
		int n;
		std::cin >> n;
		int ans = b[n % 4] + (n - a[n % 4]) / 4;
		if(n < a[n % 4]) ans = -1;
		std::cout << ans << std::endl;
	}
}