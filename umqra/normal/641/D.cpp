#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int N = 100100;
int n;
double a[N], b[N];
double ans[2][N];

double sqr(double x)
{
	return x * x;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%lf", &b[i]);
	double A = 0, B = 1;
	for (int i = 0; i < n - 1; i++)
	{
		A += a[i];
		B -= b[i];
		double D = sqr(B - A - 1) - 4 * A;
		if (D < 0)
			D = 0;
		D = sqrt(D);
		double C = 1 + A - B;
		ans[0][i] = (C - D) / 2;
		ans[1][i] = (C + D) / 2;
	}
	ans[0][n - 1] = 1;
	ans[1][n - 1] = 1;
	for (int k = 0; k < 2; k++)
	{
		for (int i = 0; i < n; i++)
			printf("%.10lf ", ans[k][i] - (i == 0 ? 0 : ans[k][i - 1]));
		printf("\n");
	}
	return 0;
}