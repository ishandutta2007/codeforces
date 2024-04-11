#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

double lens[10];

const double pi = atan(1.) * 4;

double getV(int n, double x)
{
	double R = x / (2 * sin(pi / n));
	double h = sqrt(x * x - R * R);
	double S = n * (1. / 2. * R * R * sin(2 * pi / n));
	return 1. / 3. * S * h;
}

int main()
{
	scanf("%lf%lf%lf", &lens[3], &lens[4], &lens[5]);
	double V = 0;
	for (int i = 3; i <= 5; i++)
	{
		V += getV(i, lens[i]);
	}
	printf("%.10lf\n", V);
	return 0;
}