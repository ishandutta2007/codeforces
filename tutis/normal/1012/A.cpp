/*input
4
4 1 3 2 3 2 1 3
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << "0\n";
		return 0;
	}
	ll a[n * 2];
	for (int i = 0; i < n * 2; i++)
		cin >> a[i];
	sort(a, a + 2 * n);
	ll ans = 3e18;
	for (ll b = 1; b + n - 1 < 2 * n - 1; b++)
		ans = min(ans, (a[2 * n - 1] - a[0]) * (a[b + n - 1] - a[b]));
	for (ll b = 1; b <= n; b++)
	{
		ll x = n;
		if (b == n)
			x--;
		ans = min(ans, (a[2 * n - 1] - a[b]) * (a[x] - a[0]));
	}

	cout << ans << "\n";
}