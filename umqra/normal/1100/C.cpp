#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

const long double pi = atanl(1.0) * 4;

int main()
{
	double n, r;
	cin >> n >> r;	
	long double angle = 2 * pi / n;
	long double k = 2 * (1 - cosl(angle));
	long double d = (r * k + sqrtl(r * r * k * k + r * r * k * (4 - k))) / (4 - k);
	printf("%.12lf\n", (double)d);
	return 0;
}