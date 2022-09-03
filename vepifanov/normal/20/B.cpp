#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int main () {
	long long a, b, c;
	cin >> a >> b >> c;
	if (a == 0) {
		if (b == 0) printf ("%d\n", -int (c == 0)); else printf ("1\n%.10f\n", -(double)c / b);
	} else {
		long long d = b * b - 4 * a * c;
		if (d < 0) printf ("0\n"); else
		if (d == 0) printf ("1\n%.10f\n", -(b + 0.0) / (2 * a)); else {
			double x = (-b + sqrt (d + 0.0)) / (2 * a);
			double y = (-b - sqrt (d + 0.0)) / (2 * a);
			if (x > y) swap (x, y);
			printf ("2\n%.10f\n%.10f\n", x, y);
		}
	}                           
}