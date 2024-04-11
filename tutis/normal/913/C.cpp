/***
5 787787787
123456789 234567890 345678901 456789012 987654321
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n, L;
	cin >> n >> L;
	ll c[35];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 1; i < n; i++)
	{
		c[i] = min(c[i], 2 * c[i - 1]);
	}
	for (int i = n; i < 35; i++)
	{
		c[i] = min(LONG_LONG_MAX / 4, 2 * c[i - 1]);
	}
	for (int i = 33; i >= 0; i--)
		c[i] = min(c[i], c[i + 1]);
	ll ans = 0;
	for (ll i = 0; i < 35; i++)
		ans += c[i] * ll((L & (1ll << i)) != 0);
	ll ans2 = 0;
	for (ll i = 34; i >= 0; i--)
	{
		if (((L & (1ll << i)) != 0) == 0)
		{
			ans = min(ans, ans2 + c[i]);
		}
		else
			ans2 += c[i];
	}
	ll k = 1;
	ll i = 0;
	while (k < L)
	{
		k *= 2;
		i++;
	}
	ans = min(ans, c[i]);
	cout << ans << endl;
}