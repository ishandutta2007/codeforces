/***
9
2 1 3 5 4 1 2 3 1
***/
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll x = *(min_element(a, a + n));
	ll nuo = -n * 2 - 10;
	ll ans = n + 1;
	for (ll i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			ans = min(ans, i - nuo);
			nuo = i;
		}
	}
	cout << ans;
}