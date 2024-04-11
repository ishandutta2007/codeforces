/*input
3 3
9 9 9 9 9 9 9 9 9
1 2 3
1 2 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, k;
	cin >> n >> k;
	map<ll, ll>kortos;
	ll kiekis = n * k;
	while (kiekis--)
	{
		ll a;
		cin >> a;
		if (kortos.count(a))
			kortos[a]++;
		else
			kortos[a] = 1;
	}
	map<ll, ll>kiek;
	for (ll i = 0; i < n; i++)
	{
		ll f;
		cin >> f;
		if (kiek.count(f))
			kiek[f]++;
		else
			kiek[f] = 1;
	}
	ll h[k + 1];
	for (ll i = 1; i <= k; i++)
		cin >> h[i];
	h[0] = 0;
	ll ans = 0;
	ll DP[n + 1][n * k + 1];
	for (ll i = 0; i <= n; i++)
		for (ll j = 0; j <= n * k; j++)
			DP[i][j] = 0;
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 0; j <= n * k; j++)
		{
			for (ll a = 0; a <= j && a <= k; a++)
			{
				DP[i][j] = max(DP[i][j], DP[i - 1][j - a] + h[a]);
			}
		}
	}
	for (pair<ll, ll>a : kiek)
	{
		ll n = a.second;
		ll kk = kortos[a.first];
		kk = min(kk, n * k);
		ans += DP[n][kk];
	}
	cout << ans << "\n";


}