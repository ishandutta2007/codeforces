/*input
10
841746 527518
595261 331297
-946901 129987
670374 -140388
-684770 309555
-302589 415564
-387435 613331
-624940 -95922
945847 -199224
24636 -565799

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
ll dp[300][6][300];
ll fast(ll n, point A[])
{
	vector<pair<ld, pair<int, int>>>x;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
				continue;
			x.push_back({(A[j] - A[i]).kampas(), {i, j}});
		}
	}
	sort(x.begin(), x.end());
	for (int i = 0; i < n; i++)
	{
		dp[i][0][i] = 1;
	}
	for (auto c : x)
	{
		int i = c.second.first;
		int j = c.second.second;
		for (int t = 0; t < 5; t++)
		{
			for (int k = 0; k < n; k++)
			{
				dp[j][t + 1][k] += dp[i][t][k];
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
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
	cout << fast(n, A) << "\n";
}