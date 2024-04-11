/*input
2 7
3 4
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ll n, M;
	cin >> n >> M;
	ll N = n;
	ll a[n + 10];
	a[0] = 0;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	a[n + 1] = a[n + 2] = a[n + 3] = a[n + 4] = a[n + 5] = M;
	n++;
	if (n % 2 == 0)
		n++;
	ll suma[n + 2];
	suma[0] = 0;
	for (ll j = 1; j <= n + 1; j++)
	{
		if (j % 2 == 1)
		{
			suma[j] = suma[j - 1] + a[j] - a[j - 1];
		}
		else
			suma[j] = suma[j - 1];
	}
	ll sumb[n + 2];
	sumb[n + 1] = 0;
	for (ll j = n; j >= 0; j--)
	{
		if (j % 2 == 0)
		{
			sumb[j] = sumb[j + 1] + a[j + 1] - a[j];
		}
		else
			sumb[j] = sumb[j + 1];
	}
	ll ans = suma[n + 1];
	for (ll i = 0; i <= n; i++)
	{
		if (i % 2 == 1)
		{
			ll gal = suma[i];
			gal -= sumb[i + 1];
			gal += M - (a[i] + 1);
			if (a[i + 1] > a[i] + 1 || (i - 1 >= 0 && a[i] > a[i - 1] + 1))
			{
				ans = max(ans, gal);
			}
		}
	}


	cout << ans << "\n";
}