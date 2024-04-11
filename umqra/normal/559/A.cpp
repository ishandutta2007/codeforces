#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <cmath>
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
struct Point
{
	double x, y;
	Point () : x(), y() {}
	Point (double _x, double _y) : x(_x), y(_y) {}
	Point operator + (const Point &a) const
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (Point a)
	{
		return Point(x - a.x, y - a.y);
	}
	Point operator / (double k)
	{
		return Point(x / k, y / k);
	}
	Point operator * (double k)
	{
		return Point(x * k, y * k);
	}
	double operator * (Point a)
	{
		return x * a.y - y * a.x;
	}
	Point norm()
	{
		return *this / length();
	}
	double length()
	{
		return sqrt(x * x + y * y);
	}
	Point rotate(double alpha)
	{
		double sina = sin(alpha);
		double cosa = cos(alpha);
		return Point(x * cosa - y * sina, x * sina + y * cosa);
	}
	void print()
	{
		printf("%lf %lf\n", x, y);
	}
};
Point p[10];
int a[10];

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif
	
	for (int i = 0; i < 6; i++)
		scanf("%d", &a[i]);

	p[0] = Point();
	p[1] = Point(a[0], 0);
	for (int i = 1; i < 6; i++)
	{
		Point v = p[i] - p[i - 1];
		v = v.norm();
		v = v * a[i];
		v = v.rotate(pi / 3);
		p[i + 1] = p[i] + v;
	}
	double area = 0;
	for (int i = 1; i < 6; i++)
	{
		area += (p[i] - p[0]) * (p[i + 1] - p[0]);
	}
	area = fabs(area / 2);
	double sq = sqrt(3.) / 4;
	int cnt = (area / sq + 0.5);
	cout << cnt;

	return 0;
}