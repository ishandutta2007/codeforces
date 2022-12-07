#include <bits/stdc++.h>

using namespace std;

long long sum(long long x) {
	long long res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main() {
	int t; 
	cin >> t;
	while (t--) {
		long long n;
		cin >> n;
		while (__gcd(n, sum(n)) == 1) n++;
		cout << n << "\n";
	}
	return 0;
}