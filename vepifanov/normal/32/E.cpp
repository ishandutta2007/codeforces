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

#define re return
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef double D;

template<class T> T abs(T x) {
	re x > 0 ? x : -x;
}

int n;
int m;
double ax, ay;

bool cross (D x1, D y1, D x2, D y2, D x3, D y3, D x4, D y4, bool col) {
	D a = x2 - x1;
	D b = x3 - x4;
	D c = x3 - x1;
	D d = y2 - y1;
	D e = y3 - y4;
	D f = y3 - y1;
	if (fabs (a * e - b * d) > 1e-7) {
		double t = (c * e - b * f) / (a * e - b * d);
		double s = (a * f - c * d) / (a * e - b * d);
		if (t > -1e-7 && t < 1 + 1e-7 && s > -1e-7 && s < 1 + 1e-7) {
			ax = x1 + (x2 - x1) * t;
			ay = y1 + (y2 - y1) * t;
			re true;
		}
	} else if (col) re (x1 - x3) * (x2 - x3) + (y1 - y3) * (y2 - y3) < -1e-7;
	re false;
}

int main() {
        double xv, yv, xp, yp, x1, y1, x2, y2, x3, y3, x4, y4;
        scanf ("%lf%lf%lf%lf", &xv, &yv, &xp, &yp);
        scanf ("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        scanf ("%lf%lf%lf%lf", &x3, &y3, &x4, &y4);
        
        if (!cross (xv, yv, xp, yp, x1, y1, x2, y2, true) && !cross (xv, yv, xp, yp, x3, y3, x4, y4, false)) printf ("YES\n"); else {
        	double dx = xp - x3, dy = yp - y3;
        	double px = x4 - x3, py = y4 - y3;
        	double dd = sqrt (sqr (px) + sqr (py));
        	double t = (dx * py - dy * px) / dd;
        	double xw = xp - py * t / dd * 2, yw = yp + px * t / dd * 2;
        	if (cross (xv, yv, xw, yw, x3, y3, x4, y4, false)) {
        		xw = ax;
        		yw = ay;
	        	if (!cross (xv, yv, xw, yw, x1, y1, x2, y2, true) && !cross (xw, yw, xp, yp, x1, y1, x2, y2, true)) printf ("YES\n"); else printf ("NO\n");
        	} else printf ("NO\n");
        }

	return 0;
}