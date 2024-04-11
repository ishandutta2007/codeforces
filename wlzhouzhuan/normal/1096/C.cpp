#include <iostream>
#include <math.h>
using namespace std;

int t, n;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	cin >> t;
	while (t--) {
		cin >> n;
		int g = gcd(n, 180);
		int p = 180 / g;
		while (180 * (p - 2) / p < n) p <<= 1;
		cout << p << '\n';
	}
	return 0;
}