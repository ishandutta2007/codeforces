/*input
50 50 7
10 F 1 80000
20 T 1 80000
30 T 81000 82000
40 T 83000 84000
50 T 85000 86000
60 T 87000 88000
70 F 81000 89000
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
struct point
{
	ll x, y;
	point(): x(0), y(0)
	{

	}
	point(ll x, ll y): x(x), y(y)
	{

	}
};
point operator-(point a, point b)
{
	return point(a.x - b.x, a.y - b.y);
}
ll cross(point a, point b)
{
	return a.x * b.y - a.y * b.x;
}
bool intersect(point a, point b, point x, point y)
{
	ll c = cross(y - x, a - x);
	ll d = cross(y - x, b - x);
	if (c == 0 || d == 0)
		return true;
	if (c > 0 && d < 0)
		return true;
	if (c < 0 && d > 0)
		return true;
	return false;
}
struct LINE
{
	point A, B;
	ll i;
	LINE()
	{

	}
	LINE(point a, point b): A(a), B(b)
	{

	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	ll hl, hr, n;
	cin >> hl >> hr >> n;
	ll v[n];
	vector<LINE>X;
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		char x;
		ll a, b;
		cin >> v[i] >> x >> a >> b;
		LINE Y;
		Y.i = i;
		Y.A.x = a;
		Y.B.x = b;
		for (ll t = -100; t <= 100; t++)
		{
			ll y = t * 100;
			if (t % 2 == 0)
			{
				if (x == 'F')
				{
					Y.A.y = Y.B.y = y;
					X.push_back(Y);
				}
			}
			else
			{
				if (x != 'F')
				{
					Y.A.y = Y.B.y = y;
					X.push_back(Y);
				}
			}
		}
	}
	for (ll t = -101; t <= 101; t++)
	{
		LINE C;
		if (t % 2 == 0)
		{
			C = LINE(point(0, hl), point(100000, hr + 100 * t));
		}
		else
		{
			C = LINE(point(0, hl), point(100000, -hr + 100 * (t + 1)));
		}
		set<ll>ids;
		bool ok = true;
		for (LINE c : X)
		{
			if (intersect(c.A, c.B, C.A, C.B))
			{
				if (ids.count(c.i))
					ok = false;
				ids.insert(c.i);
			}
		}
		if (ok && ids.size() == abs(t))
		{
			ll gal = 0;
			for (ll i : ids)
				gal += v[i];
			ans = max(ans, gal);
		}
	}
	cout << ans << "\n";
}