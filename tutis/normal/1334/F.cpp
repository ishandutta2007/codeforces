/*input
11
4 1 3 3 7 8 7 9 10 7 11
3 5 0 -2 5 3 6 7 8 2 4
3
3 7 10

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll maxi = 6e8;
ll F[500009];
void add(ll i, ll w)
{
	while (i < 500009)
	{
		F[i] += w;
		i += i & -i;
	}
}
ll get(ll i)
{
	ll s = 0;
	while (i > 0)
	{
		s += F[i];
		i -= i & -i;
	}
	return s;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	map<ll, vector<ll>>a;
	for (ll i = 1; i <= n; i++)
	{
		ll A;
		cin >> A;
		a[A].push_back(i);
	}
	a[maxi] = {n + 1};
	ll p[n + 2];
	p[0] = 0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> p[i];
		p[i] += p[i - 1];
	}
	p[n + 1] = p[n];
	map<ll, ll, greater<ll>>C;
	C[0] = 0;
	ll m;
	cin >> m;
	ll x = -1;
	for (ll t = 0; t <= m; t++)
	{
		while (!a.empty() && a.begin()->first <= x)
		{
			for (ll i : a.begin()->second)
			{
				ll x = p[i] - p[i - 1];
				if (x > 0)
					add(i, x);
			}
			a.erase(a.begin());
		}
		ll b;
		if (t < m)
			cin >> b;
		else
			b = maxi;
		map<ll, ll, greater<ll>>C1 = C;
		ll mn = 1e18;
		for (auto it = C1.rbegin(); it != C1.rend(); it++)
		{
			ll j = it->first;
			it->second -= p[j];
			it->second += get(j);
			mn = min(mn, it->second);
			it->second = mn;
		}
		C.clear();
		for (ll i : a[b])
		{
			auto it = C1.upper_bound(i);
			if (it != C1.end())
			{
				ll c = it->second;
				C[i] = c + p[i - 1] - get(i - 1);
			}
		}
		x = b;
	}
	if (C.empty())
	{
		cout << "NO\n";
	}
	else
	{
		cout << "YES\n";
		ll ans = C.begin()->second;
		for (auto i : C)
			ans = min(ans, i.second);
		cout << ans << "\n";
	}
	return 0;
}