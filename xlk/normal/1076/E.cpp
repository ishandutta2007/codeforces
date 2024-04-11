#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> a[300020];
vector<pair<int, int> > b[300020];
long long c[300020];
long long z[300020];
void dfs(int x, int y, int d)
{
	z[x] = z[y] + c[d];
	for (pair<int, int> i: b[x])
	{
		z[x] += i.second;
		c[min(d + i.first + 1, n)] -= i.second;
	}
	for (int i: a[x])
	{
		if (i != y)
		{
			dfs(i, x, d + 1);
		}
	}
	for (pair<int, int> i: b[x])
	{
		c[min(d + i.first + 1, n)] += i.second;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		b[x].push_back(make_pair(y, z));
	}
	dfs(1, 0, 0);
	for (int i = 1; i <= n; i++)
	{
		printf("%lld%c", z[i], i == n ? '\n' : ' ');
	}
	return 0;
}