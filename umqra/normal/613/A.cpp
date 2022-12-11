#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <sstream>
#include <fstream>
#include <functional>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const double pi = atan(1.) * 4;
const int N = (int)1e5 + 100;

struct Point
{
	ll x, y;
	Point () : x(), y() {}
	Point (ll _x, ll _y) : x(_x), y(_y) {}
	Point operator + (const Point &a) const
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const
	{
		return Point(x - a.x, y - a.y);
	}
	ll operator * (const Point &a) const
	{
		return x * a.y - y * a.x;
	}
	ll operator % (const Point &a) const
	{
		return x * a.x + y * a.y;
	}
	void scan()
	{
		scanf("%lld%lld", &x, &y);
	}
	bool operator < (const Point &a) const
	{
		return x < a.x || (x == a.x && y < a.y);
	}
	ll sqrLen()
	{
		return x * x + y * y;
	}
	double length()
	{
		return sqrt(sqrLen());
	}
};

Point p[N];
Point st[N];
Point minP;
int r = 0;

bool cmp(const Point &a, const Point &b)
{
	Point v = a - minP;
	Point u = b - minP;
	if (v * u != 0)
		return v * u > 0;
	return v.sqrLen() < u.sqrLen();
}
int n;

void getH()
{
	minP = *min_element(p, p + n);
	sort(p, p + n, cmp);
	r = 0;
	for (int i = 0; i < n; i++)
	{
		while (r > 1 && ((st[r - 1] - st[r - 2]) * (p[i] - st[r - 2])) <= 0)
			r--;
		st[r++] = p[i];
	}
}

bool isInside(Point P)
{
	double angle = 0;
	for (int i = 0; i < r; i++)
	{
		Point v = st[(i + 1) % r] - P;
		Point u = st[i] - P;
		angle += atan2(v * u, v % u);
	}
	return fabs(angle) > 1e-2;
}

double sqr(double x)
{
	return x * x;
}

double getDist(Point P, Point A, Point B)
{
	if ((P - A) % (B - A) <= 0)
		return (P - A).sqrLen();
	if ((P - B) % (A - B) <= 0)
		return (P - B).sqrLen();
	return sqr((P - A) * (P - B)) / (A - B).sqrLen();
}

int main()
{
	Point P;
	scanf("%d", &n);
	P.scan();
	double minR = (double)1e18, maxR = 0;
	for (int i = 0; i < n; i++)
	{
		p[i].scan();
		double curR = (p[i] - P).sqrLen();
		minR = min(minR, curR);
		maxR = max(maxR, curR);
	}
	for (int i = 0; i < n; i++)
	{
		minR = min(minR, getDist(P, p[i], p[(i + 1) % n]));
	}
	getH();
	printf("%.10lf\n", pi * (maxR - minR));
	return 0;
}