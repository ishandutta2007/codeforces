#include<cmath>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Point {
	double x, y;

	Point (double x = 0, double y = 0) : x(x), y(y) {}

	void in() {
		scanf("%lf%lf", &x, &y);
	}

	double len() {
		return sqrt(x * x + y * y);
	}

	double len2() {
		return x * x + y * y;
	}

	Point norm() {
		double l = len();
		return Point(x / l, y / l);
	}
};

double dot(Point a, Point b) {
	return a.x * b.x + a.y * b.y;
}

Point operator + (const Point &a, const Point &b) {
	return Point(a.x + b.x, a.y + b.y);
}

Point operator - (const Point &a, const Point &b) {
	return Point(a.x - b.x, a.y - b.y);
}

Point operator * (const Point &a, const double &k) {
	return Point(a.x * k, a.y * k);
}

double getAns(Point s, Point t, Point w, double vMax) {
	t = t - s;
	Point pw = w - t.norm() * dot(w, t.norm());
	double qw = dot(w, t.norm());
	double v = qw + sqrt(vMax * vMax - pw.len2());
	return t.len() / v;
}

double getAns(Point s, Point t, Point w, double vMax, double len) {
	double l = 0, r = 1e20;
	for (int i = 0; i < 100; ++i) {
		double m = (l + r) / 2;
		Point ss = s + w * m;
		double lent = vMax * m + len;
		if ((t - ss).len() < lent) {
			r = m;
		} else {
			l = m;
		}
	}
	return l;
}

Point s, t, v, w;

double vMax, ti;

int main() {
	s.in();
	t.in();
	if ((s - t).len() < 1e-7) {
		printf("%.12f\n", 0.0);
		return 0;
	}
	scanf("%lf%lf", &vMax, &ti);
	v.in();
	w.in();
	double x;
	if ((x = getAns(s, t, v, vMax)) > ti) {
		s = s + v * ti;
		x = getAns(s, t, w, vMax, vMax * ti) + ti;
	}
	printf("%.12f\n", x);
	return 0;
}