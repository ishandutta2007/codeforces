/***
4
4 2 4 3
***/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + (n));
	ll ans = n;
	bool uzimta[n + 1];
	fill_n(uzimta, n + 1, false);
	for (ll i = 0; i < n; i++)
	{
		for (ll j = i + 1; j < n; j++)
		{
			if (a[i] < a[j] && uzimta[j] == false)
			{
				uzimta[j] = true;
				ans--;
				break;
			}
		}
	}
	cout << ans;
}