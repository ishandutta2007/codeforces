#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cmath>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int a, b;
	std::cin >> a >> b;
	for(int x = 1, y = 0; x < a; x++) {
		while(x * x + y * y < a * a) {
			y++;
		}
		while(x * x + y * y > a * a) {
			y--;
		}
		if(x * x + y * y == a * a) {
			//std::cout << "found with " << x << ", " << y << "\n";
			int g = gcd(x, y);
			int x2 = x / g;
			int y2 = y / g;
			int s = sqrt((b * b) / (double)(x2 * x2 + y2 * y2)) + 0.5;
			x2 *= s;
			y2 *= s;
			std::swap(x2, y2);
			//std::cout << "s is " << s << ", rest is " << x2 << ", " << y2 << "\n";
			if(x2 <= 0 || y2 <= 0 || x2 * x2 + y2 * y2 != b * b) {
				continue;
			}
			if(x - x2 != 0 && y + y2 != 0) {
				std::cout << "YES\n";
				std::cout << "0 0\n";
				std::cout << x << ' ' << y << "\n";
				std::cout << x - x2 << ' ' << y + y2 << "\n";
				return 0;
			}
			x2 *= -1;
			y2 *= -1;
			if(x - x2 != 0 && y + y2 != 0) {
				std::cout << "YES\n";
				std::cout << "0 0\n";
				std::cout << x << ' ' << y << "\n";
				std::cout << x - x2 << ' ' << y + y2 << "\n";
				return 0;
			}
		}
	}
	std::cout << "NO\n";
}