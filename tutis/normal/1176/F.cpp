/*input
5
3
1 6
1 7
1 5
2
1 4
1 3
3
1 10
3 5
2 3
3
1 15
2 4
1 10
1
1 100
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename A, typename B>
using hash_set = cc_hash_table<A, B>;
typedef long long ll;
mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	ll ans[10];
	fill_n(ans, 10, -1e18);
	ans[0] = 0;
	while (n--)
	{
		ll k;
		cin >> k;
		vector<ll>dd[4];
		ll ans_[10];
		fill_n(ans_, 10, -1e18);
		for (ll i = 0; i < k; i++)
		{
			ll c, d;
			cin >> c >> d;
			dd[c].push_back(d);
		}
		vector<pair<ll, ll>>x;
		for (ll t = 1; t <= 3; t++)
		{
			if (t > 1)
			{
				if (!dd[t].empty())
					x.push_back({t, *max_element(dd[t].begin(), dd[t].end())});
				continue;
			}
			sort(dd[t].begin(), dd[t].end(), greater<ll>());
			for (int i = 0; i < 3 && i < dd[t].size(); i++)
				x.push_back({t, dd[t][i]});
		}
		vector<vector<pair<ll, ll>>>xxx;
		for (int i = 0; i < x.size(); i++)
		{
			xxx.push_back({x[i]});
			for (int j = 0; j < x.size(); j++)
			{
				if (j == i)
					continue;
				xxx.push_back({x[i], x[j]});
				for (int k = 0; k < x.size(); k++)
				{
					if (k == i || k == j)
						continue;
					xxx.push_back({x[i], x[j], x[k]});
				}
			}
		}
		for (auto x : xxx)
			for (ll t = 0; t < 10; t++)
			{
				ll sumc = 0;
				ll sumd = 0;
				for (ll i = 0; i < x.size(); i++)
				{
					ll t_ = (t + i + 1) % 10;
					sumc += x[i].first;
					sumd += x[i].second;
					if (t_ % 10 == 0)
						sumd += x[i].second;
					if (sumc <= 3)
						ans_[t_] = max(ans_[t_], ans[t] + sumd);
				}
			}
		for (ll i = 0; i < 10; i++)
			ans[i] = max(ans[i], ans_[i]);
	}
	cout << *max_element(ans, ans + 10) << "\n";
}