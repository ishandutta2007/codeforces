/*input
1 1 2 3 1 0
2 2 1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	ll x0, y0, ax, ay, bx, by;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;
	ll xs, ys, t;
	cin >> xs >> ys >> t;
	vector<pair<ll, ll>>A = {{x0, y0}};
	while (true)
	{
		ll x = A.back().first * ax + bx;
		ll y = A.back().second * ay + by;
		if (x <= xs + t && y <= ys + t)
			A.push_back({x, y});
		else
			break;
	}
	ll mx = 0;
	for (ll i = 0; i < (ll)A.size(); i++)
	{
		for (ll j = i; j < (ll)A.size(); j++)
		{
			for (ll k = i; k >= 0; k--)
			{
				{
					ll liko = t;
					ll xx = xs;
					ll yy = ys;
					ll kiek = 0;
					auto d = [&](ll id)
					{
						liko -= abs(xx - A[id].first);
						liko -= abs(yy - A[id].second);
						if (liko < 0)
							liko = -1;
						xx = A[id].first;
						yy = A[id].second;
						kiek++;
					};
					d(i);
					for (ll t = i + 1; t <= j; t++)
						d(t);
					for (ll t = i - 1; t >= k; t--)
						d(t);
					if (liko >= 0)
						mx = max(mx, kiek);
				}
				{
					ll liko = t;
					ll xx = xs;
					ll yy = ys;
					ll kiek = 0;
					auto d = [&](ll id)
					{
						liko -= abs(xx - A[id].first);
						liko -= abs(yy - A[id].second);
						if (liko < 0)
							liko = -1;
						xx = A[id].first;
						yy = A[id].second;
						kiek++;
					};
					d(i);
					for (ll t = i - 1; t >= k; t--)
						d(t);
					for (ll t = i + 1; t <= j; t++)
						d(t);
					if (liko >= 0)
						mx = max(mx, kiek);
				}
			}
		}
	}
	cout << mx << "\n";
}