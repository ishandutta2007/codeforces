#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
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

	bool operator < (const Point &a) const
	{
		if (x != a.x) return x < a.x;
		return y < a.y;
	}

	void scan()
	{
		scanf("%lld%lld", &x, &y);
	}
	void print()
	{
		printf("%lld %lld\n", x, y);
	}
};

Point minP;
bool cmp(const Point &a, const Point &b)
{
	Point v = a - minP, u = b - minP;
	if (v * u != 0) return v * u > 0;
	return v.sqrLen() < u.sqrLen();
}
const int N = 15050;
int n;
Point a[N];
Point h[N];
int m;
int ans1, ans2, ans3;
ll res = -1;

ll getArea(Point A, Point B, Point C)
{
	return abs((A - B) * (A - C));
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	ll _t;
	scanf("%d%lld", &n, &_t);
	for (int i = 0; i < n; i++)
		a[i].scan();
	minP = a[0];
	for (int i = 0; i < n; i++)
		if (a[i] < minP)
			minP = a[i];
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
	{
		while(m > 1 && (a[i] - h[m - 1]) * (a[i] - h[m - 2]) >= 0) m--;
		h[m++] = a[i];
	}
	n = m;
	for (int i = 0; i < 2 * n; i++)
		a[i] = h[i % n];
	if (n < 3) throw;
//	for (int i = 0; i < n; i++)
//		a[i].print();
	for (int it1 = 0; it1 < n; it1++)
	{
		int it3 = it1 + 2;
		for (int it2 = it1 + 1; it2 < it1 + n; it2++)
		{
			ll oldAr = getArea(a[it1], a[it2], a[it3]);
			while(it3 + 1 < it1 + n)
			{
				ll newAr = getArea(a[it1], a[it2], a[it3 + 1]);
				if (newAr <= oldAr) break;
				oldAr = newAr;
				it3++;
			}
			if (oldAr > res)
			{
				res = oldAr;
				ans1 = it1;
				ans2 = it2;
				ans3 = it3;
			}
		}
	}

	(a[ans1] + a[ans2] - a[ans3]).print();
	(a[ans2] + a[ans3] - a[ans1]).print();
	(a[ans3] + a[ans1] - a[ans2]).print();

	return 0;
}