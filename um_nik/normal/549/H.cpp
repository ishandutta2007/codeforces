#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const double INF = 1e20;
double l = 0, r = 1e9;
const int IT = 1000;
double a, b, c, d;

void calc(double x, double y, double s, double &L, double &R)
{
	L = INF, R = -INF;
	for (int i = -1; i <= 1; i += 2)
		for (int j = -1; j <= 1; j += 2)
		{
			double v = (x + i * s) * (y + j * s);
			L = min(L, v);
			R = max(R, v);
		}
	return;
}

bool check(double x)
{
	double l1, l2, r1, r2;
	calc(a, d, x, l1, r1);
	calc(b, c, x, l2, r2);
	return max(l1, l2) <= min(r1, r2);
}

int main()
{
	cin >> a >> b >> c >> d;
	for (int it = 0; it < IT; it++)
	{
		double x = (l + r) / 2;
		if (check(x))
			r = x;
		else
			l = x;
	}
	printf("%.13lf\n", (l + r) / 2);

	return 0;
}