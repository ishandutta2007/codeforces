#include <bits/stdc++.h>
using namespace std;
int t, n, z;
int l[200020];
int r[200020];
vector<int> a[200020];
void dfs(int x)
{
	long long sr = 0;
	for (int i : a[x])
	{
		dfs(i);
		sr += r[i];
	}
	if (l[x] > sr)
	{
		z++;
	}
	else
	{
		if (r[x] > sr)
		{
			r[x] = sr;
		}
	}
}
int main()
{
	scanf("%d", &t);
	for (int tt = 0; tt < t; tt++)
	{
		scanf("%d", &n);
		for (int i = 0; i <= n; i++)
		{
			a[i].clear();
		}
		for (int i = 2; i <= n; i++)
		{
			int x;
			scanf("%d", &x);
			a[x].push_back(i);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &l[i], &r[i]);
		}
		z = 0;
		dfs(1);
		printf("%d\n", z);
	}
	return 0;
}