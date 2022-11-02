#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const double eps = 1e-9;

double cal(double x, double v, double g) {
	if (v < -eps) {
		return x / -v;
	} else if (v > eps) {
		return (g - x) / v;
	} else {
		return 1e10;
	}
}

int main() {
	double x, y, z, vx, vy, vz, a, b;
	scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &z, &vx, &vz, &vy);
	x = a / 2, y = 0;
	while (z > eps) {
		double tx = cal(x, vx, a), ty = cal(y, vy, b), tz = cal(z, vz, 1e10), t = min(tx, min(ty, tz));
		x += t * vx, y += t * vy, z += t * vz;
		if (tx < ty && tx < tz) {
			vx = -vx;
		} else if (ty < tx && ty < tz) {
			vy = -vy;
		} else if (tz < tx && tz < ty) {
			vz = -vz;
		}
	}
	printf("%.12f %.12f\n", x, y);
	return 0;
}