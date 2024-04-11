#include <iostream>
#include <iomanip>

int dp[20000000];

int main() {
	int n, m;
	std::cin >> n >> m;
	double min = 1e10;
	while(n--) {
		int a, b;
		std::cin >> a >> b;
		min = std::min(min, (double) a / b);
	}
	std::cout << std::fixed << std::setprecision(20) << min * m << '\n';
}