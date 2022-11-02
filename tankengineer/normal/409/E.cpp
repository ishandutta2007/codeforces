#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	double x;
	scanf("%lf", &x);
	for (int a = 1; a <= 5000; ++a) {
		for (int h = 1; h <= 5000; ++h) {
			if (fabs(x * sqrt(a * a + 4 * h * h) - a * h) < 1e-5) {
				cout << a << ' ' << h << endl;
				return 0;
			}
		}
	}
	return 0;
}