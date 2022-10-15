/*input
5 6
2 3 11
5 3 7
1 4 10
2 4 14
4 3 8
2 5 6

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll n, m;
	cin >> n >> m;
	map<ll, ll>E[n + 1];
	ll X = 0;
	vector<pair<ll, pair<ll, ll>>>EE;
	for (ll i = 0; i < m; i++)
	{
		ll u, v, w;
		cin >> u >> v >> w;
		EE.push_back({w, {u, v}});
		X ^= w;
		E[u][v] = w;
		E[v][u] = w;
	}
	ll m_ = n * (n - 1) / 2 - m;
	if (m_ < n && X > 0)
	{
		ll pa[n + 1];
		iota(pa, pa + n + 1, 0);
		function<ll(ll)>root = [&](ll x)
		{
			if (pa[x] == x)
				return x;
			else
				return pa[x] = root(pa[x]);
		};
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j < i; j++)
			{
				if (E[i].count(j) == 0)
				{
					ll x = root(i);
					ll y = root(j);
					if (x != y)
					{
						pa[x] = y;
					}
					else
					{
						X = 0;
						goto B;
					}
				}
			}
		}
		for (ll i = 1; i <= n; i++)
		{
			for (ll j = 1; j <= i; j++)
			{
				if (E[i].count(j) != 0)
				{
					ll w = E[i][j];
					ll x = root(i);
					ll y = root(j);
					if (x == y)
					{
						X = min(X, w);
					}
				}
			}
		}
	}
	else
		X = 0;
B:;
	ll ans = 0;
	ll pa[n + 1];
	iota(pa, pa + n + 1, 0);
	function<ll(ll)>root = [&](ll x)
	{
		if (pa[x] == x)
			return x;
		else
			return pa[x] = root(pa[x]);
	};
	multiset<ll>R;
	for (ll i = 1; i <= n; i++)
		R.insert(i);
	ll cnt[n + 1];
	fill_n(cnt, n + 1, 1);
	for (ll i = 1; i <= n; i++)
	{
		ll ri = root(i);
		vector<ll>P;
		for (auto e : E[i])
		{
			ll j = root(e.first);
			if (ri != j)
			{
				P.push_back(j);
				cnt[j]--;
			}
		}
		vector<ll>mer;
		for (ll v : R)
		{
			if (cnt[v] > 0 && v != ri)
				mer.push_back(v);
		}
		for (ll j : P)
			cnt[j]++;
		for (ll j : mer)
		{
			ll x = root(i);
			ll y = root(j);
			pa[x] = y;
			cnt[y] += cnt[x];
			R.erase(x);
		}
	}
	for (int i = 1; i <= n; i++)
		cnt[i]--;
	sort(EE.begin(), EE.end());
	for (auto e : EE)
	{
		ll w = e.first;
		ll x = root(e.second.first);
		ll y = root(e.second.second);
		if (x != y)
		{
			pa[x] = y;
			cnt[y] += cnt[x];
			ans += w;
		}
		else if (E[e.second.first].size() < n - 1 || E[e.second.second].size() < n - 1)
		{
			X = min(X, w);
		}
	}
	ans += X;
	cout << ans << "\n";
}