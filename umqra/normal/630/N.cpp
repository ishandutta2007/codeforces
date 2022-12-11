#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c;
	scanf("%lf%lf%lf", &a, &b, &c);
	double D = sqrt(b * b - 4 * a * c);
	double x1 = (-b - D) / (2 * a);
	double x2 = (-b + D) / (2 * a);
	if (x1 > x2)
		swap(x1, x2);
	printf("%.10lf\n%.10lf\n", x2, x1);
	return 0;
}