#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int f[60];
int F(int x)
{
	return f[x] != x ? f[x] = F(f[x]) : x;
}
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x = F(x);
		y = F(y);
		if (x != y)
		{
			f[x] = y;
		}
	}
	int z = n;
	for (int i = 1; i <= n; i++)
	{
		if (f[i] == i)
		{
			z--;
		}
	}
	cout << (1LL << z) << endl;
	return 0;
}