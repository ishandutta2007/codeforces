/********************************
 *Copyright (c) 2017 Xu Mingkuan*
 *v1.2     2017.6.16            *
 ********************************/

//basic part
#if 0
{
#endif
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <typeinfo>
#include <cassert>
#include <set>
using namespace std;

typedef long long Di;//can be changed to long double or double (warning: if Di is long long, ANY point without integral coordinates will cause undefined behavior)
typedef double D;//can be changed to long double
int DEFAULT_PREC = 6;
const D EPS = 1e-9, PI = acos((D)-1.0);
const Di INF = 1010101010101010101ll;

//int cmp(T a):     +:1    0:0    - or NaN:-1
inline int cmp(double a)
{
	return a > EPS ? 1 : a >= -EPS ? 0 : -1;
}
inline int cmp(long double a)
{
	return a > EPS ? 1 : a >= -EPS ? 0 : -1;
}
inline int cmp(int a)
{
	return a > 0 ? 1 : !a ? 0 : -1;
}
inline int cmp(long long a)
{
	return a > 0 ? 1 : !a ? 0 : -1;
}
template<class T> inline int cmp(T a, T b)
{
	return cmp(a - b);
}
template<class T> T sqr(T x)
{
	return x * x;
}

inline void inputnum(double &p)
{
	scanf("%lf", &p);
}
inline void inputnum(long double &p)
{
	double tmp;
	scanf("%lf", &tmp);
	p = tmp;
}
inline void inputnum(int &p)
{
	scanf("%d", &p);
}
inline void inputnum(long long &p)
{
//	#ifdef WIN32
//	scanf("%I64d", &p);
//	#else
	scanf("%lld", &p);
//	#endif
}
inline void outputnum(const double &p, int prec = DEFAULT_PREC)
{
	printf("%.*f", prec, p);
}
inline void outputnum(const long double &p, int prec = DEFAULT_PREC)
{
	printf("%.*f", prec, (double)p);
}
inline void outputnum(const int &p, int prec = DEFAULT_PREC)
{
	printf("%d", p);
	if(prec)
		for(printf("."); prec--; printf("0"));
}
inline void outputnum(const long long &p, int prec = DEFAULT_PREC)
{
	#ifdef WIN32
	printf("%I64d", p);
	#else
	printf("%lld", p);
	#endif
	if(prec)
		for(printf("."); prec--; printf("0"));
}

D safeacos(D x)
{
	if(x <= -1)
		return PI;
	if(x >= 1)
		return 0;
	return acos(x);
}

class Point
{
public:
	Di x, y;
	Point(){}
	Point(Di x, Di y): x(x), y(y) {}
	Point operator +(const Point &b) const
	{
		return Point(x + b.x, y + b.y);
	}
	Point operator -(const Point &b) const
	{
		return Point(x - b.x, y - b.y);
	}
	Point operator *(Di b) const
	{
		return Point(x * b, y * b);
	}
	Point operator /(Di b) const
	{
		return Point(x / b, y / b);
	}
	Point &operator +=(const Point &b)
	{
		return *this = *this + b;
	}
	Point &operator -=(const Point &b)
	{
		return *this = *this - b;
	}
	Point &operator *=(Di b)
	{
		return *this = *this * b;
	}
	Point &operator /=(Di b)
	{
		return *this = *this / b;
	}
	bool operator <(const Point &b) const
	{
		return cmp(x, b.x) == 0 ? cmp(y, b.y) < 0 : cmp(x, b.x) < 0;//x == b.x ? y < b.y : x < b.x;
	}
	bool operator >(const Point &b) const
	{
		return b < *this;
	}
	bool operator ==(const Point &b) const
	{
		return cmp(x, b.x) == 0 && cmp(y, b.y) == 0;//x == b.x && y == b.y;
	}
	bool operator <=(const Point &b) const
	{
		return !(*this > b);
	}
	bool operator >=(const Point &b) const
	{
		return !(*this < b);
	}
	bool operator !=(const Point &b) const
	{
		return !(*this == b);
	}
	Di len2() const
	{
		return x * x + y * y;
	}
	D len() const
	{
		return sqrt(len2());
	}
	void read()
	{
		inputnum(x);
		inputnum(y);
	}
	void write(int prec = DEFAULT_PREC) const
	{
		printf("(");
		outputnum(x, prec);
		printf(",");
		outputnum(y, prec);
		printf(") ");
	}
	void writeln(int prec = DEFAULT_PREC) const
	{
		write(prec);
		printf("\n");
	}
	Point unit() const
	{
		return *this / len();
	}
	Point &tounit()
	{
		return *this = *this / len();
	}
	Point normal() const
	{
		return Point(-y, x);
	}
	Point symmetry(const Point &b) const
	{
		return b + b - *this;
	}
	D angle() const
	{
		return atan2(y, x);
	}
	Point rotate(const Point &b) const
	{
		return Point(x * b.x - y * b.y, x * b.y + y * b.x);
	}
	Point rotate(double b) const
	{
		return rotate(Point(cos(b), sin(b)));
	}
	Point &torotate(const Point &b)
	{
		return *this = rotate(b);
	}
	Point &torotate(double b)
	{
		return *this = rotate(b);
	}
};
Point operator *(Di b, const Point &a)
{
	return Point(a.x * b, a.y * b);
}
Point middle(const Point &a, const Point &b)
{
	return (a + b) / 2;
}
Di dot(const Point &a, const Point &b)
{
	return a.x * b.x + a.y * b.y;
}
Di det(const Point &a, const Point &b)
{
	return a.x * b.y - a.y * b.x;
}
bool in_triangle(const Point &a, const Point &b, const Point &c, const Point &p)
{
	return cmp(abs(det(a - p, b - p)) + abs(det(b - p, c - p)) + abs(det(c - p, a - p)), abs(det(a - b, c - b))) == 0;
}
bool convex_tetragon(const Point &a, const Point &b, const Point &c, const Point &d)
{
	Di s[4] = {abs(det(a - b, a - c)), abs(det(b - c, b - d)), abs(det(c - d, c - a)), abs(det(d - a, d - b))};
	return cmp(s[0] + s[1] + s[2], s[3]) != 0 && cmp(s[1] + s[2] + s[3], s[0]) != 0 && cmp(s[2] + s[3] + s[0], s[1]) != 0 && cmp(s[3] + s[0] + s[1], s[2]) != 0;
}
#if 0
}

