#include <iostream>

int main() {
	int n;
	std::cin >> n;
	int count[2];
	count[0] = count[1] = 0;
	while(n--) {
		int x, t;
		std::cin >> x >> t;
		count[x < 0 ? 1 : 0]++;
	}
	std::cout << (std::min(count[0], count[1]) <= 1 ? "Yes\n" : "No\n");
}