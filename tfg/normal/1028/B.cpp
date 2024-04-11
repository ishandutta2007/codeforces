#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(false); std::cin.tie(NULL);
	int n, m;
	std::cin >> n >> m;
	n = n / 9 + 10;
	m = n;
	std::string a(n, '9');
	std::string b = std::string(m, '9') + std::string(n - 1, '0') + "1";
	std::cout << a << ' ' << b << std::endl;
}