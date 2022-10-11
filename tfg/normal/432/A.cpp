#include <iostream>

int main() {
	int n, k;
	std::cin >> n >> k;
	int cnt = 0;
	while(n--) {
		int t;
		std::cin >> t;
		if(5 - t >= k) {
			cnt++;
		}
	}
	std::cout << cnt / 3 << '\n';
}