/********************************
 *Copyright (c) 2017 Xu Mingkuan*
 *v1.1.3   2017.4.13            *
 ********************************/
//class: Point, Line, LineSegment, Ray; Circle, Arc; Figure; GeneralLine, Convex; Point3D, Ball;
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

typedef double Di;//can be changed to long double or long long (warning: if Di is long long, ANY point without integral coordinates will cause undefined behavior)
typedef double D;//can be changed to long double
int DEFAULT_PREC = 6;
const D EPS = 1e-9, PI = acos((D)-1.0);
const Di INF = 1e150;
template<class T> inline int cmp(T a);//+:1    0:0    - or NaN:-1
template<> inline int cmp(double a)
{
	return a > EPS ? 1 : a >= -EPS ? 0 : -1;
}
template<> inline int cmp(long double a)
{
	return a > EPS ? 1 : a >= -EPS ? 0 : -1;
}
template<> inline int cmp(int a)
{
	return a > 0 ? 1 : !a ? 0 : -1;
}
template<> inline int cmp(long long a)
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

template<class T> inline void inputnum(T &p);
template<class T> inline void outputnum(const T &p, int prec = DEFAULT_PREC);
template<> inline void inputnum(double &p)
{
	scanf("%lf", &p);
}
template<> inline void inputnum(long double &p)
{
	double tmp;
	scanf("%lf", &tmp);
	p = tmp;
}
template<> inline void inputnum(int &p)
{
	scanf("%d", &p);
}
template<> inline void inputnum(long long &p)
{
	#ifdef WIN32
	scanf("%I64d", &p);
	#else
	scanf("%lld", &p);
	#endif
}
template<> inline void outputnum(const double &p, int prec)
{
	printf("%.*f", prec, p);
}
template<> inline void outputnum(const long double &p, int prec)
{
	printf("%.*f", prec, (double)p);
}
template<> inline void outputnum(const int &p, int prec)
{
	printf("%d", p);
	if(prec)
		for(printf("."); prec--; printf("0"));
}
template<> inline void outputnum(const long long &p, int prec)
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

