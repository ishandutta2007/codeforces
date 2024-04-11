#include <bits/stdc++.h>
using namespace std;
int n, a;
int f[100020];
int g[100020];
int h[100020];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (a & 2)
		{
			f[i] = min(g[i - 1], h[i - 1]);
		}
		else
		{
			f[i] = 1e9;
		}
		if (a & 1)
		{
			g[i] = min(f[i - 1], h[i - 1]);
		}
		else
		{
			g[i] = 1e9;
		}
		h[i] = min(min(f[i - 1], g[i - 1]), h[i - 1]) + 1;
	}
	cout << min(min(f[n], g[n]), h[n]) << endl;
	return 0;
}