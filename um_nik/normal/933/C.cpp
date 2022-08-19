#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-9;
inline bool eq(double x, double y)
{
	return fabs(x - y) < eps;
}
bool ls(double x, double y)
{
	return (x < y) && !eq(x, y);
}
bool lseq(double x, double y)
{
	return ls(x, y) || eq(x, y);
}

struct Point 
{
	double x, y;

	Point () : x(0), y(0) {}
	Point (double x, double y) : x(x), y(y) {}

	void scan()
	{
		scanf("%lf%lf", &x, &y);
	}

	void print()
	{
//		printf("%.4lf %.4lf\n", x, y);
	}

	Point operator + (Point a)
	{
		return Point(x + a.x, y + a.y);
	}

	Point operator - (Point a)
	{
		return Point(x - a.x, y - a.y);
	}

	Point operator * (double k)
	{
		return Point(x * k, y * k);
	}

	Point operator / (double k)
	{
		return *this * (1. / k);
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

	double len()
	{
		return sqrt( sqLen() );
	}

	Point norm()
	{
		return *this / len();
	}

	Point rot()
	{
		return Point(-y, x);
	}

	Point rot(double angle)
	{
		return *this * cos(angle) + rot() * sin(angle);
	}

	bool operator < (const Point &a) const
	{
		if (eq(x, a.x))
			return ls(y, a.y);
		return ls(x, a.x);
	}

	bool operator == (const Point &a) const
	{
		return !( (*this < a) || (a < *this) );
	}
};

struct Circle
{
	Point O;
	double R;

	void scan()
	{
		O.scan();
		scanf("%lf", &R);
	}

	bool operator < (const Circle &a) const
	{
		if (eq(R, a.R))
			return O < a.O;
		return ls(R, a.R);
	}

	bool operator == (const Circle &a) const
	{
		return !( (*this < a) || (a < *this) );
	}
};

int n;
int ans = 1;
Circle a[600];
Point b[260000];
int sz;
int par[260000];
int s[260000];

void intersect_circles(Circle A, Circle B)
{
	Point O1 = A.O;
	Point O2 = B.O;
	double R1 = A.R;
	double R2 = B.R;
	double L = (O1 - O2).len();
	if (L < fabs(R2 - R1) || L > (R1 + R2))
		return;
	double d = 0.5 * (L + (R1 * R1 - R2 * R2) / L);
	Point H = O1 + (O2 - O1).norm() * d;
	double len = sqrt(R1 * R1 - d * d);
	Point a = (O2 - O1).rot().norm() * len;
	b[sz++] = H + a;
	b[sz++] = H - a;
	return;
}

inline int get_par(int v)
{
	if (par[v] == -1)
		return v;
	return par[v] = get_par(par[v]);
}

void unite(int v, int u)
{
	v = get_par(v);
	u = get_par(u);
	if (v == u)
		return;
	if (s[v] < s[u])
	{
		par[v] = u;
		s[u] += s[v];
	}
	else
	{
		par[u] = v;
		s[v] += s[u];
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		a[i].scan();
	sort(a, a + n);
	n = unique(a, a + n) - a;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			intersect_circles(a[i], a[j]);
	sort(b, b + sz);
	sz = unique(b, b + sz) - b;
	ans -= sz;
	for (int i = 0; i < sz; i++)
	{
		par[i] = -1;
		s[i] = 1;
	}
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 0; j < sz; j++)
		{
			if ( fabs(a[i].R * a[i].R - ( a[i].O - b[j] ).sqLen()) < 1e-6 )
			{
				ans++;
				if (t == -1)
					t = j;
				else
					unite(t, j);
			}
		}
		if (t == -1)
			ans++;
	}
	for (int i = 0; i < sz; i++)
		if (par[i] == -1)
			ans++;
	printf("%d\n", ans);

	return 0;
}