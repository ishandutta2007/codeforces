/***
4 20
10 3 6 3
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n, d;
	cin >> n >> d;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ll ans = 0;
	for (ll i = 0; i < n; i++)
	{
		while (d * 2 < a[i])
		{
			d *= 2;
			ans++;
		}
		if (d * 2 >= a[i])
		{
			d = max(d, a[i]);
		}
	}
	cout << ans;
}