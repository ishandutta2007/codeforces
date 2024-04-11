#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

double myPow(double x, int k)
{
	if (k == 0)
		return 1;
	if (k & 1)
		return myPow(x, k - 1) * x;
	double t = myPow(x, k / 2);
	return t * t;
}

int main()
{
	int n, t;
	scanf("%d%d", &n, &t);
	double x = 1.000000011;
	x = myPow(x, t);
	printf("%.10lf\n", x * n);
	return 0;
}