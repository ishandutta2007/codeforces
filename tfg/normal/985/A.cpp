#include <iostream>
#include <algorithm>

int a[2309];

int main() {
	int n;
	std::cin >> n;
	int cost[2] = {0, 0};
	for(int i = 1; i <= n / 2; i++) {
		std::cin >> a[i];
	}
	std::sort(a + 1, a + n / 2 + 1);
	for(int i = 1; i <= n / 2; i++) {
		cost[0] += abs(a[i] - 2 * i);
		cost[1] += abs(a[i] - 2 * i + 1);
	}
	std::cout << std::min(cost[0], cost[1]);
}