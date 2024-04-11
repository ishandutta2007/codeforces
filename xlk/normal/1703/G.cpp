#include <bits/stdc++.h>
using namespace std;
int t, n, k, x;
long long f[40];
long long g[40];
int main()
{
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		cin >> n >> k;
		memset(f, 0, sizeof f);
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			memset(g, 0xc0, sizeof g);
			for (int j = 0; j < 32; j++)
			{
				g[j] = f[j] + (x >> j) - k;
			}
			for (int j = 1; j < 32; j++)
			{
				g[j] = max(g[j], f[j - 1] + (x >> j));
			}
			g[31] = max(g[31], f[31]);
			memcpy(f, g, sizeof f);
		}
		cout << *max_element(f, f + 32) << endl;
	}
	return 0;
}