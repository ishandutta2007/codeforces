/*input
5
1 2 3 2 2
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll DP[5000][2525][2];
ll MN[5000][2525];
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0), cerr.tie(0);
	int n;
	cin >> n;
	ll a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int K = (n + 1) / 2;
	const ll INF = 1e12;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= K; j++)
		{
			DP[i][j][0] = DP[i][j][1] = INF;
			MN[i][j] = INF;
		}
	}
	for (int i = 0; i < n; i++)
	{
		DP[i][0][0] = 0;
		if (i == 0)
		{
			DP[i][1][1] = 0;
			for (int k = 0; k <= K; k++)
			{
				if (i != n - 1)
					MN[i][k] = DP[i][k][1] + max(0ll, a[i + 1] - a[i] + 1);
				else
					MN[i][k] = DP[i][k][1];
			}
			continue;
		}
		if (i == 1)
		{
			DP[i][1][1] = max(0ll, a[i - 1] - a[i] + 1);
			if (a[i - 1] > a[i])
				DP[i][1][0] = 0;
			for (int k = 0; k <= K; k++)
			{
				if (i != n - 1)
					MN[i][k] = min(MN[i - 1][k], DP[i][k][1] + max(0ll, a[i + 1] - a[i] + 1));
				else
					MN[i][k] = min(MN[i - 1][k], DP[i][k][1]);
			}
			continue;
		}
		for (int j = 1; j <= K; j++)
		{
			DP[i][j][0] = DP[i - 1][j][0];
			if (a[i - 1] > a[i])
				DP[i][j][0] = min(DP[i][j][0], DP[i - 1][j][1]);
			DP[i][j][1] = DP[i - 1][j - 1][0] + max(0ll, a[i - 1] - a[i] + 1);
			DP[i][j][1] = min(DP[i][j][1],
			                  DP[i - 2][j - 1][1] +
			                  max({0ll, a[i - 1] - a[i] + 1, a[i - 1] - a[i - 2] + 1}));
			DP[i][j][1] = min(DP[i][j][1],
			                  MN[i - 2][j - 1] +
			                  max(0ll, a[i - 1] - a[i] + 1));
		}
		for (int k = 0; k <= K; k++)
		{
			if (i != n - 1)
				MN[i][k] = min(MN[i - 1][k], DP[i][k][1] + max(0ll, a[i + 1] - a[i] + 1));
			else
				MN[i][k] = min(MN[i - 1][k], DP[i][k][1]);
		}
	}
	for (int k = 1; k <= (n + 1) / 2; k++)
	{
		ll ans = min(DP[n - 1][k][0], MN[n - 1][k]);
		cout << ans << " ";
	}
}