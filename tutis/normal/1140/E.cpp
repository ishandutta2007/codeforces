/*input
4 200000
-1 -1 12345 -1
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modulo = 998244353;
ll ans(vector<ll>a, int k)
{
	int n = a.size();
	ll dp[n][2];
	ll b[n];
	for (int i = 0; i < n; i++)
	{
		b[i] = a[i];
		if (i > 0 && b[i] == -1)
			b[i] = b[i - 1];
	}
	for (int i = n - 2; i >= 0; i--)
	{
		if (b[i] == -1)
			b[i] = b[i + 1];
	}
	if (b[0] == -1)
	{
		ll ret = k;
		for (int i = 1; i < n; i++)
		{
			ret *= (k - 1);
			ret %= modulo;
		}
		return ret;
	}
	if (a[0] == -1)
	{
		dp[0][0] = 1;
		dp[0][1] = 1;
	}
	else
	{
		if (a[0] == b[0])
		{
			dp[0][0] = 1;
			dp[0][1] = 0;
		}
		else
		{
			assert(false);
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i] == -1)
		{
			assert(b[i] == b[i - 1]);
			dp[i][0] = dp[i - 1][1] * (k - 1);
			dp[i][1] = dp[i - 1][1] * (k - 2) + dp[i - 1][0];
		}
		else
		{
			dp[i][0] = 0;
			if (b[i - 1] == a[i])
				dp[i][0] += dp[i - 1][1] * (k - 1);
			else
				dp[i][0] += dp[i - 1][0] + dp[i - 1][1] * (k - 2);
			dp[i][1] = 0;
		}
		dp[i][0] %= modulo;
		dp[i][1] %= modulo;
	}
	return (dp[n - 1][0] + dp[n - 1][1] * (k - 1)) % modulo;
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	vector<ll>a[2];
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		a[i % 2].push_back(x);
	}
	cout << (ans(a[0], k) * ans(a[1], k)) % modulo << '\n';
}