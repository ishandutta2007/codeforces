/*input
5
1 2 0 2 1
3
1 0 1

*/
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	int n;
	cin >> n;
	int a[n + 1];
	a[0] = -1;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int m;
	cin >> m;
	int b[m + 1];
	b[0] = -1;
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	int dp[n + 1][n + 1];
	int pag[n + 1][n + 1];
	for (int i = 0; i <= n; i++)
	{
		for (int k = 0; k <= n; k++)
		{
			dp[i][k] = 1000;
		}
	}
	dp[0][0] = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n; k++)
		{
			int J = 1000;
			for (int j = 0; j < i; j++)
				if (a[j] < a[i])
				{
					J = min(J, dp[j][k - 1]);
					if (J == dp[j][k - 1])
						pag[i][k] = j;
				}
			for (int j = J + 1; j <= m; j++)
			{
				if (b[j] == a[i])
				{
					dp[i][k] = j;
					break;
				}
			}
		}
	}
	for (int k = n; k >= 0; k--)
	{
		for (int i = 0; i <= n; i++)
		{
			if (dp[i][k] <= m)
			{
				cout << k << "\n";
				vector<int>ans;
				while (i != 0)
				{
					ans.push_back(a[i]);
					i = pag[i][k];
					k--;
				}
				reverse(ans.begin(), ans.end());
				for (int x : ans)
					cout << x << " ";
				return 0;
			}
		}
	}
}