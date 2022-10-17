#include <bits/stdc++.h>
using namespace std;
int n, m, ss;
vector<int> a[200020];
int c[200020];
int d[200020];
int l[200020];
int r[200020];
int w[200020];
void change(int x, int y)
{
	for (; x <= n; x += x & -x)
	{
		c[x] += y;
	}
}
int query(int x)
{
	int re = 0;
	for (; x > 0; x -= x & -x)
	{
		re += c[x];
	}
	return re;
}
void dfs(int x, int y)
{
	l[x] = ss++;
	d[x] = d[y] + 1;
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x);
		}
	}
	r[x] = ss;
}
int main()
{
	ss = 1;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &w[i]);
	}
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 0; i < m; i++)
	{
		int o, x, y;
		scanf("%d%d", &o, &x);
		if (o == 1)
		{
			scanf("%d", &y);
			if (d[x] & 1)
			{
				y = -y;
			}
			change(l[x], y);
			change(r[x], -y);
		}
		else
		{
			printf("%d\n", w[x] + (d[x] & 1 ? -query(l[x]) : query(l[x])));
		}
	}
	return 0;
}