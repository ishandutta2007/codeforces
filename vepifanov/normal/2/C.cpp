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
const double eps = 1e-9;
const double dt = pi / 1000000;

int n;
int m;
int x[3], y[3], r[3];
double d[3];
vector<pair<double, double> > all;

double dist (double x1, double y1, double x2, double y2) {
	return sqrt ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int cross (double x1, double y1, double r1, double x2, double y2, double r2) {
	double d = dist (x1, y1, x2, y2);
	if (d > r1 + r2 + 1e-9) return 0;
	if (min (r1, r2) + d < max (r1, r2) - eps) return 0;
	double A = 2 * (x2 - x1);
	double B = 2 * (y2 - y1);
	double C = x1 * x1 + y1 * y1 - r1 * r1 - x2 * x2 - y2 * y2 + r2 * r2;
	double ax, ay, bx, by;
	if (fabs (A) > eps) {
		ay = 0;
		by = 1;
		ax = -C / A;
		bx = -(B + C) / A;
	} else {
		ax = 0;
		bx = 1;
		ay = -C / B;
		by = -(A + C) / B;
	}
	double dx = bx - ax, dy = by - ay;
	double a = dx * dx + dy * dy;
	double b = (2 * ax * dx - 2 * dx * x1 + 2 * ay * dy - 2 * dy * y1);
	double c = (ax * ax + x1 * x1 - 2 * ax * x1 + ay * ay + y1 * y1 - 2 * ay * y1 - r1 * r1);
	d = b * b - 4 * a * c;
	if (d < -eps) return 0;
	if (fabs (d) < eps) d = 0;
	double t = (-b + sqrt (d)) / (2 * a);
	double xc1, yc1, xc2, yc2;
	xc1 = ax + dx * t;
	yc1 = ay + dy * t;
	t = (-b - sqrt (d)) / (2 * a);
	xc2 = ax + dx * t;
	yc2 = ay + dy * t;
	all.push_back (make_pair (xc1, yc1));
	all.push_back (make_pair (xc2, yc2));
	return 1;
}

int cross (double x1, double y1, double r1, double x2, double y2, double x3, double y3) {
        double ax = x2, ay = y2, bx = x3, by = y3;
	double dx = bx - ax, dy = by - ay;
	double a = dx * dx + dy * dy;
	double b = (2 * ax * dx - 2 * dx * x1 + 2 * ay * dy - 2 * dy * y1);
	double c = (ax * ax + x1 * x1 - 2 * ax * x1 + ay * ay + y1 * y1 - 2 * ay * y1 - r1 * r1);
	double d = b * b - 4 * a * c;
	if (d < -eps) return 0;
	if (fabs (d) < eps) d = 0;
	double t = (-b + sqrt (d)) / (2 * a);
	double xc1, yc1, xc2, yc2;
	xc1 = ax + dx * t;
	yc1 = ay + dy * t;
	t = (-b - sqrt (d)) / (2 * a);
	xc2 = ax + dx * t;
	yc2 = ay + dy * t;
	all.push_back (make_pair (xc1, yc1));
	all.push_back (make_pair (xc2, yc2));
	return 1;
}

int cross (double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
	double a = x2 - x1;
	double b = x3 - x4;
	double c = x3 - x1;
	double d = y2 - y1;
	double e = y3 - y4;
	double f = y3 - y1;
	if (fabs (a * e - b * d) > eps) {
		double t = (c * e - b * f) / (a * e - b * d);
		all.push_back (make_pair (x1 + (x2 - x1) * t, y1 + (y2 - y1) * t));
	}
	return 0;
}

int main() {
	for (int i = 0; i < 3; i++)
		scanf ("%d%d%d", &x[i], &y[i], &r[i]);
	all.clear ();
	if (r[0] == r[1] && r[1] == r[2]) 
		cross ((x[0] + x[1]) / 2.0, (y[0] + y[1]) / 2.0, (x[0] + x[1]) / 2.0 + (y[1] - y[0]), (y[0] + y[1]) / 2.0 - (x[1] - x[0]), (x[2] + x[1]) / 2.0, (y[2] + y[1]) / 2.0, (x[2] + x[1]) / 2.0 + (y[1] - y[2]), (y[2] + y[1]) / 2.0 - (x[1] - x[2]));
	else
	if (r[0] != r[1] && r[1] == r[2]) {
		double x1, y1, r1;
		if (r[0] < r[1]) {
			double k = (double)r[0] / r[1];
			double d = dist (x[0], y[0], x[1], y[1]);
			double d1 = (k * d) / (1 - k);
			double d2 = (k * d) / (1 + k);
			double dd = (d1 - d2) / 2;
			x1 = x[0] - (x[1] - x[0]) / d * dd;
			y1 = y[0] - (y[1] - y[0]) / d * dd;
			r1 = (d1 + d2) / 2;
		} else {
			double k = (double)r[1] / r[0];
			double d = dist (x[1], y[1], x[0], y[0]);
			double d1 = (k * d) / (1 - k);
			double d2 = (k * d) / (1 + k);
			double dd = (d1 - d2) / 2;
			x1 = x[1] + (x[1] - x[0]) / d * dd;
			y1 = y[1] + (y[1] - y[0]) / d * dd;
			r1 = (d1 + d2) / 2;
		}
		cross (x1, y1, r1, (x[2] + x[1]) / 2.0, (y[2] + y[1]) / 2.0, (x[2] + x[1]) / 2.0 + (y[1] - y[2]), (y[2] + y[1]) / 2.0 - (x[1] - x[2]));
	} else
	if (r[0] == r[1] && r[1] != r[2]) {
		double x1, y1, r1;
		if (r[1] < r[2]) {
			double k = (double)r[1] / r[2];
			double d = dist (x[1], y[1], x[2], y[2]);
			double d1 = (k * d) / (1 - k);
			double d2 = (k * d) / (1 + k);
			double dd = (d1 - d2) / 2;
			x1 = x[1] - (x[2] - x[1]) / d * dd;
			y1 = y[1] - (y[2] - y[1]) / d * dd;
			r1 = (d1 + d2) / 2;
		} else {
			double k = (double)r[2] / r[1];
			double d = dist (x[2], y[2], x[1], y[1]);
			double d1 = (k * d) / (1 - k);
			double d2 = (k * d) / (1 + k);
			double dd = (d1 - d2) / 2;
			x1 = x[2] + (x[2] - x[1]) / d * dd;
			y1 = y[2] + (y[2] - y[1]) / d * dd;
			r1 = (d1 + d2) / 2;
		}
		cross (x1, y1, r1, (x[0] + x[1]) / 2.0, (y[0] + y[1]) / 2.0, (x[0] + x[1]) / 2.0 + (y[1] - y[0]), (y[0] + y[1]) / 2.0 - (x[1] - x[0]));
	} else {
		double x1, y1, r1, x2, y2, r2;
		if (r[0] < r[1]) {
			double k = (double)r[0] / r[1];
			double d = dist (x[0], y[0], x[1], y[1]);
			double d1 = (k * d) / (1 - k);
			double d2 = (k * d) / (1 + k);
			double dd = (d1 - d2) / 2;
			x1 = x[0] - (x[1] - x[0]) / d * dd;
			y1 = y[0] - (y[1] - y[0]) / d * dd;
			r1 = (d1 + d2) / 2;
		} else {
			double k = (double)r[1] / r[0];
			double d = dist (x[1], y[1], x[0], y[0]);
			double d1 = (k * d) / (1 - k);
			double d2 = (k * d) / (1 + k);
			double dd = (d1 - d2) / 2;
			x1 = x[1] + (x[1] - x[0]) / d * dd;
			y1 = y[1] + (y[1] - y[0]) / d * dd;
			r1 = (d1 + d2) / 2;
		}
		if (r[1] < r[2]) {
			double k = (double)r[1] / r[2];
			double d = dist (x[1], y[1], x[2], y[2]);
			double d1 = (k * d) / (1 - k);
			double d2 = (k * d) / (1 + k);
			double dd = (d1 - d2) / 2;
			x2 = x[1] - (x[2] - x[1]) / d * dd;
			y2 = y[1] - (y[2] - y[1]) / d * dd;
			r2 = (d1 + d2) / 2;
		} else {  
			double k = (double)r[2] / r[1];
			double d = dist (x[2], y[2], x[1], y[1]);
			double d1 = (k * d) / (1 - k);
			double d2 = (k * d) / (1 + k);
			double dd = (d1 - d2) / 2;
			x2 = x[2] + (x[2] - x[1]) / d * dd;
			y2 = y[2] + (y[2] - y[1]) / d * dd;
			r2 = (d1 + d2) / 2;
		}
		cross (x1, y1, r1, x2, y2, r2);
	}
	double ans = -1e9, ax, ay, xc, yc, good = 0;
	for (int i = 0; i < all.size (); i++) {
		xc = all[i].first;
		yc = all[i].second;
		int ok = 1;
		for (int j = 0; j < 3; j++) {
			d[j] = sqrt ((x[j] - xc) * (x[j] - xc) + (y[j] - yc) * (y[j] - yc));
			if (d[j] < r[j] + eps) ok = 0;
		}
		if (ok) {
			if (fabs (d[0] / r[0] - d[1] / r[1]) < eps && fabs (d[0] / r[0] - d[2] / r[2]) < eps) {
				double cur = asin (r[0] / d[0]);
				if (cur > ans) {
					good = 1;
					ax = xc;
					ay = yc;
					ans = cur;
				}
			}
		}
	}
	if (good) printf ("%.5f %.5f\n", ax, ay);
	return 0;
}