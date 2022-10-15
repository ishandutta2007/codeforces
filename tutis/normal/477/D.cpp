/*input
100000000000000000000
*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll modulo = 1000000007;
ll conv(const string &s)
{
	ll ret = 0;
	ll w = 1;
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '1')
		{
			ret += w;
			ret %= modulo;
		}
		w *= 2;
		w %= modulo;
	}
	return ret;
}
ll dp[5050][5050];
int prn[5050][5050];
int kitoks[5050][5050];
int main()
{
	string s;
	cin >> s;
	int n = s.size();
	s = "0" + s;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = 0;
			prn[i][j] = n + 3;
		}
	}
	for (int i = n; i >= 0; i--)
	{
		for (int j = 0; j <= n; j++)
		{
			if (s[i] != s[j])
			{
				kitoks[i][j] = 0;
			}
			else
			{
				if (i + 1 <= n && j + 1 <= n)
					kitoks[i][j] = 1 + kitoks[i + 1][j + 1];
				else
					kitoks[i][j] = n + 10;
			}
		}
	}
	dp[0][0] = 1;
	prn[0][0] = 0;
	for (int j = 0; j <= n; j++)
	{
		for (int i = 0; i <= j; i++)
		{
			if (s[i] == '0' && j != i)
				continue;
			if (prn[i][j] >= n + 3)
				continue;
			dp[i][j] %= modulo;
			if (j != 0)
			{
				dp[i][j + 1] += dp[i][j];
				prn[i][j + 1] = min(prn[i][j], prn[i][j + 1]);
			}
			int lo = j - i + 1;
			int hi = min(n - j, lo + 2);
			for (int sz = lo; sz <= hi; sz++)
			{
				if (sz > 1 && s[j + 1] == '0')
					continue;
				int kiek = kitoks[i][j + 1];
				if ((sz > lo || (kiek >= sz)) || s[i + kiek] <= s[j + 1 + kiek])
				{
					dp[j + 1][j + sz] += dp[i][j];
					prn[j + 1][j + sz] = min(prn[j + 1][j + sz], prn[i][j] + 1);
					break;
				}
			}
		}
	}
	ll ans = 0;
	for (int j = 1; j <= n; j++)
		ans += dp[j][n];
	ans %= modulo;
	cout << ans << "\n";
	ans = -1;
	for (int l = 1; l <= n; l++)
	{
		if (prn[n - l + 1][n] >= n + 3)
			continue;
		if (ans == -1)
		{
			ans = (prn[n - l + 1][n] + conv(s.substr(n - l + 1, l))) % modulo;
		}
		else if (l <= 25)
			ans = min(ans, prn[n - l + 1][n] + conv(s.substr(n - l + 1, l)));
	}
	cout << ans << "\n";
}