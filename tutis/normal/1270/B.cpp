/*input
3
5
1 2 3 4 5
4
2 0 1 9
2
2019 2020

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
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		ll a[n];
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		pair<ll, ll>ans = { -1, -1};
		for (ll i = 1; i < n; i++)
		{
			if (abs(a[i] - a[i - 1]) >= 2)
			{
				ans = {i, i + 1};
			}
		}
		if (ans.first != -1)
		{
			cout << "YES\n";
			cout << ans.first << " " << ans.second << "\n";
		}
		else
			cout << "NO\n";
	}
}