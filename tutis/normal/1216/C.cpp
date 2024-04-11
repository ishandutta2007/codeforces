/*input
0 0 1000000 1000000
0 0 499999 1000000
500000 0 1000000 1000000

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
struct rect
{
	ll x1, x2, y1, y2;
	rect()
	{
		cin >> x1 >> y1 >> x2 >> y2;
		x1 *= 2;
		y1 *= 2;
		x2 *= 2;
		y2 *= 2;
	}
	bool viduj1(ll a, ll b)
	{
		return (x1 < a && a < x2 && y1 < b && b < y2);
	}
	bool viduj2(ll a, ll b)
	{
		return (x1 <= a && a <= x2 && y1 <= b && b <= y2);
	}
};
int main()
{
	ios_base::sync_with_stdio(false);
	rect W, B1, B2;
	vector<ll>x = {W.x1, W.x2, B1.x1, B1.x2, B2.x1, B2.x2};
	vector<ll>y = {W.y1, W.y2, B1.y1, B1.y2, B2.y1, B2.y2};
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());
	for (int t = 1; t < x.size(); t++)
	{
		ll a = (x[t] + x[t - 1]) / 2;
		for (int t1 = 1; t1 < x.size(); t1++)
		{
			ll b = (y[t1] + y[t1 - 1]) / 2;
			if (W.viduj1(a, b))
			{
				if (!(B1.viduj2(a, b) || B2.viduj2(a, b)))
				{
					cout << "YES\n";
					return 0;
				}
			}
		}
	}
	cout << "NO\n";
}