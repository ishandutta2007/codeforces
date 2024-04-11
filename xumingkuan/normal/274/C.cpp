#include <stdio.h>
#include <string.h>
#include <math.h>
#define EPS 1e-7
int n;
int cmp(double x)
{
	return x > EPS ? 1 : x < -EPS ? -1 : 0;
}
class Point
{
	public:
		double x, y;
		Point(){}
		Point(double x, double y): x(x), y(y) {}
		Point operator +(const Point &b) const
		{
			return Point(x + b.x, y + b.y);
		}
		Point operator -(const Point &b) const
		{
			return Point(x - b.x, y - b.y);
		}
		Point operator *(double b) const
		{
			return Point(x * b, y * b);
		}
		bool operator ==(const Point &b) const
		{
			return !cmp(x - b.x) && !cmp(y - b.y);
		}
		Point normal() const
		{
			return Point(y, -x);
		}
		double len2() const
		{
			return x * x + y * y;
		}
		void read()
		{
			scanf("%lf%lf", &x, &y);
		}
};
double dot(const Point &a, const Point &b)
{
	return a.x * b.x + a.y * b.y;
}
double det(const Point &a, const Point &b)
{
	return a.x * b.y - a.y * b.x;
}
int intersection(const Point &a, const Point &b, const Point &c, const Point &d, Point &o)
{
	if(cmp(det(b - a, d - c)) == 0)
		return 0;
	double s1 = det(c - a, b - a);
	double s2 = det(b - a, d - a);
	o = c + (d - c) * (s1 / (s1 + s2));
	return 1;
}
int circumcenter_in_triangle(const Point &a, const Point &b, const Point &c, Point &o)
{
	if(!cmp(dot(b - a, c - a)) || !cmp(dot(c - b, a - b)) || !cmp(dot(a - c, b - c)) || !intersection((a + b) * 0.5, (a + b) * 0.5 + (b - a).normal(), (b + c) * 0.5, (b + c) * 0.5 + (c - b).normal(), o))
		return 0;
	if(cmp(fabs(det(a - o, b - o)) + fabs(det(b - o, c - o)) + fabs(det(c - o, a - o)) - fabs(det(c - a, b - a))))
		return 0;
	return 1;
}
Point a[105], o;
double ans = -1;
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		a[i].read();
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			for(int k = j + 1; k <= n; k++)
				if(circumcenter_in_triangle(a[i], a[j], a[k], o))
				{
					double now = (o - a[i]).len2();
					if(now > ans)
					{
						bool flag = true;
						for(int t = 1; t <= n; t++)
							if(cmp((a[t] - o).len2() - now) < 0)
							{
								flag = false;
								break;
							}
						if(flag)
							ans = now;
					}
				}
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			for(int k = j + 1; k <= n; k++)
				if(!cmp(dot(a[j] - a[i], a[k] - a[i])))
					for(int l = i + 1; l <= n; l++)
						if(!cmp(dot(a[l] - a[j], a[i] - a[j])) && !cmp(dot(a[l] - a[k], a[i] - a[k])) && !cmp(dot(a[j] - a[l], a[k] - a[l])) && l != j && l != k)
						{
							o = (a[l] + a[i]) * 0.5;
							double now = (o - a[i]).len2();
							if(now > ans)// && !(n == 5 && a[15 - i - j - k - l] == (a[l] + a[i]) * 0.5))
							{
								bool flag = true;
								for(int t = 1; t <= n; t++)
									if(cmp((a[t] - o).len2() - now) < 0)
									{
										flag = false;
										break;
									}
								if(flag)
									ans = now;
							}
						}
	if(ans < -0.5)
		printf("-1\n");
	else
		printf("%.9lf\n", sqrt(ans));
	return 0;
}
/*
5
-2 -2
2 -2
-4 2
4 2
0 5
*/