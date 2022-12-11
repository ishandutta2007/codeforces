#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long double ld;
const ld eps = 1e-9;
const ld pi = atanl(1.) * 4;

bool Eq(ld a, ld b)
{
	return fabs(a - b) < eps;
}

bool Ls(ld a, ld b)
{
	return a < b && !Eq(a, b);
}

ld mySqrt(ld x)
{
	if (Ls(x, 0))
		return 0;
	return sqrtl(x);
}

struct Point
{
	ld x, y;
	Point () : x(), y() {}
	Point (ld _x, ld _y) : x(_x), y(_y) {}
	Point operator + (const Point &a) const
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const
	{
		return Point(x - a.x, y - a.y);
	}
	ld operator * (const Point &a) const
	{
		return x * a.y - y * a.x;
	}
	ld operator % (const Point &a) const
	{
		return x * a.x + y * a.y;
	}
	ld length() const
	{
		return mySqrt(*this % *this);
	}
	Point operator / (ld k) const
	{
		return Point(x / k, y / k);
	}
	Point operator * (ld k) const
	{
		return Point(x * k, y * k);
	}
	Point norm() const
	{
		return *this / length();
	}
	Point rotate(ld alpha)
	{
		return rotate(sinl(alpha), cosl(alpha));
	}
	Point rotate(ld sina, ld cosa)
	{
		return Point(x * cosa - y * sina, x * sina + y * cosa);
	}

	void scan()
	{
		double _x, _y;
		scanf("%lf%lf", &_x, &_y);
		x = _x;
		y = _y;
	}
	void print()
	{
		printf("%.10lf %.10lf\n", (double)x, (double)y);
	}
};

ld getArea(vector <Point> p)
{
	ld area = 0;
	for (int i = 1; i < (int)p.size(); i++)
	{
		area += (p[i] - p[0]) * (p[(i + 1) % (int)p.size()] - p[0]);
	}
	return area;
}

vector <Point> orient(vector <Point> p)
{
	ld area = getArea(p);
	if (area > 0)
		return p;
	reverse(p.begin(), p.end());
	return p;
}

int main()
{
	Point P, v;
	P.scan();
	v.scan();
	ld a, b, c, d;
	scanf("%Lf%Lf%Lf%Lf", &a, &b, &c, &d);

	v = v.norm();
	Point A1 = v * b;
	Point A2 = v.rotate(pi / 2) * (a / 2);
	Point A3 = v.rotate(pi / 2) * (c / 2);
	Point A4 = A3 - v * d;
	Point A5 = v.rotate(pi * 3 / 2) * (c / 2) - v * d;

	Point A6 = v.rotate(pi * 3 / 2) * (c / 2);
	Point A7 = v.rotate(pi * 3 / 2) * (a / 2);

	(A1 + P).print();
	(A2 + P).print();
	(A3 + P).print();
	(A4 + P).print();
	(A5 + P).print();
	(A6 + P).print();
	(A7 + P).print();


	return 0;
}