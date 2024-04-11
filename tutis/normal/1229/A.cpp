/*input
3
1 2 3
1 2 3

*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	pair<ll, ll> a[n];
	map<ll, ll>M;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i].first;
		M[a[i].first]++;
	}
	ll suma = 0;
	ll k = 0;
	vector<ll>yra;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i].second;
		if (M[a[i].first] >= 2)
		{
			suma += a[i].second;
			k++;
			yra.push_back(a[i].first);
		}
	}
	for (ll i = 0; i < n; i++)
	{
		if (M[a[i].first] == 1)
		{
			bool geresnis = true;
			for (ll j : yra)
			{
				if ((j & a[i].first) == a[i].first)
					geresnis = false;
			}
			if (geresnis == false)
			{
				yra.push_back(a[i].first);
				suma += a[i].second;
				k++;
			}
		}
	}
	ll ans = 0;
	if (k >= 2)
		ans = suma;
	cout << ans << "\n";
}