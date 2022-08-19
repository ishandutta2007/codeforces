#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int IT = 200;
const int N = 100100;
int n;
double k;
double a[N];

bool solve(double x)
{
	double bal = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] >= x)
			bal += k * (a[i] - x);
		else
			bal += a[i] - x;
	}
	return bal >= 0;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%lf", &n, &k);
	k = 1 - k / 100.;
	double l = 0, r = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &a[i]);
		r = max(r, a[i]);
	}
	for (int it = 0; it < IT; it++)
	{
		double x = (l + r) / 2;
		if (solve(x))
			l = x;
		else
			r = x;
	}
	printf("%.12lf\n", r);

	return 0;
}