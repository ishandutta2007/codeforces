/*input
10 100
ajihiushda

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll dp[100][101];
ll kiek[101];
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	string s;
	cin >> n >> k >> s;
	for (ll i = 0; i < n; i++)
	{
		dp[i][1] = 1;
		set<char>buvau;
		for (ll j = i - 1; j >= 0; j--)
		{
			if (buvau.count(s[j]))
				continue;
			for (ll l = 2; l <= n; l++)
			{
				dp[i][l] += dp[j][l - 1];
				dp[i][l] = min(dp[i][l], k);
			}
			buvau.insert(s[j]);
		}
	}
	set<char>buvau;
	for (ll j = n - 1; j >= 0; j--)
	{
		if (buvau.count(s[j]))
			continue;
		for (ll l = 1; l <= n; l++)
		{
			kiek[l] += dp[j][l];
			kiek[l] = min(kiek[l], k);
		}
		buvau.insert(s[j]);
	}
	ll ans = 0;
	kiek[0] = 1;
	for (ll l = n; l >= 0; l--)
	{
		ll x = min(k, kiek[l]);
		ans += (n - l) * x;
		k -= x;
	}
	if (k != 0)
		ans = -1;
	cout << ans << "\n";
}