/*input
5 5
1 10 100 1000 10000

*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll a[1000];
ll sk;
ll dps(ll i, ll k);
int mn[1000];
ll dp(ll i, ll k)
{
	if (sk * (k - 1) > 100000 || k > i + 1)
		return 0;
	if (k == 1)
		return 1;
	return dps(mn[i] - 1, k - 1);
}
int D[1111][1111];
ll dps(ll i, ll k)
{
	if (i < 0)
		return 0;
	if (sk * (k - 1) > 100000 || k > i + 1)
		return 0;
	if (D[i][k] != -1)
		return D[i][k];
	ll ret = dps(i - 1, k) + dp(i, k);
	if (ret >= mod)
		ret -= mod;
	return D[i][k] = ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		mn[i] = i;
	sort(a, a + n);
	ll ans = 0;
	for (sk = 1; sk <= 100000; sk++)
	{
		for (ll i = 0; i < n; i++)
			while (mn[i] > 0 && a[i] - a[mn[i] - 1] < sk)
				mn[i]--;
		for (int i = 0; i < 1000; i++)
		{
			for (int k = 1; sk * (k - 1) <= 100000 && k <= 1000; k++)
			{
				D[i][k] = -1;
			}
		}
		for (ll i = 0; i < n; i++)
		{
			ans += dp(i, k);
			ans %= mod;
			if (ans < 0)
				ans += mod;
		}
	}
	cout << ans << "\n";
}