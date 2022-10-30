#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = acos(-1);

int x[100050], y[100050];
double a[100050];

int main()
{
	int n;

	cin >> n;

	for (int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		a[i] = atan2(y[i], x[i]);
	}

	sort(a, a+n);

	double m = a[0] + 2 * pi - a[n - 1];
	for (int i = 1; i < n; ++i) {
		m = max(m, a[i] - a[i - 1]);
	}

	printf("%.9f\n", (2 * pi - m) * 180 / pi);

	return 0;
}