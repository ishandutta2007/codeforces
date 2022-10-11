#include <iostream>

int gcd(int a, int b) {
	if(!b) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int main() {
	int n;
	std::cin >> n;
	int max = 0;
	int g = 0;
	for(int i = 0; i < n; i++) {
		int t;
		std::cin >> t;
		g = gcd(t, g);
		max = std::max(max, t);
	}
	if((max / g - n % 2) % 2 == 1) {
		std::cout << "Alice\n";
	} else {
		std::cout << "Bob\n";
	}
	//
}