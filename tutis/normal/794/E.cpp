/*input
20
1 6 4 9 8 6 4 9 2 4 9 3 5 9 6 1 8 4 6 9
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll XXX[300001][11][2];
ll *xxx;
ll answer(ll *a, ll *b, ll k)
{
	if (a == b)
		return a[0];
	if (b - a > 10)
	{
		ll c = (b - a) / 2 - 3;
		return answer(a + c, b - c, k);
	}
	if (XXX[a - xxx][b - a][k] != 0)
		return XXX[a - xxx][b - a][k];

	if (k == 0)
		return XXX[a - xxx][b - a][k] = max(answer(a + 1, b, 1 - k), answer(a, b - 1, 1 - k));
	return XXX[a - xxx][b - a][k] = min(answer(a + 1, b, 1 - k), answer(a, b - 1, 1 - k));
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll n;
	cin >> n;
	ll a[n];
	xxx = a;
	for (ll &i : a)
		cin >> i;
	ll ans[n];
	fill_n(ans, n, 0);
	if (n * n < 50000)
		for (ll i = 0; i < n; i++)
		{
			for (ll j = i; j < n; j++)
			{
				ans[n - (j - i + 1)] = max(ans[n - (j - i + 1)], answer(a + i, a + j, 0));
			}
		}
	for (ll i = 0; i < n; i++)
	{
		if (min(i, n - i) < 10)
			for (ll j = i; j < n; j++)
			{
				ans[n - (j - i + 1)] = max(ans[n - (j - i + 1)], answer(a + i, a + j, 0));
			}
	}
	for (ll i = 0; i < n; i++)
	{
		for (ll j = i; j < n && j < i + 10; j++)
		{
			ans[n - (j - i + 1)] = max(ans[n - (j - i + 1)], answer(a + i, a + j, 0));
		}
	}
	for (ll i = 0; i < n; i++)
	{
		ll c = min(i, n - i);
		for (ll x = i - c - 1; x <= i - c + 1; x++)
		{
			for (ll y = i + c - 1; y <= i + c + 1; y++)
			{
				if (x <= y && x >= 0 && y < n)
					ans[n - (y - x + 1)] = max(ans[n - (y - x + 1)], answer(a + x, a + y, 0));
			}
		}
	}

	for (ll i = 0; i < n; i++)
	{
		if (i - 2 >= 0)
			ans[i] = max(ans[i], ans[i - 2]);
		cout << ans[i] << " ";
	}
}/**/