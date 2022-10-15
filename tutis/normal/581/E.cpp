/*input
9 3 2 3
2 3
1 6
-1 0 1
*/
#pragma GCC target ("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false);
	ll e, s, m, n;
	cin >> e >> s >> n >> m;
	set<ll>xx[4];
	while (n--)
	{
		ll t, x;
		cin >> t >> x;
		for (ll j = 1; j <= t; j++)
			xx[j].insert(x);
	}
	xx[3].insert(e);
	xx[2].insert(e);
	xx[1].insert(e);
	map<pair<ll, ll>, pair<ll, ll>>M;
	function<pair<ll, ll>(ll, ll)>kuro = [&](ll f, ll k)->pair<ll, ll>
	{
		if (M.count(make_pair(f, k)))
			return M[make_pair(f, k)];
		if (f >= e)
			return {0, 0};
		if (xx[3].count(f))
		{
			ll f1 = *xx[1].upper_bound(f);
			ll r = f1 - f;
			if (r > s)
				return M[make_pair(f, k)] = { -1, -1};
			return M[make_pair(f, k)] = kuro(f1, s - r);
		}
		else if (xx[2].count(f))
		{
			ll f1 = *xx[2].upper_bound(f);
			ll r = f1 - f;
			if (r <= k)
			{
				return M[make_pair(f, k)] = kuro(f1, k - r);
			}
			else if (r <= s)
			{
				pair<ll, ll>ret = kuro(f1, 0);
				ret.second += r - k;
				if (ret.first == -1)ret.second = -1;
				return M[make_pair(f, k)] = ret;
			}
			f1 = *xx[1].upper_bound(f);
			r = f1 - f;
			if (r <= s)
			{
				pair<ll, ll>ret = kuro(f1, s - r);
				if (ret.first == -1)return { -1, -1};
				ret.second += s - k;
				return M[make_pair(f, k)] = ret;
			}
		}
		if (xx[1].count(f))
		{
			ll f1 = *xx[1].upper_bound(f);
			ll r = f1 - f;
			if (r <= k)
			{
				return M[make_pair(f, k)] = kuro(f1, k - r);
			}
			else
			{
				if (r > s)
					return M[make_pair(f, k)] = { -1, -1};
				else
				{
					pair<ll, ll>ret = kuro(f1, 0);
					if (ret.first == -1)return { -1, -1};
					ret.first += r - k;
					return M[make_pair(f, k)] = ret;
				}
			}
		}
		ll f1 = *xx[1].lower_bound(f);
		ll r = f1 - f;
		if (r <= k)
		{
			pair<ll, ll>ret = kuro(f1, k - r);
			if (ret.first == -1)
				return { -1, -1};
			return M[make_pair(f, k)] = ret;
		}
		return M[make_pair(f, k)] = { -1, -1};
	};
	while (m--)
	{
		ll f;
		cin >> f;
		pair<ll, ll>ans = kuro(f, s);
		cout << ans.first << " " << ans.second << "\n";
	}
}