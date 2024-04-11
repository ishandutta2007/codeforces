#include <iostream>

int a[3030];

int main() {
	int n;
	std::cin >> n;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		std::cin >> a[i];
		for(int j = 0; j < i; j++) {
			if(a[j] > a[i]) {
				ans++;
			}
		}
	}
	if(ans % 2 == 0) {
		std::cout << ans * 2 << '\n';
	} else {
		std::cout << ans * 2 - 1 << '\n';
	}
}