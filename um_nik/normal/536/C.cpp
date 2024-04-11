#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

const double A = 1e4;
const double eps = 1e-12;
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

struct Point
{
	int idx;
	double x, y;

	Point() : idx(), x(), y() {}
	Point(double _x, double _y) : idx(-1), x(_x), y(_y) {}

	void scan(int i)
	{
		idx = i;
		scanf("%lf%lf", &x, &y);
		x = A / x;
		y = A / y;
	}

	Point operator + (Point a)
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (Point a) const
	{
		return Point(x - a.x, y - a.y);
	}
	Point operator * (double k)
	{
		return Point(x * k, y * k);
	}
	Point operator / (double k)
	{
		return Point(x / k, y / k);
	}

	double operator % (Point a)
	{
		return x * a.x + y * a.y;
	}
	double operator * (Point a)
	{
		return x * a.y - y * a.x;
	}
	double sqLen()
	{
		return *this % *this;
	}

	bool operator < (const Point &a) const
	{
		if (!eq(x, a.x))
			return x < a.x;
		return ls(y, a.y);
	}

	bool operator == (const Point &a) const
	{
		return eq(x, a.x) && eq(y, a.y);
	}
};

const int N = (int)2e5 + 200;
int n, oldn;
Point a[N];
Point minP;
bool ans[N];
int ans2[N];

bool cmp(const Point &a, const Point &b)
{
	Point v = a - minP;
	Point u = b - minP;
	double x = v * u;
	if (!eq(x, 0))
		return x > 0;
	return ls(v.sqLen(), u.sqLen());
}

void solve()
{
	minP = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] < minP)
			minP = a[i];
	sort(a, a + n, cmp);
	Point h[N];
	int sz = 1;
	h[0] = a[0];
	for (int i = 1; i < n; i++)
	{
		while(sz >= 2 && ls(0, (a[i] - h[sz - 1]) * (h[sz - 1] - h[sz - 2])))
			sz--;
		h[sz++] = a[i];
	}
	int idx = 1;
	while(idx < sz && ls((h[idx] - h[idx - 1]).y, 0))
		idx++;
	for (int i = 0; i < idx; i++)
		ans[h[i].idx] = 1;

	for (int i = 1; i <= oldn; i++)
		if (ans[i] || (ans2[i] != -1 && ans[ans2[i]]))
			printf("%d ", i);
	printf("\n");
	return;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		a[i].scan(i + 1);

	sort(a, a + n);
	ans2[a[0].idx] = -1;
	for (int i = 1; i < n; i++)
	{
		if (a[i] == a[i - 1])
		{
			int p = a[i - 1].idx;
			if (ans2[p] == -1)
				ans2[a[i].idx] = p;
			else
				ans2[a[i].idx] = ans2[p];
		}
		else
			ans2[a[i].idx] = -1;
	}
	oldn = n;
	n = unique(a, a + n) - a;

	solve();

	return 0;
}