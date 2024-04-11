/*input
3 2
2 4 5
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modulo = 1000000007;
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	ll a[n + 1];
	a[0] = 0;
	for (ll i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	ll DP[2][n + 5][k + 5];
	for (ll i = 0; i < 2; i++)
	{
		for (ll j = 0; j < n + 5; j++)
		{
			for (ll c = 0; c < k + 5; c++)
				DP[i][j][c] = 0;
		}
	}
	DP[0][0][0] = 1;
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j <= n; j++)
		{
			ll pap = (a[i + 1] - a[i]) * j;
			for (ll c = 0; c + pap <= k; c++)
			{
				DP[i % 2][j][c] %= modulo;
				DP[(i + 1) % 2][j + 1][c + pap] += DP[i % 2][j][c];
				DP[(i + 1) % 2][j][c + pap] += DP[i % 2][j][c] * (j + 1);
				if (j - 1 >= 0)
				{
					DP[(i + 1) % 2][j - 1][c + pap] += DP[i % 2][j][c] * j;
				}
			}
		}
		for (ll j = 0; j <= n; j++)
			for (ll c = 0; c <= k; c++)
				DP[i % 2][j][c] = 0;
	}

	ll ans = 0;
	for (ll c = 0; c <= k; c++)
	{
		ans += DP[n % 2][0][c];
		ans %= modulo;
	}
	cout << ans << "\n";
}/**/