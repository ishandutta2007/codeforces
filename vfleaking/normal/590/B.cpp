#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

double solve(double a, double b, double c)
{
	double d = sqrt(b * b - 4 * a * c);
	double x1 = (-b - d) / (2 * a), x2 = (-b + d) / (2 * a);
	if (0 < x1)
		return 0;
	if (0 < x2)
		return x2;
	return 0;
}

int main()
{
	double x1, y1, x2, y2;
	double vm, t;
	double vx, vy, wx, wy;
	double dx, dy;

	cin >> x1 >> y1 >> x2 >> y2;
	cin >> vm >> t;
	cin >> vx >> vy >> wx >> wy;

	dx = x2 - x1, dy = y2 - y1;

	double x;
	x = solve(vm * vm - vx * vx - vy * vy, 2 * (vx * dx + vy * dy), -dx * dx - dy * dy);

	if (x > t)
	{
		double qx = t * wx - t * vx + dx;
		double qy = t * wy - t * vy + dy;
		x = solve(vm * vm - wx * wx - wy * wy, 2 * (wx * qx + wy * qy), -qx * qx - qy * qy);
		if (x < t)
			x = t;
	}
	printf("%.10f\n", x);

	return 0;
}