#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
int f[100020];
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
	int z = m;
	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		x = F(x);
		y = F(y);
		if (x != y)
		{
			f[x] = y;
			z--;
		}
	}
	cout << z << endl;
	return 0;
}