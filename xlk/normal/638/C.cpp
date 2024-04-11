#include <bits/stdc++.h>
using namespace std;
int n, x, y, zc;
vector<pair<int, int> > a[200020];
vector<int> z[200020];
void dfs(int x, int y, int c)
{
	int j = 0;
	for (pair<int, int> i: a[x])
	{
		if (i.first != y)
		{
			++j;
			if (j == c)
			{
				++j;
			}
			z[j].push_back(i.second);
			zc = max(zc, j);
			dfs(i.first, x, j);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(make_pair(y, i));
		a[y].push_back(make_pair(x, i));
	}
	dfs(1, 0, 0);
	printf("%d\n", zc);
	for (int i = 1; i <= zc; i++)
	{
		printf("%u", z[i].size());
		for (int j: z[i])
		{
			printf(" %d", j);
		}
		printf("\n");
	}
	return 0;
}