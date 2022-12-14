#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 0x3fff3fff3fff3fff;
const int maxn = 1e6 + 10;
string str;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		ll n, a, b, dp[maxn][2];
		cin >> n >> a >> b >> str;
		for (int i = 0; i <= n; i++)dp[i][0] = dp[i][1] = inf;
		str += "0";
		dp[0][0] = b;
		for (int i = 1; i <= n; i++)
		{
			if (str[i - 1] == '0'&&str[i] == '0')
			{
				dp[i][0] = min(dp[i][0], dp[i - 1][0] + a + b);
				dp[i][0] = min(dp[i][0], dp[i - 1][1] + 2 * a + b);
			}
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + 2 * a + 2 * b);
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + a + 2 * b);
		}
		cout << dp[n][0] << endl;
	}
	return 0;
}