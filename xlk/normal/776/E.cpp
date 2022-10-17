#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
long long n, k;
long long phi(long long x) {
	long long re = x;
	for (long long i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			re = re / i * (i - 1);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		re = re / x * (x - 1);
	}
	return re;
}
int main() {
	cin >> n >> k;
	while (k > 0 && n != 1) {
		n = phi(n);
		k -= 2;
	}
	cout << n % 1000000007 << endl;
	return 0;
}