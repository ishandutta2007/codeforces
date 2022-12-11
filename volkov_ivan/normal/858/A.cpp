#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	} else {
		return gcd(b, a % b);
	}
}

int main() {
	long long n, k, k1 = 1;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		k1 *= 10;
	}
	long long x0 = n / gcd(n, k1);
	cout << k1 * x0 << endl;
	return 0;
}