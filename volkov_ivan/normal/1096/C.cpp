#include <iostream>
#include <cmath>

using namespace std;

const long double eps = 1e-6;

bool ok(long double x) {
	return abs(round(x) - x) < eps;
}

int main() {
	int t;
	cin >> t;
	for (int it = 0; it < t; it++) {
		int n;
		cin >> n;
		for (int i = 3; i <= 360; i++) {
			long double alpha = ((long double) (i - 2)) / i * 180;
			long double one = alpha / (i - 2);
			bool flag = 0;
			for (int j = 1; j <= i - 2; j++) {
				if (ok(one * j) && round(one * j) == n) {
					cout << i << endl;
					flag = 1;
				}
			}
			if (flag) break;
		}
	}
	return 0;
}