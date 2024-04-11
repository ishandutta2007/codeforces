/*input
7 8
3 6 7 9 10 7 239
8 1 9 7 10 2 6 239
3 2 1 3
2 4 1
3 1 3 7
2 4 3
5 3 4 5 6 7
2 5 7
1 8

*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	ll m, n;
	cin >> m >> n;
	ll a[m + 1];
	for (ll i = 1; i <= m; i++)
		cin >> a[i];
	ll b[n + 1];
	for (ll i = 1; i <= n; i++)
		cin >> b[i];
	vector<ll>A[n + 1];
	ll ret = 0;
	ll sum = 0;
	vector<pair<ll, pair<ll, ll>>>X;
	for (ll i = 1; i <= m; i++)
	{
		ll k;
		cin >> k;
		while (k--)
		{
			ll x;
			cin >> x;
			sum += a[i] + b[x];
			X.push_back({ -a[i] - b[x], {x, i}});
			A[x].push_back(i);
		}
	}
	ll pa[m + 1];
	iota(pa, pa + m + 1, 0);
	set<ll>x[m + 1];
	sort(X.begin(), X.end());
	vector<ll>id(n + 1, -1);
	function<ll(ll)>root = [&](ll x)
	{
		if (x != pa[x])
			return pa[x] = root(pa[x]);
		else
			return pa[x];
	};
	for (auto asd : X)
	{
		ll i = asd.second.second;
		ll x = asd.second.first;
		if (id[x] == -1)
		{
			id[x] = root(i);
			ret += -asd.first;
		}
		else
		{
			ll a = root(i);
			ll b = root(id[x]);
			if (a != b)
			{
				ret += -asd.first;
				pa[a] = b;
			}
		}
	}
	cout << sum - ret << "\n";
	return 0;
}