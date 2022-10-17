#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, z;
int d[320][320];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> d[i][j];
		}
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	cin >> m;
	for (int k = 0; k < m; k++)
	{
		cin >> x >> y >> z;
		d[x][y] = min(d[x][y], z);
		d[y][x] = min(d[y][x], z);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], d[i][x] + d[x][j]);
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				d[i][j] = min(d[i][j], d[i][y] + d[y][j]);
			}
		}
		long long z = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j < i; j++)
			{
				z += d[i][j];
			}
		}
		cout << z << " ";
	}
	return 0;
}