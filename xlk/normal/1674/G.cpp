#include <bits/stdc++.h>
using namespace std;
vector<int> a[200020];
int d[200020];
int f[200020];
int n, m, x, y;
int F(int x)
{
	if (f[x] > 0)
	{
		return f[x];
	}
	f[x] = 1;
	if (a[x].size() <= 1)
	{
		return f[x];
	}
	for (int i: a[x])
	{
		if (d[i] > 1)
		{
			f[x] = max(f[x], F(i) + 1);
		}
	}
	return f[x];
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		d[y]++;
	}
	int z = 0;
	for (int i = 1; i <= n; i++)
	{
		z = max(z, F(i));
	}
	printf("%d\n", z);
	return 0;
}