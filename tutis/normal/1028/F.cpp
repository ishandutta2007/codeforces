/*input
6
1 1 2
3 1 1
1 1 1
3 2 2
2 1 1
3 2 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll q;
	cin >> q;
	map<ll, vector<pair<ll, ll>>>X;
	map<pair<ll, ll>, ll>ans;
	map<pair<ll, ll>, ll>lyg;
	ll kiek = 0;
	while (q--)
	{
		ll t, x, y;
		cin >> t >> x >> y;
		if (t == 1)
		{
			kiek++;
			vector<pair<ll, ll>> &xxx = X[x * x + y * y];
			for (pair<ll, ll>a : X[x * x + y * y])
			{
				ll c = (x + a.first);
				ll d = (y + a.second);
				ll g = __gcd(c, d);
				ans[ {c / g, d / g}]++;
			}
			xxx.emplace_back(x, y);
			ll g = __gcd(x, y);
			x /= g;
			y /= g;
			lyg[ {x, y}]++;
		}
		if (t == 2)
		{
			kiek--;
			vector<pair<ll, ll>> &xxx = X[x * x + y * y];
			xxx.erase(find(xxx.begin(), xxx.end(), make_pair(x, y)));
			for (pair<ll, ll>a : xxx)
			{
				ll c = (x + a.first);
				ll d = (y + a.second);
				ll g = __gcd(c, d);
				ans[ {c / g, d / g}]--;
			}
			ll g = __gcd(x, y);
			x /= g;
			y /= g;
			lyg[ {x, y}]--;
		}
		if (t == 3)
		{
			ll g = __gcd(x, y);
			x /= g;
			y /= g;
			ll gal = kiek;
			if (ans.count({x, y}))
				gal -= ans[ {x, y}] * 2;
			if (lyg.count({x, y}))
				gal -= lyg[ {x, y}];
			cout << gal << "\n";
		}
	}

}