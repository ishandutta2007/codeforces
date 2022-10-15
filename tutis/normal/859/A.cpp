/***
3
14 15 92
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll K;
	cin >> K;
	set<ll>x;
	ll iki = 0;
	while (K--)
	{
		ll a;
		cin >> a;
		x.insert(a);
		iki = max(iki, a);
	}
	ll i = 0;
	while (x.size() < 25)
	{
		i++;
		x.insert(i);
		iki = max(iki, i);
	}
	ll ans = 0;
	for (ll i = 1; i <= iki; i++)
	{
		if (!x.count(i))
			ans++;
	}
	cout << ans;
}