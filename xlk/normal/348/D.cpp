#include <bits/stdc++.h>
using namespace std;
const int p = 1000000007;
int n, m;
char s[3020];
int f[3020][3020]; // from (1, 2) to every other point
int g[3020][3020]; // from (2, 1) to every other point
int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m;
	f[0][2] = 1;
	g[2][0] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		for (int j = 1; j <= m; j++)
		{
			if (s[j - 1] == '.')
			{
				f[i][j] = (f[i - 1][j] + f[i][j - 1]) % p;
				g[i][j] = (g[i - 1][j] + g[i][j - 1]) % p;
			}
		}
	}
	cout << ((long long)f[n - 1][m] * g[n][m - 1] % p + p - (long long)g[n - 1][m] * f[n][m - 1] % p) % p << endl;
	return 0;
}