#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;

double R, D, r, d, k;
double pw2(double x) {return x * x;}
double dist_r(double x1, double y1, double x2, double y2) {
	double l1 = pw2(d)/(pw2(x1) + pw2(y1)), l2 = pw2(d)/(pw2(x2) + pw2(y2));
	x1 *= l1, y1 *= l1, x2 *= l2, y2 *= l2;
	return sqrt(pw2(x1 - x2) + pw2(y1 - y2));
}

void solve() {
	scanf("%lf%lf%lf", &R, &r, &k), D = 2*R, d = 2*r;
	double pd = dist_r(D, 0, d, 0), pr = pd / 2;
	double x0 = d - pr, y0 = k*pd, l0 = sqrt(pw2(x0) + pw2(y0));
	double dx = x0/l0*pr, dy = y0/l0*pr;
	printf("%.9f\n", dist_r(x0 + dx, y0 + dy, x0 - dx, y0 - dy) / 2);
}

int main() {
	int t; scanf("%d", &t);
	while( t-- ) solve();
}