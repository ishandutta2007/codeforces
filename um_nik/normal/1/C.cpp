#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

const double PI = 4 * atan(1);

const double eps = 1e-5;
bool eq(double x, double y)
{
	return fabs(x - y) < eps;
}
bool ls(double x, double y)
{
	return x < y && !eq(x, y);
}
bool lseq(double x, double y)
{
	return x < y || eq(x, y);
}

bool isInt(double x)
{
	int xx = (int)(x + eps);
	return eq(x, xx);
}

struct Point
{
	double x, y;

	Point() : x(), y() {}
	Point (double _x, double _y) : x(_x), y(_y) {}

	void scan()
	{
		scanf("%lf%lf", &x, &y);
	}
	void print()
	{
		printf("(%.5lf %.5lf)\n", x, y);
	}

	Point operator + (const Point &a) const
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const
	{
		return Point(x - a.x, y - a.y);
	}
	Point operator * (const double &k) const
	{
		return Point(x * k, y * k);
	}
	Point operator / (const double &k) const
	{
		return Point(x / k, y / k);
	}
	double operator % (const Point &a) const
	{
		return x * a.x + y * a.y;
	}
	double operator * (const Point &a) const
	{
		return x * a.y - y * a.x;
	}
	double sqrLen() const
	{
		return *this % *this;
	}
	double len() const
	{
		return sqrt(sqrLen());
	}
	Point norm() const
	{
		return *this / len();
	}
	Point ort() const
	{
		return Point(-y, x);
	}
};

bool intersectLines(Point A, Point a, Point B, Point b, Point &M)
{
	if (eq(a * b, 0)) return false;
	double y = ((A - B) * a) / (b * a);
	M = B + b * y;
	return true;
}

double getAngle(Point v, Point u)
{
	return atan2(v * u, v % u);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	Point A, B, C;
	A.scan();
	B.scan();
	C.scan();
	Point D = (A + B) / 2;
	Point d = (B - A).ort();
	Point E = (A + C) / 2;
	Point e = (C - A).ort();
	Point O;
	if (!intersectLines(D, d, E, e, O)) throw;
//	O.print();
	A = O - A;
	B = O - B;
	C = O - C;
	double R = A.len();
	double a1 = fabs(getAngle(A, B));
	double a2 = fabs(getAngle(A, C));
	for (int n = 3; n <= 200; n++)
	{
		double ang = 2 * PI / n;
		if (!isInt(a1 / ang) || !isInt(a2 / ang)) continue;
		printf("%.13lf\n", n * R * R * sin(ang) / 2);
		return 0;
	}
	throw;

	return 0;
}