/*input
6 8
....*...
...**...
..*****.
...**...
....*...
........
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll yra1[1000 + 2][1000 + 2];
ll yra2[1000 + 2][1000 + 2];
int main()
{
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	string a[n];
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	ll yra[n + 1][m + 1];
	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			yra[i + 1][j + 1] = (a[i][j] == '*');
		}
	}
	ll dp[n + 1][m + 1][4];
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= m; j++)
		{
			if (yra[i][j])
				dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = 0;
			else
				dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = dp[i][j][3] = -3e5;
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= m; j++)
		{
			if (yra[i][j])
			{
				if (i - 1 >= 1)
					dp[i][j][1] = max(dp[i][j][1], dp[i - 1][j][1] + 1);
				if (j - 1 >= 1)
					dp[i][j][2] = max(dp[i][j][2], dp[i][j - 1][2] + 1);
			}
		}
	}
	for (ll i = n; i >= 1; i--)
	{
		for (ll j = m; j >= 1; j--)
		{
			if (yra[i][j])
			{
				if (i + 1 <= n)
					dp[i][j][3] = max(dp[i][j][3], dp[i + 1][j][3] + 1);
				if (j + 1 <= m)
					dp[i][j][0] = max(dp[i][j][0], dp[i][j + 1][0] + 1);
			}
		}
	}
	vector<pair<pair<ll, ll>, ll>>ans;
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= m; j++)
		{
			ll k = min({dp[i][j][0], dp[i][j][1], dp[i][j][2], dp[i][j][3]});
			if (k > 0)
			{
				yra1[i - k][j]++;
				yra1[i + k + 1][j]--;
				yra2[i][j - k]++;
				yra2[i][j + k + 1]--;
				ans.push_back({{i, j}, k});
			}
		}
	}
	for (ll i = 1; i <= n; i++)
	{
		for (ll j = 1; j <= m; j++)
		{
			if (i != 1)
				yra1[i][j] += yra1[i - 1][j];
			if (j != 1)
				yra2[i][j] += yra2[i][j - 1];
			if (yra[i][j] && yra1[i][j] + yra2[i][j] == 0)
			{
				cout << "-1\n";
				return 0;
			}
		}
	}
	cout << ans.size() << "\n";
	for (auto i : ans)
		cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
}