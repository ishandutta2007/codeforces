/*input
4 4
0 1 0 1
1 0 1 0
0 1 0 1
1 0 1 0
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, K;
	cin >> n >> K;
	int a[n][n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
		a[i][i] = 1;
	}
	int k = n / 2;
	int dp[1 << k];
	fill_n(dp, 1 << k, 1);
	dp[0] = 0;
	int sz = 1;
	for (int msk = 1; msk < (1 << k); msk++)
	{
		vector<int>A;
		for (int i = 0; i < k; i++)
		{
			if ((msk & (1 << i)) > 0)
				A.push_back(i);
		}
		bool clika = true;
		for (int i : A)
		{
			for (int j : A)
			{
				clika &= a[i][j];
			}
		}
		if (clika)
		{
			dp[msk] = A.size();
		}
		else
		{
			for (int i : A)
			{
				dp[msk] = max(dp[msk], dp[msk ^ (1 << i)]);
			}
		}
		sz = max(sz, dp[msk]);
	}
	int c = n - k;
	for (int msk = 1; msk < (1 << c); msk++)
	{
		vector<int>A;
		for (int i = 0; i < c; i++)
		{
			if ((msk & (1 << i)) > 0)
				A.push_back(k + i);
		}
		bool clika = true;
		for (int i : A)
		{
			for (int j : A)
			{
				clika &= a[i][j];
			}
		}
		if (clika)
		{
			int w = 0;
			for (int i = 0; i < k; i++)
			{
				bool ok = true;
				for (int j : A)
				{
					ok &= a[i][j];
				}
				if (ok)
					w ^= (1 << i);
			}
			sz = max(sz, (int)A.size() + dp[w]);
		}
	}
	cout << fixed << setprecision(30) << (ld(K * K) / ld(sz))*ld((sz - 1)) * 0.5 << "\n";
}