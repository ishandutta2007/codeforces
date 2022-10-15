/*input
10 3
1 1 2
1 1 3
1 1 6
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modulo = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n, q;
	cin >> n >> q;
	ll WAYS[n + 1];
	vector<ll>ins[n + 2];
	vector<ll>era[n + 2];
	while (q--)
	{
		ll l, r, x;
		cin >> l >> r >> x;
		ins[l].push_back(x);
		era[r + 1].push_back(x);
	}
	bool gerai[n + 1];
	for (ll i = 0; i <= n; i++)
		gerai[i] = false;
	for (ll i = 1; i <= n; i++)
		WAYS[i] = 0;
	gerai[0] = true;
	WAYS[0] = 1;
	for (ll i = 1; i <= n; i++)
	{
		for (ll x : ins[i])
		{
			for (ll j = n; j - x >= 0; j--)
			{
				WAYS[j] += WAYS[j - x];
				WAYS[j] %= modulo;
			}
		}
		for (ll x : era[i])
		{
			for (ll j = x; j <= n; j++)
			{
				WAYS[j] += modulo - WAYS[j - x];
				WAYS[j] %= modulo;
			}
		}
		for (ll j = 1; j <= n; j++)
			if (WAYS[j] != 0)
				gerai[j] = true;
	}
	ll ans = 0;
	for (ll j = 1; j <= n; j++)
		if (gerai[j])
			ans++;
	cout << ans << "\n";
	for (ll j = 1; j <= n; j++)
		if (gerai[j])
			cout << j << " ";

}