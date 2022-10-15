/***
3
111
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	string s;
	cin >> s;
	ll a[n];
	for (ll i = 0; i < n; i++)
	{
		if (s[i] == '0')
		{
			a[i] = -1;
		}
		else
		{
			a[i] = 1;
		}
	}
	ll D[n];
	D[0] = a[0];
	for (ll i = 1; i < n; i++)
		D[i] = D[i - 1] + a[i];
	map<ll, ll>mini;
	map<ll, ll>maxi;
	mini[0] = -1;
	maxi[0] = -1;
	multiset<ll>X;
	X.insert(0);
	X.insert(0);
	for (ll i = 0; i < n; i++)
		X.insert(D[i]);
	for (ll i = 0; i < n; i++)
	{
		if (mini.count(D[i]) == 0)
			mini[D[i]] = i;
		mini[D[i]] = min(mini[D[i]], i);
	}
	for (ll i = 0; i < n; i++)
	{
		if (maxi.count(D[i]) == 0)
			maxi[D[i]] = i;
		maxi[D[i]] = max(maxi[D[i]], i);
	}
	ll ans = 0;
	for (ll i = -n; i <= n; i++)
		if (X.count(i) >= 2)
			ans = max(ans, maxi[i] - mini[i]);
	cout << ans;
}