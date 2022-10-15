/*input
6
4 7 1 5 4 9
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll a[n];
	map<ll, ll>K;
	for (ll i = 0; i < n; i++)
	{
		cin >> a[i];
		K[a[i]]++;
	}
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		bool geras = false;
		K[a[i]]--;
		for (ll t = 1; t <= 3e9; t *= 2)
		{
			if (K.count(t - a[i]) && K[t - a[i]] > 0)
				geras = true;
		}
		if (geras == false)
			ans++;
		K[a[i]]++;
	}
	cout << ans << "\n";
}