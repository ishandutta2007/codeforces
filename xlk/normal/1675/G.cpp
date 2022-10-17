#include <bits/stdc++.h>
using namespace std;
int n, m;
int s[260];
int f[260][260];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i];
		s[i] += s[i - 1];
	}
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	for (int i = m; i >= 0; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = i; k <= m; k++)
			{
				f[j][k] = min(f[j][k], f[j - 1][k - i] + abs(s[j] - k));
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}