#include<iostream>
using namespace std;
long long gojo(long long a, long long b) {
	long long c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
int main() {
	long long n, i, x[333333], m, p[333333], gcd;
	cin >> n >> m;
	for (i = 0; i < n; i++)
		cin >> x[i];
	for (i = 0; i < m; i++)
		cin >> p[i];
	gcd = x[1] - x[0];
	for (i = 2; i < n; i++)
		gcd = gojo(gcd, x[i] - x[i - 1]);
	for (i = 0; i < m; i++) {
		if (gcd%p[i] == 0) {
			cout << "YES" << endl << x[0] << " " << i + 1 << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
}