/*input
5
0 0
0 4
4 0
4 4
2 3

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct point
{
	ll x, y;
	point() {}
	point(ld x, ld y): x(x), y(y) {}
	ld kampas()
	{
		ld alfa = atan2(y, x);
		if (y < 0)
			alfa += 10;
		return alfa;
	}
};
point operator!(const point &a)
{
	return point(a.x, -a.y);
}
point operator+(const point &a, const point &b)
{
	return point(a.x + b.x, a.y + b.y);
}
point operator-(const point &a, const point &b)
{
	return point(a.x - b.x, a.y - b.y);
}
point operator*(const point &a, const point &b)
{
	return point(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}
point operator*(point a, ld k)
{
	return point(a.x * k, a.y * k);
}
ll dot(const point &a, const point &b)
{
	return a.x * b.x + a.y * b.y;
}
ll cross(const point &a, const point &b)
{
	return a.x * b.y - a.y * b.x;
}
ll sgn(ll x)
{
	if (x < 0)
		return -1;
	if (x > 0)
		return 1;
	return 0;
}
bool x(point a, point b, point c, point d)
{
	return sgn(cross(b - a, c - a)) * sgn(cross(b - a, d - a)) == -1 &&
	       sgn(cross(d - c, a - c)) * sgn(cross(d - c, b - c)) == -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	point A[n];
	for (ll i = 0; i < n; i++)
		cin >> A[i].x >> A[i].y;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			ll mx = -1e9;
			ll mn = 1e9;
			for (int k = 0; k < n; k++)
			{
				ll s = cross(A[k] - A[i], A[i] - A[j]);
				mx = max(mx, s);
				mn = min(mn, s);
			}
			if (mx > 0 && mn < 0)
				ans = max(ans, mx - mn);
		}
	}
	cout << ans / 2 << "." << (ans % 2) * 5 << "\n";
}