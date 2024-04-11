#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;

struct Point
{
	ll x, y;

	Point() : x(), y() {}
	Point (ll _x, ll _y) : x(_x), y(_y) {}

	Point operator + (const Point &a) const
	{
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const
	{
		return Point(x - a.x, y - a.y);
	}
	ll operator % (const Point &a) const
	{
		return x * a.x + y * a.y;
	}
	ll operator * (const Point &a) const
	{
		return x * a.y - y * a.x;
	}
	ll sqrLen() const
	{
		return *this % *this;
	}

	void scan()
	{
		scanf("%lld%lld", &x, &y);
	}
};

const int N = 100100;
Point a[N];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		a[i].scan();
	ll L = (a[1] - a[0]).sqrLen();
	int v = 1;
	for (int i = 2; i < n; i++)
	{
		ll d = (a[i] - a[0]).sqrLen();
		if (d < L)
		{
			L = d;
			v = i;
		}
	}
	ll S = -1;
	int u = -1;
	for (int i = 0; i < n; i++)
	{
		ll s = (a[i] - a[0]) * (a[i] - a[v]);
		s = abs(s);
		if (s == 0) continue;
		if (S == -1 || s < S)
		{
			S = s;
			u = i;
		}
	}
	printf("%d %d %d\n", 1, min(v, u) + 1, max(v, u) + 1);
	
	return 0;
}