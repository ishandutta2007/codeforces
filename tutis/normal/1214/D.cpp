/*input
4 4
....
#.#.
....
.#..

*/
#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	string s[n];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	const ll p = 1023897321;
	int ans = 2;
	ll K[n][m];
	ll G[n][m];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			K[i][j] = 0;
			if (s[i][j] != '.')
				continue;
			if (i + j == 0)
				K[i][j] = 1;
			if (i != 0)
				K[i][j] += K[i - 1][j];
			if (j != 0)
				K[i][j] += K[i][j - 1];
			K[i][j] %= p;
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = m - 1; j >= 0; j--)
		{
			G[i][j] = 0;
			if (s[i][j] != '.')
				continue;
			if (i + j == n - 1 + m - 1)
				G[i][j] = 1;
			if (i != n - 1)
				G[i][j] += G[i + 1][j];
			if (j != m - 1)
				G[i][j] += G[i][j + 1];
			G[i][j] %= p;
		}
	}
	if (K[n - 1][m - 1] == 0)
		ans = 0;
	if (ans == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (i + j == 0 || i + j == n - 1 + m - 1)
					continue;
				if ((K[i][j]*G[i][j]) % p == K[n - 1][m - 1])
					ans = 1;
			}
		}
	}
	cout << ans << "\n";
}