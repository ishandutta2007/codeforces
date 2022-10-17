#include <bits/stdc++.h>
using namespace std;
int t, p, n, o, x, y;
vector<pair<int, int> > a[300020];
int c[300020];
int z[300020];
void dfs(int x, int y, int d)
{
	for (auto i: a[x])
	{
		if (i.first != y)
		{
			if (d & 1)
			{
				z[i.second] = ++o;
				c[i.first] = o + n;
			}
			else
			{
				z[i.second] = ++o + n;
				c[i.first] = o;
			}
			dfs(i.first, x, d + 1);
		}
	}
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &p);
		n = (1 << p);
		o = 0;
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			a[x].push_back(make_pair(y, i));
			a[y].push_back(make_pair(x, i));
		}
		c[1] = n;
		dfs(1, 0, 0);
		printf("%d\n", 1);
		for (int i = 1; i <= n; i++)
		{
			printf("%d%c", c[i], i == n ? '\n' : ' ');
		}
		for (int i = 1; i < n; i++)
		{
			printf("%d%c", z[i], i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}