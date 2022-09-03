#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

const double pi = asin (1.0) * 2;

int n;
int m;

int cross (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double *xc, double *yc) {
	double a = x2 - x1;
	double b = x3 - x4;
	double c = x3 - x1;
	double d = y2 - y1;
	double e = y3 - y4;
	double f = y3 - y1;
	double t = (c * e - b * f) / (a * e - b * d);
	*xc = x1 + (x2 - x1) * t;
	*yc = y1 + (y2 - y1) * t;
	return 0;
}

double calc (double x1, double y1, double x2, double y2) {
	double ang = atan2 (y1, x1) - atan2 (y2, x2);
	if (ang < -1e-6) ang += 2 * pi;
	return ang;
}

int main() {
	double x1, y1, x2, y2, x3, y3;
	scanf ("%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3);
	double d;
	if (fabs (x1 - x2) < 1e-6 && fabs (y1 - y2) < 1e-6) {
		d = sqrt ((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
		printf ("%.10f\n", sqrt (3.0) * d * d / 4);	
		return 0;
	}
	if (fabs (x1 - x3) < 1e-6 && fabs (y1 - y3) < 1e-6) {
		d = sqrt ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
		printf ("%.10f\n", sqrt (3.0) * d * d / 4);	
		return 0;
	}
	if (fabs (x3 - x2) < 1e-6 && fabs (y3 - y2) < 1e-6) {
		d = sqrt ((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));
		printf ("%.10f\n", sqrt (3.0) * d * d / 4);	
		return 0;
	}
	double cx1 = (x1 + x2) / 2;
	double cy1 = (y1 + y2) / 2;
	double cx2 = (x2 + x3) / 2;
	double cy2 = (y2 + y3) / 2;
	double dx1 = (x2 - x1);
	double dy1 = (y2 - y1);
	double dx2 = (x3 - x2);
	double dy2 = (y3 - y2);
	double xc, yc;
	cross (cx1, cy1, cx1 - dy1, cy1 + dx1, cx2, cy2, cx2 - dy2, cy2 + dx2, &xc, &yc);
	double a1 = calc (x1 - xc, y1 - yc, x2 - xc, y2 - yc);
	double a2 = calc (x2 - xc, y2 - yc, x3 - xc, y3 - yc);
	double a3 = calc (x3 - xc, y3 - yc, x1 - xc, y1 - yc);
	if (a1 + a2 + a3 > 3 * pi) {
		a1 = 2 * pi - a1;
		a2 = 2 * pi - a2;
		a3 = 2 * pi - a3;
	}
	double ans = 1e10;
	double r = sqrt ((x1 - xc) * (x1 - xc) + (y1 - yc) * (y1 - yc));
	for (int i = 3; i <= 100; i++) {
		double a = 2 * pi / i;
		int i1 = -1, i2 = -1, i3 = -1;
		for (int j = 0; j <= i; j++) {
			if (fabs (a * j - a1) < 1e-6) i1 = j;
			if (fabs (a * j - a2) < 1e-6) i2 = j;
			if (fabs (a * j - a3) < 1e-6) i3 = j;
		}
		if (i1 != -1 && i2 != -1 && i3 != -1 && i1 + i2 + i3 == i) {
			double cur = sin (a) * r * r * i / 2;
			if (cur < ans) ans = cur;
		}
	}
	printf ("%.10f\n", ans);
	return 0;
}