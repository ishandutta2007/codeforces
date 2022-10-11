#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n, a, b;
	std::cin >> n >> a >> b;
	std::cout << (a - 1 + b % n + n) % n + 1;
}