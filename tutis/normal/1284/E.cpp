/*input
10
588634631 265299215
-257682751 342279997
527377039 82412729
145077145 702473706
276067232 912883502
822614418 -514698233
280281434 -41461635
65985059 -827653144
188538640 592896147
-857422304 -529223472

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
	ll ketv()
	{
		if (x >= 0 && y >= 0)
			return 1;
		if (x <= 0 && y >= 0)
			return 2;
		if (x <= 0 && y <= 0)
			return 3;
		return 4;
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
ll dp[2600][6][2600];
ll fast(ll n, point A[])
{
	vector<pair<point, pair<int, int>>>x;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			x.push_back({A[j] - A[i], {i, j}});
		}
	}
	sort(x.begin(), x.end(), [&](pair<point, pair<int, int>> aa, pair<point, pair<int, int>> bb) {
		point a = aa.first;
		point b = bb.first;
		if (a.ketv() != b.ketv())
			return a.ketv() < b.ketv();
		ll c = cross(a, b);
		if (c != 0)
			return c > 0;
		else
			return aa.second < bb.second;
	});
	for (ll i = 0; i < n; i++)
	{
		dp[i][0][i] = 1;
	}
	for (auto c : x)
	{
		ll i = c.second.first;
		ll j = c.second.second;
		for (ll t = 0; t < 5; t++)
		{
			for (ll k = 0; k < n; k++)
			{
				dp[j][t + 1][k] += dp[i][t][k];
			}
		}
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		ans += dp[i][5][i];
	}
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	point A[n];
	for (ll i = 0; i < n; i++)
		cin >> A[i].x >> A[i].y;
	ll f345 = n * (n - 1) * (n - 2) * (n - 3) * (n - 4) / 2 / 3 / 4 / 5;
	ll ff = 0;
	for (ll i = 0; i < n; i++)
	{
		vector<point>b;
		for (int j = 0; j < n; j++)
		{
			if (j != i)
				b.push_back(A[j] - A[i]);
		}
		sort(b.begin(), b.end(), [&](point a, point b) {
			if (a.ketv() != b.ketv())
				return a.ketv() < b.ketv();
			return cross(a, b) > 0;
		});
		ll k1 = 0;
		for (ll j = 0; j < (ll)b.size(); j++)
		{
			k1++;
			k1 = min(k1, n - 2);
			while (cross(b[j], b[(j + k1 + 1) % b.size()]) > 0)
				k1++;
			while (cross(b[j], b[(j + k1) % b.size()]) < 0)
				k1--;
			ff += k1 * (k1 - 1) * (k1 - 2) / 6;
		}
	}
	cout << (ff - 5 * f345) * (-1) << "\n";
}