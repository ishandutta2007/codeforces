#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

struct Point {
	double x, y;

	Point () {}

	Point (double x, double y) : x(x), y(y) {}
};

const double eps = 1e-9;

int sign(double a) {
	return a < -eps ? -1 : a > eps;
}

double cal(Point a, Point b, double pos) {
	double k = (b.y - a.y) / (b.x - a.x);
	return (pos - a.x) * k + a.y;
}

struct Poly {
	vector<Point> p;

	void in(int n) {
		p.clear();
		for (int i = 0; i < n; ++i) {
			int d;
			scanf("%d", &d);
			p.push_back(Point(i, d));
		}
	}

	double area() {
		double ret = 0;
		for (int i = 1; i < (int)p.size(); ++i) {
			ret += (p[i - 1].y + p[i].y) * (p[i].x - p[i - 1].x) / 2;
		}
		return ret;
	}
	
	Poly& merge(const vector<Point> &b) {
		vector<Point> &a = p;
		int i = 0, j = 0;	
		vector<Point> r;	
		r.push_back(Point(0, max(a[i].y, b[j].y)));
		while (i + 1 < a.size() && j + 1 < b.size()) {
			double nowl = r.back().x, nowr = min(a[i + 1].x, b[j + 1].x);	
			double yi1 = cal(a[i], a[i + 1], nowl),
				   yi2 = cal(a[i], a[i + 1], nowr),
				   yj1 = cal(b[j], b[j + 1], nowl),
				   yj2 = cal(b[j], b[j + 1], nowr);
			if (sign(yi1 - yj1) * sign(yi2 - yj2) < 0) {
				double pos = (yj1 - yi1) * (nowr - nowl) / ((yi2 - yi1) - (yj2 - yj1)) + nowl;
				r.push_back(Point(pos, cal(a[i], a[i + 1], pos)));	
			} else {
				r.push_back(Point(nowr, max(yi2, yj2)));
			}
			if (sign(a[i + 1].x - r.back().x) <= 0) {
				++i;
			}
			if (sign(b[j + 1].x - r.back().x) <= 0) {
				++j;
			}
		}
		p = r;
		return *this;
	}
};

int n, k;

int main() {
	scanf("%d%d", &n, &k);
	Poly a, b;
	a.in(k + 1);
	double last = 0;
	printf("%.12f\n", last = a.area());
	for (int i = 1; i < n; ++i) {
		b.in(k + 1);
		double newarea = a.merge(b.p).area();
		printf("%.12f\n", newarea - last);
		last = newarea;
	}
	return 0;
}