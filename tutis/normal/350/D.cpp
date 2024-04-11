/*input
1 2
-1 0 1 0
-100 0 1
100 0 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y): x(x), y(y) {}
	bool operator<(const point &o)const
	{
		if (x != o.x)
			return x < o.x;
		return y < o.y;
	}
	void simplify()
	{
		if (x < 0 || (x == 0 && y < 0))
		{
			x *= -1;
			y *= -1;
		}
		ll g = __gcd(abs(x), abs(y));
		x /= g;
		y /= g;
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
point operator*(point a, ll k)
{
	return point(a.x * k, a.y * k);
}
point operator/(point a, ll k)
{
	return point(a.x / k, a.y / k);
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
struct segment
{
	point a, b;
};
struct line
{
	point v;
	ll dis;
	line(const point &a, const point &b)
	{
		v = b - a;
		v.simplify();
		dis = cross(a, v);
	}
	bool operator<(const line&o)const
	{
		if (dis != o.dis)
			return dis < o.dis;
		return v < o.v;
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	map<line, vector<point>>A;
	map<line, vector<point>>B;
	while (n--)
	{
		point a, b;
		cin >> a.x >> a.y >> b.x >> b.y;
		a = a * 2;
		b = b * 2;
		if (b < a)
			swap(a, b);
		assert(a < b);
		line c(a, b);
		A[c].push_back(a);
		B[c].push_back(b);
	}
	for (pair<const line, vector<point>> &it : A)
	{
		sort(it.second.begin(), it.second.end());
	}
	for (pair<const line, vector<point>> &it : B)
	{
		sort(it.second.begin(), it.second.end());
	}
	pair<point, ll> C[m];
	for (ll i = 0; i < m; i++)
	{
		cin >> C[i].first.x >> C[i].first.y >> C[i].second;
		C[i].first = C[i].first * 2;
		C[i].second *= 2;
	}
	ll ans = 0;
	for (ll i = 0; i < m; i++)
	{
		for (ll j = 0; j < i; j++)
		{
			if (C[i].second != C[j].second)
				continue;
			point v = C[i].first - C[j].first;
			ll d2 = v.x * v.x + v.y * v.y;
			if (d2 <= 4 * C[i].second * C[i].second)
				continue;
			point M = (C[i].first + C[j].first) / 2;
			v = v * point(0, 1);
			line c(M, M + v);
			if (A.count(c))
			{
				ans += upper_bound(A[c].begin(), A[c].end(), M) - A[c].begin();
				ans -= lower_bound(B[c].begin(), B[c].end(), M) - B[c].begin();
			}
		}
	}
	cout << ans << "\n";
}