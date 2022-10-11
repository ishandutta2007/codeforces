#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, m, a, b;
	std::cin >> n >> m >> a >> b;
	std::cout << std::min(n % m * b, (m - n % m) * a) << std::endl;
}