#include <bits/stdc++.h>
using namespace std;
int t, n, s, x, y;
vector<int> a[200020];
int f[200020];
int v[200020];
vector<vector<int> > z;
vector<int> b;
void dfs(int x, int y)
{
	b.push_back(x);
	int c = 0;
	for (int i : a[x])
	{
		if (i != y)
		{
			c++;
			dfs(i, x);
		}
	}
	if (c == 0)
	{
		z.push_back(b);
		b.clear();
	}
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			a[i].clear();
		}
		z.clear();
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &x);
			if (x == i)
			{
				s = i;
			}
			else
			{
				a[x].push_back(i);
			}
			v[i] = 0;
		}
		dfs(s, 0);
		printf("%lu\n", z.size());
		for (int i = 0; i < z.size(); i++)
		{
			printf("%lu\n", z[i].size());
			for (int j : z[i])
			{
				printf("%d ", j);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}