//line part
{
#endif
class Curve
{
public:
	virtual void read(){}
	virtual void write(int prec = DEFAULT_PREC) const {}
	void writeln(int prec = DEFAULT_PREC) const
	{
		write(prec);
		printf("\n");
	}
	virtual D len() const
	{
		return 0;
	}
};
class Line: public Curve
{
public:
	Point a, b;
	Line(){}
	Line(const Point &a, const Point &b): a(a), b(b) {}
	bool operator <(const Line &l) const
	{
		return a == l.a ? b < l.b : a < l.a;
	}
	bool in_line(const Point &p) const
	{
		return cmp(det(p - a, p - b)) == 0;
	}
	virtual bool contain(const Point &p) const//check if it contains point p which is in the line
	{
		return true;
	}
	void read()
	{
		a.read();
		b.read();
	}
	virtual void write(int prec = DEFAULT_PREC) const
	{
		a.write(prec);
		printf("-- ");
		b.write(prec);
	}
	virtual D len() const
	{
		return INF;
	}
};
class LineSegment: public Line
{
public:
	LineSegment(){}
	LineSegment(const Point &a, const Point &b): Line(a, b) {}
	LineSegment(const Line &a): Line(a) {}
	bool contain(const Point &p) const
	{
		return cmp(dot(p - a, p - b)) <= 0;
	}
	void write(int prec = DEFAULT_PREC) const
	{
		a.write(prec);
		printf("- ");
		b.write(prec);
	}
	D len() const
	{
		return (a - b).len();
	}
};
class Ray: public Line
{
public:
	Ray(){}
	Ray(const Point &a, const Point &b): Line(a, b) {}
	Ray(const Line &a): Line(a) {}
	bool contain(const Point &p) const
	{
		return cmp(dot(p - a, b - a)) >= 0;
	}
	void write(int prec = DEFAULT_PREC) const
	{
		a.write(prec);
		printf("-> ");
		b.write(prec);
	}
};
int intersection(const Line &a, const Line &b, Point &o)
{
	if(cmp(det(a.b - a.a, b.b - b.a)) == 0)
		return 0;
	Di s1 = det(b.b - a.a, b.a - a.a);
	Di s2 = det(b.a - a.b, b.b - a.b);
	o = a.a + (a.b - a.a) * s1 / (s1 + s2);
	return a.contain(o) && b.contain(o);
}
int intersection(const Line &a, const Line &b, Point &p1, Point &p2)
{
	return intersection(a, b, p1);
}
Point projection(const Line &l, const Point &p)
{
	return l.a + dot(p - l.a, l.b - l.a) * (l.b - l.a) / (l.b - l.a).len2();
}
Point symmetry(const Line &l, const Point &p)
{
	return p.symmetry(projection(l, p));
}
int circumcenter(const Point &a, const Point &b, const Point &c, Point &o)
{
	return intersection(Line(middle(a, b), middle(a, b) + (a - b).normal()), Line(middle(b, c), middle(b, c) + (b - c).normal()), o);
}
#if 0
}
#endif
vector<Point> convex_hull(vector<Point> vec)//warning: only for Di being long long; if Di is double, it may cause undefined behavior
{
	if(vec.size() <= 1)
		return vec;
	sort(vec.begin(), vec.end());
	vector<Point> up, down;
	for(int i = 0; i < (int)vec.size(); i++)
	{
		while(up.size() >= 2 && cmp(det(vec[i] - up.back(), *++up.rbegin() - up.back())) >= 0)
			up.pop_back();
		up.push_back(vec[i]);
		while(down.size() >= 2 && cmp(det(vec[i] - down.back(), *++down.rbegin() - down.back())) <= 0)
			down.pop_back();
		down.push_back(vec[i]);
	}
	up.pop_back();
	reverse(up.begin(), up.end());
	up.pop_back();
	down.insert(down.end(), up.begin(), up.end());
//	for(int i = 0; i < down.size(); i++)
//		down[i].write(0);
//	printf("\n");
	return down;
}
int n, m;
vector<Point> a, b;
int main()
{
	scanf("%d%d", &n, &m);
	a.resize(n);
	b.resize(m);
	for(int i = 0; i < n; i++)
		a[i].read();
	for(int i = 0; i < m; i++)
		b[i].read();
	a = convex_hull(a);
	b = convex_hull(b);
	if(a.size() != b.size())
	{
		printf("NO\n");
		return 0;
	}
	n = a.size();
	if(n == 2)
	{
		if((a[1] - a[0]).len2() == (b[1] - b[0]).len2())
			printf("YES\n");
		else
			printf("NO\n");
		return 0;
	}
	a.push_back(a[0]);
	a.push_back(a[1]);
	b.insert(b.end(), b.begin(), b.end());
	b.push_back(b[0]);
	b.push_back(b[1]);
	for(int offset = 0; offset < n; offset++)
	{
		bool ok = true;
		for(int i = 0; i < n && ok; i++)
		{
			if((a[i + 1] - a[i]).len2() != (b[offset + i + 1] - b[offset + i]).len2())
				ok = false;
			if(det(a[i + 2] - a[i + 1], a[i] - a[i + 1]) != det(b[offset + i + 2] - b[offset + i + 1], b[offset + i] - b[offset + i + 1]))
				ok = false;
		}
		if(ok)
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}