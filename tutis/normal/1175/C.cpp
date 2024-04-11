/*input
3
3 2
1 2 5
2 1
1 1000000000
1 0
4
*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		ll n, k;
		cin >> n >> k;
		k++;
		ll mini = 2e18;
		ll x = 0;
		ll a[n];
		for (ll i = 0; i < n; i++)
			cin >> a[i];
		for (ll i = 0; i + k - 1 < n; i++)
		{
			ll d1 = a[i];
			ll d2 = a[i + k - 1];
			if (d2 - d1 < mini)
			{
				mini = d2 - d1;
				x = (d1 + d2) / 2;
			}
		}
		cout << x << "\n";
	}

	return 0;
}