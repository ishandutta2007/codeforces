/*input
5
100 98 100 100
100 100 100 100
100 100 99 99
90 99 90 100
100 98 60 99
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	pair<ll, ll> a[n];
	for (ll i = 0; i < n; i++)
	{
		a[i].first = 0;
	}
	for (ll i = 0; i < n; i++)
	{
		for (ll t = 0; t < 4; t++)
		{
			ll s;
			cin >> s;
			a[i].first += s;
		}
		a[i].second = n - i;
	}
	ll ans = 1;

	for (ll i = 0; i < n; i++)
		ans += (a[i] > a[0]);
	cout << ans << "\n";

}