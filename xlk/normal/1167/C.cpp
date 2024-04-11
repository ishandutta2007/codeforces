#include <bits/stdc++.h>
using namespace std;
int n, m, l, x, y;
int f[500020];
int c[500020];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
void U(int x, int y)
{
	x = F(x);
	y = F(y);
	if (x != y)
	{
		f[x] = y;
		c[y] += c[x];
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		c[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> l;
		for (int j = 0; j < l; j++)
		{
			cin >> y;
			if (j > 0)
			{
				U(x, y);
			}
			x = y;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		cout << c[F(i)] << " ";
	}
	return 0;
}