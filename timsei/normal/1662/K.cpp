#include<bits/stdc++.h>
using namespace std;
#define double long double
const double eps = 1e-10, pi = acos(-1);
inline int Dcmp(double x) {
	return x < -eps ? -1 : x > eps ? 1 : 0;
}
struct Point {
	double x, y;
	Point(double x = 0, double y = 0) : x(x), y(y) {}
	inline bool operator == (const Point &rhs) const {
		return !Dcmp(x - rhs.x) && !Dcmp(y - rhs.y);
	}
	inline Point operator + (const Point &rhs) const {
		return Point(x + rhs.x, y + rhs.y);
	}
	inline Point operator - (const Point &rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
	inline double operator * (const Point &rhs) const {
		return x * rhs.x + y * rhs.y;
	}
	inline double operator ^ (const Point &rhs) const {
		return x * rhs.y - y * rhs.x;
	}
	inline Point operator * (const double &k) const {
		return Point(x * k, y * k);
	}
	inline Point operator / (const double &k) const {
		return Point(x / k, y / k);
	}
	inline double len2() {
		return x * x + y * y;
	}
	inline double len() {
		return sqrt(len2());
	}
	inline Point Rotate90() {
		return Point(-y, x);
	}
	inline Point Rotate(const double &rad) {
		return Point(x * cos(rad) - y * sin(rad), x * sin(rad) + y * cos(rad));
	}
}a, b, c;
struct Line {
	Point s, t;
	Line(Point s = Point(), Point t = Point()) : s(s), t(t) {}
};
inline Point LineInter(Line l1, Line l2) {
	double a1 = (l2.t - l2.s) ^ (l1.s - l2.s), a2 = (l2.t - l2.s) ^ (l1.t - l2.s);
	return (l1.s * a2 - l1.t * a1) / (a2 - a1);
}
inline Point FermatPoint(Point a, Point b, Point c) {
	if(a == b)
		return a;
	if(b == c)
		return b;
	if(c == a)
		return c;
	double ab = (b - a).len(), bc = (c - b).len(), ca = (a - c).len();
	double cosa = (b - a) * (c - a) / ab / ca;
	double cosb = (a - b) * (c - b) / ab / bc;
	double cosc = (b - c) * (a - c) / ca / bc;
	double sq3 = pi / 3.0;
// cerr << cosa << " " << cosb << " " << cosc << " " << sq3 << " " << Dcmp((b - a) ^ (c - a)) << endl;
	Point mid;
	if(Dcmp(cosa + 0.5) < 0)
		mid = a;
	else if(Dcmp(cosb + 0.5) < 0)
		mid = b;
	else if(Dcmp(cosc + 0.5) < 0)
		mid = c;
	else if(Dcmp((b - a) ^ (c - a)) < 0)
		mid = LineInter(Line(b, a + (c - a).Rotate(-sq3)), Line(c, a + (b - a).Rotate(sq3)));
		// mid = LineInter(Line(a, b + (c - b).Rotate(sq3)), Line(b, c + (a - c).Rotate(sq3)));
	else
		swap(b, c), mid = LineInter(Line(b, a + (c - a).Rotate(-sq3)), Line(c, a + (b - a).Rotate(sq3)));
	return mid;
}
inline double Calc(Point a, Point b, Point c) {
	Point mid = FermatPoint(a, b, c);
// cerr << "(" << a.x << ", " << a.y << ") (" << b.x << ", " << b.y << ") (" << c.x << ", " << c.y << ") (" << mid.x << ", " << mid.y << ") " << (a - mid).len() + (b - mid).len() + (c - mid).len() << endl;
	return (a - mid).len() + (b - mid).len() + (c - mid).len();	
}
inline double Work(double x, double y) {
	Point p = Point(x, y);
	return max(Calc(a, b, p), max(Calc(a, c, p), Calc(b, c, p)));
}
inline double Solve(double x) {
	double ly = -1e4, ry = 1e4;
	for(int C = 1; C <= 300; ++ C) {
		double mid1 = ly + (ry - ly) / 3, mid2 = ry - (ry - ly) / 3;
		if(Work(x, mid1) > Work(x, mid2))
			ly = mid1;
		else
			ry = mid2;
	}
	return Work(x, ly);
}
int main() {
	scanf("%Lf%Lf%Lf%Lf%Lf%Lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
// cerr << Work(2.3842, 0.4151) << endl;
	double lx = -1e4, rx = 1e4;
	for(int C = 1; C <= 300; ++ C) {
		double mid1 = lx + (rx - lx) / 3, mid2 = rx - (rx - lx) / 3;
		if(Dcmp(Solve(mid1) - Solve(mid2)) > 0)
			lx = mid1;
		else
			rx = mid2;
	}
	printf("%.15Lf\n", Solve(lx));
}