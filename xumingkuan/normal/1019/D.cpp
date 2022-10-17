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
	#ifdef WIN32
	scanf("%I64d", &p);
	#else
	scanf("%lld", &p);
	#endif
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
#endif

const int MAXN = 2020;
const int MAXM = 4040404;
int n;
long long S;
pair<Point, int> a[MAXN];
pair<Point, pair<int, double> > b[MAXM];
int pos[MAXN];
int bn = 0;
bool cmp_angle(const pair<Point, pair<int, double> > &a, const pair<Point, pair<int, double> > &b)
{
	return a.second.second < b.second.second;
}
Point nowvec;
bool cmp_nowvec(const pair<Point, int> &a, const pair<Point, int> &b)
{
	return det(nowvec, a.first) < det(nowvec, b.first);
}
void found(int p1, int p2, int p3)
{
	printf("Yes\n");
	printf("%d %d\n", (int)a[p1].first.x, (int)a[p1].first.y);
	printf("%d %d\n", (int)a[p2].first.x, (int)a[p2].first.y);
	printf("%d %d\n", (int)a[p3].first.x, (int)a[p3].first.y);
	exit(0);
}
int rr()
{
	return (rand() & 32767) << 15 ^ (rand() & 32767);
}
int main()
{
//	n = 2000;
//	S = 1010101010101010ll;
	scanf("%d", &n);
	scanf("%I64d", &S);
	S *= 2;//det
	for(int i = 1; i <= n; i++)
	{
//		a[i].first.x = rr() % 2000000001 - 1000000000;
//		a[i].first.y = rr() % 2000000001 - 1000000000;
		a[i].first.read();
		a[i].second = i;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i; j++)
		{
			b[++bn] = make_pair(a[i].first - a[j].first, make_pair(i * MAXN + j, (a[i].first - a[j].first).angle()));
			b[++bn] = make_pair(a[j].first - a[i].first, make_pair(j * MAXN + i, (a[j].first - a[i].first).angle()));
		}
	sort(b + 1, b + bn + 1, cmp_angle);
	b[0] = b[bn];
	nowvec = b[0].first + b[1].first;
	sort(a + 1, a + n + 1, cmp_nowvec);
	for(int i = 1; i <= n; i++)
	{
//		printf("%d ", a[i].second);
		pos[a[i].second] = i;
	}
//	printf("\n");
	for(int i = 1; i <= bn; i++)
	{
//		b[i].first.writeln(0);
		if(i > 1)
		{
			int x = b[i - 1].second.first / MAXN;
			int y = b[i - 1].second.first % MAXN;
//			printf("%d %d: %d %d\n", x, y, pos[x], pos[y]);
//			assert(abs(pos[x] - pos[y]) == 1);
			swap(a[pos[x]], a[pos[y]]);
			swap(pos[x], pos[y]);
		}
		int l = 1, r = n;
		Point nowp = a[pos[b[i].second.first % MAXN]].first;
//		for(int j = 1; j <= n; j++)
//			printf("%d: %I64d\n", a[j].second, det(b[i].first, a[j].first - nowp));
		while(l < r)
		{
			int m = (l + r) / 2;
			long long mv = det(b[i].first, a[m].first - nowp);
			if(mv < S)
				l = m + 1;
			else if(mv > S)
				r = m - 1;
			else
				found(m, pos[b[i].second.first / MAXN], pos[b[i].second.first % MAXN]);
		}
		if(det(b[i].first, a[r].first - nowp) == S)
			found(r, pos[b[i].second.first / MAXN], pos[b[i].second.first % MAXN]);
		/*l = 1, r = n;
		while(l < r)
		{
			int m = (l + r) / 2;
			long long mv = det(b[i].first, a[m].first - nowp);
			if(mv < -S)
				l = m + 1;
			else if(mv > -S)
				r = m - 1;
			else
				found(m, pos[b[i].second / MAXN], pos[b[i].second % MAXN]);
		}*/
	}
	printf("No\n");
	return 0;
}