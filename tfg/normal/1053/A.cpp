#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <utility>


int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	long long n, m, k;
	std::cin >> n >> m >> k;
	if(2 * n * m % k != 0) {
		std::cout << "NO\n";
	} else {
		long long area = (2 * n * m / k);
		long long a = area / m;
		if(a * m < area) {
			a++;
		}
		long long b = m;
		long long c = 1;
		long long d = a * b - area;
		//std::cout << "got answer (" << a << ", " << b << "), (" << c << ", " << d << ")\n";
		//std::cout << a * b - c * d << std::endl;
		std::cout << "YES\n";
		std::cout << "0 0\n";
		std::cout << a << " " << d << "\n";
		std::cout << c << " " << b << "\n";
	}
}