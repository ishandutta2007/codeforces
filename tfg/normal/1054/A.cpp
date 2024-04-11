#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int x, y, z, t1, t2, t3;
	std::cin >> x >> y >> z >> t1 >> t2 >> t3;
	int stairs = abs(x - y) * t1;
	int elev = abs(z - x) * t2 + abs(x - y) * t2 + t3 + t3 + t3;
	//std::cout << stairs << " " << elev << std::endl;
	std::cout << (stairs < elev ? "NO\n" : "YES\n");
}