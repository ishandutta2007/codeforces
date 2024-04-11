/*input
10
3 62 24 39
1 17
1 99
1 60
1 64
1 30
2 79 29
2 20 73
2 85 37
1 100

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	ll n;
	cin >> n;
	vector<ll>a[n];
	ll ans = n * n;
	for (ll i = 0; i < n; i++)
	{
		ll l;
		cin >> l;
		while (l--)
		{
			ll x;
			cin >> x;
			a[i].push_back(x);
		}
	}
	vector<ll>b;
	for (ll i = 0; i < n; i++)
	{
		bool ok = true;
		for (ll t = 1; t < (ll)a[i].size(); t++)
			ok &= a[i][t] <= a[i][t - 1];
		if (ok)
		{
			b.push_back(a[i][0]);
		}
	}
	sort(b.begin(), b.end());
	for (ll i = 0; i < n; i++)
	{
		bool ok = true;
		for (ll t = 1; t < (ll)a[i].size(); t++)
			ok &= a[i][t] <= a[i][t - 1];
		if (ok)
		{
			auto it = lower_bound(b.begin(), b.end(), a[i].back() + 1);
			ans -= it - b.begin();
		}
	}
	cout << ans << "\n";
}