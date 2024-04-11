#include <iostream>
#include <vector>
#include <cstdlib>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, cap;
	std::cin >> n >> cap;
	int sum = 0, minSum = 0, maxSum = 0;
	while(n--) {
		int t;
		std::cin >> t;
		sum += t;
		minSum = std::min(sum, minSum);
		maxSum = std::max(sum, maxSum);
	}
	std::cout << std::max(0, cap + 1 - (maxSum - minSum)) << std::endl;
}