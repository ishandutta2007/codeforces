/*input
6 4 10
3 1 1 1 2 2
7
8
9
10
11
12
13
14
15
16

*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m, q;
	cin >> n >> m >> q;
	pair<ll, ll>h[m + 1];
	h[m].second = -1;
	for (ll i = 0; i < m; i++)
		h[i] = {0, i + 1};
	for (ll i = 0; i < n; i++)
	{
		ll a;
		cin >> a;
		a--;
		h[a].first++;
	}
	sort(h, h + m);
	ll V[m];
	ll sumh = 0;
	for (ll i = 0; i < m; i++)
	{
		sumh += h[i].first;
		V[i] = (i + 1) * h[i].first - sumh;
	}
	ll ans[q];
	vector<pair<ll, ll>>que;
	for (ll i = 0; i < q; i++)
	{
		ll a;
		cin >> a;
		que.push_back({a, i});
	}
	sort(que.begin(), que.end());
	ordered_set<ll>t;
	ll xx = -1;
	for (auto j : que)
	{
		ll i = j.second;
		ll k = j.first;
		k -= n;
		ll lo = 0;
		ll hi = m - 1;
		while (lo < hi)
		{
			ll x = (lo + hi + 1) / 2;
			if (V[x] < k)
				lo = x;
			else
				hi = x - 1;
		}
		ll x = (lo + hi) / 2;
		k -= V[x];
		k--;
		k %= (x + 1);
		while (xx < x)
		{
			t.insert(h[xx + 1].second);
			xx++;
		}
		ans[i] = *t.find_by_order(k);
	}
	for (ll i = 0; i < q; i++)
		cout << ans[i] << "\n";
}