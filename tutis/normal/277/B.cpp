/*input
4 3
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
struct point
{
	ll x, y;
	point() {}
	point(ll x, ll y): x(x), y(y) {}
};
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	if (n >= 5 && m == 3)
	{
		cout << "-1\n";
		return 0;
	}
	vector<point>a;
	for (int i = 0; i < m; i++)
	{
		ld alfa = 2 * acos(-1) * i / m + 0.86132876312;
		a.push_back(point(cos(alfa) * 25000000, sin(alfa) * 25000000));
	}
	n -= m;
	if (n > 0)
	{
		a.push_back(point(100000000, 100000000));
		n--;
	}
	if (n > 0)
	{
		a.push_back(point(-100000000, -100000000));
		n--;
	}
	if (m >= 4)
	{
		if (n > 0)
		{
			a.push_back(point(100000000, -100000000));
			n--;
		}
		if (n > 0)
		{
			a.push_back(point(-100000000, 100000000));
			n--;
		}
	}
	if (m >= 5)
		if (n > 0)
		{
			a.push_back(point(7123, 871));
			n--;
		}
	for (int i = 0; i < n; i++)
	{
		ld alfa = 2 * acos(-1) * i / m + 0.0124412;
		a.push_back(point(cos(alfa) * 10000000, sin(alfa) * 10000000));
	}
	for (point i : a)
		cout << i.x << " " << i.y << "\n";
}