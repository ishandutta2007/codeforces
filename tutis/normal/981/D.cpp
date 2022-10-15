/*input
7 3
3 14 15 92 65 35 89
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	ll a[n + 1];
	ll S[n + 1];
	S[0] = 0;
	a[0] = 0;
	for (ll i = 1; i <= n; i++)
	{
		cin >> a[i];
		S[i] = S[i - 1] + a[i];
	}
	ll msk = 0;
	for (ll bit = (1ll << 60); bit >= 1; bit /= 2)
	{
		ll tikrinam = msk + bit;
		bool DP[n + 1][k + 1];
		for (ll i = 0; i <= n; i++)
			for (ll j = 0; j <= k; j++)
				DP[i][j] = false;
		DP[0][0] = true;
		for (ll i = 0; i <= n; i++)
		{
			for (ll j = 0; j < k; j++)
			{
				if (DP[i][j] == false)
					continue;
				for (ll r = i + 1; r <= n; r++)
				{
					if (((tikrinam & (S[r] - S[i])) == tikrinam))
						DP[r][j + 1] = true;
				}
			}
		}
		if (DP[n][k])
			msk += bit;
	}
	cout << msk << endl;
}