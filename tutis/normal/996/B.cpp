/*input
6
5 2 6 5 7 4
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
	for (ll &i : a)
		cin >> i;
	ll lo = 0;
	ll hi = 1000000009;
	while (lo < hi)
	{
		ll t = (lo + hi + 1) / 2;
		bool ok = true;
		for (ll &i : a)
		{
			i -= t * n;
			if (i <= 0)
				ok = false;
		}
		for (ll &i : a)
			i += t * n;
		if (ok)
		{
			lo = t;
		}
		else
		{
			hi = t - 1;
		}
	}
	ll t = (lo + hi) / 2;
	for (ll &i : a)
		i -= t * n;
	t = 0;
	for (int i = 0;; i = (i + 1) % n)
	{
		if (a[i] - t <= 0)
		{
			cout << i + 1 << "\n";
			return 0;
		}
		t++;
	}
}