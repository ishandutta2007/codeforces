/*input
2 2
1 2
2 1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	ll ans = n;
	ll a[m][n];
	for (ll j = 0; j < m; j++)
		for (ll i = 0; i < n; i++)
			cin >> a[j][i];
	ll kur[m][n];
	for (ll j = 0; j < m; j++)
	{
		for (ll i = 0; i < n; i++)
			kur[j][a[j][i]] = i;
	}
	ll kiek = 1;
	ll I[m];
	I[0] = n - 1;
	for (ll j = 1; j < m; j++)
		I[j] = kur[j][a[0][I[0]]];
	for (I[0] = n - 2; I[0] >= 0; I[0]--)
	{
		bool ok = true;
		for (ll j = 1; j < m; j++)
		{
			ll xx = kur[j][a[0][I[0]]];
			ok &= (I[j] == xx + 1);
			I[j] = xx;
		}
		if (ok)
			kiek++;
		else
			kiek = 1;
		ans += kiek - 1;
	}
	cout << ans << "\n";
}