class Line;
class LineSegment;
class Ray;
class Circle;
class Arc;
class Line
{
public:
	Point a, b;
	Line(){}
	Line(const Point &a, const Point &b): a(a), b(b) {}
	Line(const LineSegment &l);
	Line(const Ray &l);
	Line(const Circle &o) {assert(0);}//can't convert
	bool contain(const Point &) const//for convenience
	{
		return true;
	}
	void write(int prec = DEFAULT_PREC) const
	{
		a.write(prec);
		printf("-- ");
		b.write(prec);
	}
	void writeln(int prec = DEFAULT_PREC) const
	{
		write(prec);
		printf("\n");
	}
};
class LineSegment
{
public:
	Point a, b;
	LineSegment(){}
	LineSegment(const Point &a, const Point &b): a(a), b(b) {}
	LineSegment(const Line &l);
	LineSegment(const Ray &l);
	bool contain(const Point &p) const//check if it contains point p which is in the line
	{
		return cmp(dot(p - a, p - b)) <= 0;
	}
	bool operator <(const LineSegment &r) const
	{
		return a == r.a ? b < r.b : a < r.a;
	}
	void write(int prec = DEFAULT_PREC) const
	{
		a.write(prec);
		printf("- ");
		b.write(prec);
	}
	void writeln(int prec = DEFAULT_PREC) const
	{
		write(prec);
		printf("\n");
	}
};
class Ray
{
public:
	Point a, b;//a -> b
	Ray(){}
	Ray(const Point &a, const Point &b): a(a), b(b) {}
	Ray(const Line &l);
	Ray(const LineSegment &l);
	bool contain(const Point &p) const//check if it contains point p which is in the line
	{
		return cmp(dot(p - a, b - a)) >= 0;
	}
	void write(int prec = DEFAULT_PREC) const
	{
		a.write(prec);
		printf("-> ");
		b.write(prec);
	}
	void writeln(int prec = DEFAULT_PREC) const
	{
		write(prec);
		printf("\n");
	}
};
Line::Line(const LineSegment &l): a(l.a), b(l.b) {}
Line::Line(const Ray &l): a(l.a), b(l.b) {}
LineSegment::LineSegment(const Line &l): a(l.a), b(l.b) {}
LineSegment::LineSegment(const Ray &l): a(l.a), b(l.b) {}
Ray::Ray(const Line &l): a(l.a), b(l.b) {}
Ray::Ray(const LineSegment &l): a(l.a), b(l.b) {}
int intersection(const Line &a, const Line &b, Point &o)
{
	if(cmp(det(a.b - a.a, b.b - b.a)) == 0)
		return 0;
	Di s1 = det(b.b - a.a, b.a - a.a);
	Di s2 = det(b.a - a.b, b.b - a.b);
	o = a.a + (a.b - a.a) * s1 / (s1 + s2);
	return 1;
}
template<class T1, class T2> int intersection(const T1 &a, const T2 &b, Point &o)//T1 and T2 are Line/LineSegment/Ray
{
	if(intersection(Line(a), Line(b), o))
		return a.contain(o) && b.contain(o);
	else
		return 0;
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
template<class T> bool isLine()
{
	return typeid(T) == typeid(Line) || typeid(T) == typeid(LineSegment) || typeid(T) == typeid(Ray);
}

class Circle
{
public:
	Point o;
	Di r;
	Circle(){}
	Circle(const Point &o, Di r): o(o), r(r) {}
	Circle(const Arc &a);
	Circle(const Line &l) {assert(0);}//can't convert
	D area() const
	{
		return PI * r * r;
	}
	bool contain(const Point &) const//for convenience
	{
		return true;
	}
	void read()
	{
		o.read();
		inputnum(r);
	}
	void write(int prec = DEFAULT_PREC) const
	{
		printf("o=");
		o.write(prec);
		printf("r=");
		outputnum(r, prec);
		printf(" ");
	}
	void writeln(int prec = DEFAULT_PREC) const
	{
		write(prec);
		printf("\n");
	}
};
class Arc
{
public:
	Point a, b;//a---(counter-clockwise)-->b
	Circle o;
	Arc(){}
	Arc(const Point &a, const Point &b, const Circle &o): a(a), b(b), o(o) {}
	D len() const
	{
		D ret = safeacos(1 - (D)(a - b).len2() / (2 * o.r * o.r));
		return (det(a - o.o, b - o.o) >= 0 ? ret : 2 * PI - ret) * o.r;
	}
	D CircularSector_area() const
	{
		return len() * o.r / 2;
	}
	D CircularSegment_area() const
	{
		return (len() * o.r - det(a - o.o, b - o.o)) / 2;
	}
	bool contain(const Point &p) const//check if it contains point p which is on the circle
	{
		return cmp(det(a - p, b - p)) <= 0;
	}
	void write(int prec = DEFAULT_PREC) const
	{
		o.write(prec);
		a.write(prec);
		printf("-> ");
		b.write(prec);
	}
	void writeln(int prec = DEFAULT_PREC) const
	{
		write(prec);
		printf("\n");
	}
	Di getminx() const
	{
		return min(a.x, b.x);
	}
	Di getmaxx() const
	{
		return max(a.x, b.x);
	}
};
Circle::Circle(const Arc &a) {*this = a.o;}
int intersection(const Circle &o, const Line &l, Point &p1, Point &p2)
{
	Point h = projection(l, o.o);
	Di tmp = o.r * o.r - (h - o.o).len2();
	int tmp1 = cmp(tmp);
	if(tmp1 == -1)
		return 0;
	else if(tmp1 == 0)
	{
		p1 = h;
		return 1;
	}
	else
	{
		p1 = l.a - l.b;
		p1 *= sqrt(tmp / p1.len2());
		p2 = h - p1;
		p1 += h;
		return 2;
	}
}
int intersection(const Line &l, const Circle &o, Point &p1, Point &p2)
{
	return intersection(o, l, p1, p2);
}
int intersection(const Circle &o1, const Circle &o2, Point &p1, Point &p2)
{
	if(o2.o == o1.o)
		return 0;
	D tmp1 = ((o2.o - o1.o).len2() + o1.r * o1.r - o2.r * o2.r) / (2 * (o2.o - o1.o).len());
	D tmp2 = o1.r * o1.r - tmp1 * tmp1;
	int tmp3 = cmp(tmp2);
	if(tmp3 == -1)
		return 0;
	else if(tmp3 == 0)
	{
		p1 = o1.o + (o2.o - o1.o).unit() * tmp1;
		return 1;
	}
	else
	{
		Point h = o1.o + (o2.o - o1.o).unit() * tmp1;
		p1 = (o2.o - o1.o).unit().normal() * sqrt(tmp2);
		p2 = h - p1;
		p1 += h;
		return 2;
	}
}
template<class T1, class T2> int intersection(const T1 &o, const T2 &l, Point &p1, Point &p2)//T1 and T2 are Line/LineSegment/Ray/Circle/Arc
{
	int tmp;
	if(isLine<T1>())
	{
		if(isLine<T2>())
			tmp = intersection(Line(o), Line(l), p1);
		else
			tmp = intersection(Circle(l), Line(o), p1, p2);
	}
	else
	{
		if(isLine<T2>())
			tmp = intersection(Circle(o), Line(l), p1, p2);
		else
			tmp = intersection(Circle(o), Circle(l), p1, p2);
	}
	bool tmp1 = tmp >= 1 && o.contain(p1) && l.contain(p1);
	bool tmp2 = tmp == 2 && o.contain(p2) && l.contain(p2);
	if(tmp1)
		return (int)tmp2 + 1;
	else if(tmp2)
	{
		p1 = p2;
		return 1;
	}
	else
		return 0;
}
int tangent(const Circle &o, const Point &a, Point &p1, Point &p2)
{
	D tmp = (o.o - a).len2();
	if(cmp(tmp, (D)o.r * o.r) == -1)
		return 0;
	Point h = o.o + (a - o.o) * (o.r * o.r / tmp);
	tmp = o.r * o.r - (h - o.o).len2();
	int tmp1 = cmp(tmp);
	if(tmp1 == -1)
		return 0;
	else if(tmp1 == 0)
	{
		p1 = h;
		return 1;
	}
	else
	{
		p1 = (a - o.o).unit().normal() * sqrt(tmp);
		p2 = h - p1;
		p1 += h;
		return 2;
	}
}
int tangent(const Point &a, const Circle &o, Point &p1, Point &p2)
{
	return tangent(o, a, p1, p2);
}
template<class T> int tangent(const T &o, const Point &a, Point &p1, Point &p2)//T is Arc
{
	int tmp = tangent(Circle(o), a, p1, p2);
	bool tmp1 = tmp >= 1 && o.contain(p1);
	bool tmp2 = tmp == 2 && o.contain(p2);
	if(tmp1)
		return (int)tmp2 + 1;
	else if(tmp2)
	{
		p1 = p2;
		return 1;
	}
	else
		return 0;
}
template<class T> int tangent(const Point &a, const T &o, Point &p1, Point &p2)//T is Arc
{
	return tangent(o, a, p1, p2);
}
template<class T> int tangent_external(const Circle &o1, const Circle &o2, T &l1, T &l2)//T is Line/LineSegment
{
	if(o1.o == o2.o)
		return 0;
	D sinalpha = (o1.r - o2.r) / (o1.o - o2.o).len();
	int tmp = cmp(fabs(sinalpha), (D)1);
	if(tmp == 1)
		return 0;
	else if(tmp == 0)
	{
		l1.a = l1.b = (o1.r > o2.r ? o1.o + (o2.o - o1.o).unit() * o1.r : o2.o + (o1.o - o2.o).unit() * o2.r);
		return 1;
	}
	else
	{
		D cosalpha = sqrt(1 - sqr(o1.r - o2.r) / (o1.o - o2.o).len2());
		Point u = (o2.o - o1.o).unit();
		Point p = u * sinalpha + u.normal() * cosalpha;
		l1 = T(o1.o + p * o1.r, o2.o + p * o2.r);
		p = u * sinalpha - u.normal() * cosalpha;
		l2 = T(o1.o + p * o1.r, o2.o + p * o2.r);
		return 2;
	}
}
template<class T1, class T2, class T3> int tangent_external(const T1 &o1, const T2 &o2, T3 &l1, T3 &l2)//T1 and T2 are Circle/Arc, T3 is Line/LineSegment
{
	int tmp = tangent_external(Circle(o1), Circle(o2), l1, l2);
	bool tmp1 = tmp >= 1 && o1.contain(l1.a) && o2.contain(l1.b);
	bool tmp2 = tmp == 2 && o1.contain(l2.a) && o2.contain(l2.b);
	if(tmp1)
		return (int)tmp2 + 1;
	else if(tmp2)
	{
		l1 = l2;
		return 1;
	}
	else
		return 0;
}
template<class T> int tangent_internal(const Circle &o1, const Circle &o2, T &l1, T &l2)//T is Line/LineSegment
{
	if(o1.o == o2.o)
		return 0;
	D sinalpha = (o1.r + o2.r) / (o1.o - o2.o).len();
	int tmp = cmp(fabs(sinalpha), (D)1);
	if(tmp == 1)
		return 0;
	else if(tmp == 0)
	{
		l1.a = l1.b = o1.o + (o2.o - o1.o).unit() * o1.r;
		return 1;
	}
	else
	{
		D cosalpha = sqrt(sqr(o1.r - o2.r) - (o1.o - o2.o).len2());
		Point u = (o2.o - o1.o).unit();
		Point p = u * sinalpha + u.normal() * cosalpha;
		l1 = T(o1.o + p * o1.r, o2.o - p * o2.r);
		p = u * sinalpha - u.normal() * cosalpha;
		l2 = T(o1.o + p * o1.r, o2.o - p * o2.r);
		return 2;
	}
}
template<class T1, class T2, class T3> int tangent_internal(const T1 &o1, const T2 &o2, T3 &l1, T3 &l2)//T1 and T2 are Circle/Arc, T3 is Line/LineSegment
{
	int tmp = tangent_internal(Circle(o1), Circle(o2), l1, l2);
	bool tmp1 = tmp >= 1 && o1.contain(l1.a) && o2.contain(l1.b);
	bool tmp2 = tmp == 2 && o1.contain(l2.a) && o2.contain(l2.b);
	if(tmp1)
		return (int)tmp2 + 1;
	else if(tmp2)
	{
		l1 = l2;
		return 1;
	}
	else
		return 0;
}
template<class T1, class T2, class T3> int tangent(const T1 &o1, const T2 &o2, T3 &l1, T3 &l2, T3 &l3, T3 &l4)//T1 and T2 are Circle/Arc, T3 is Line/LineSegment
{
	int tmpa = tangent_internal(o1, o2, l1, l2);
	int tmpb = tangent_external(o1, o2, l3, l4);
	if(tmpa == 2)
		return tmpb + 2;
	else if(tmpa == 1)
	{
		l2 = l3;
		l3 = l4;
		return tmpb + 1;
	}
	else
	{
		l1 = l3;
		l2 = l4;
		return tmpb;
	}
}
int circumcircle(const Point &a, const Point &b, const Point &c, Circle &o)
{
	if(!intersection(Line(middle(a, b), middle(a, b) + (a - b).normal()), Line(middle(b, c), middle(b, c) + (b - c).normal()), o.o))
		return 0;
	o.r = (o.o - a).len();
	return 1;
}
template<class T> bool isCurve()
{
	return typeid(T) == typeid(Circle) || typeid(T) == typeid(Arc);
}

const int MAXN = 1010;
int n;
Circle a[MAXN];
int father[MAXN], height[MAXN];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		a[i].read();
	memset(father, 0, sizeof(father));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(a[j].r > a[i].r && (a[i].o - a[j].o).len2() < a[j].r * a[j].r && (!father[i] || a[j].r < a[father[i]].r))
				father[i] = j;
	memset(height, -1, sizeof(height));
	for(int i = 1; i <= n; i++)
		if(!father[i])
			height[i] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(height[father[j]] != -1)
				height[j] = height[father[j]] + 1;
	double ans = 0;
	for(int i = 1; i <= n; i++)
	{
//		printf("%d %d %d %f\n", i, father[i], height[i], a[i].area());
		if(height[i] == 0 || height[i] % 2 == 1)
			ans += a[i].area();
		else
			ans -= a[i].area();
	}
	printf("%.12f\n", ans);
	return 0;
}