#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
double a, b, c, xs, ys, xt, yt;
double ans, x[2][2], y[2][2];
double Abs(double x)
{
	return x > 0 ? x : -x; 
}
double calc(double A, double B, double C, double D)
{
	return sqrt((A - C) * (A - C) + (B - D) * (B - D));
}
int main()
{
	scanf("%lf%lf%lf", &a, &b, &c);
	scanf("%lf%lf%lf%lf", &xs, &ys, &xt, &yt);
	x[0][0] = xs, y[0][0] = -(xs * a + c) / b;
	x[0][1] = -(ys * b + c) / a, y[0][1] = ys;
	x[1][0] = xt, y[1][0] = -(xt * a + c) / b;
	x[1][1] = -(yt * b + c) / a, y[1][1] = yt;
	ans = Abs(xs - xt) + Abs(ys - yt);
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			ans = min(ans, calc(xs, ys, x[0][i], y[0][i])
				+ calc(x[0][i], y[0][i], x[1][j], y[1][j]) + calc(x[1][j], y[1][j], xt, yt));
		}
	}
	printf("%.10f", ans);
	return 0;
}