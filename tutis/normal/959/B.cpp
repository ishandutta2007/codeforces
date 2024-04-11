/*input
5 4 4
i loser am the second
100 20 1 5 10
1 1
1 3
2 2 5
1 4
i am the second
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, k, m;
	cin >> n >> k >> m;
	string a[n + 1];
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	ll c[n + 1];
	for (ll i = 1; i <= n; i++)
		cin >> c[i];
	map<string, ll>CC;
	while (k--)
	{
		ll x;
		cin >> x;
		ll cost = LONG_LONG_MAX / 2;
		vector<ll>XX;
		while (x--)
		{
			ll a;
			cin >> a;
			XX.push_back(a);
			cost = min(cost, c[a]);
		}
		for (ll i : XX)
			CC[a[i]] = cost;
	}
	ll ans = 0;
	while (m--)
	{
		string xx;
		cin >> xx;
		ans += CC[xx];
	}
	cout << ans << "\n";
}