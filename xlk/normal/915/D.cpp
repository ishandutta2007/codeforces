#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<int> a[520];
int in[520];
int d[520];
int q[520], b, f;
bool ok()
{
	b = f = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!d[i])
		{
			q[f++] = i;
		}
	}
	while (b < f)
	{
		int u = q[b++];
		for (int i: a[u])
		{
			if (!--d[i])
			{
				q[f++] = i;
			}
		}
	}
	return f == n;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d", &x, &y);
		a[x].push_back(y);
		in[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		memcpy(d, in, sizeof d);
		d[i]--;
		if (ok())
		{
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}