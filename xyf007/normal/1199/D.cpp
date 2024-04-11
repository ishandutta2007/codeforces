#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, a[200001], m, l, last[200001];
struct op
{
	int k, x, c;
} b[200001];
bool vis[200001];
void checkmax(int &x, int y)
{
	if (x < y)
	{
		x = y;
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d", &b[i].k, &b[i].x);
		if (b[i].k == 1)
		{
			scanf("%d", &b[i].c);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		last[i] = a[i];
	}
	for (int i = m; i >= 1; i--)
	{
		if (b[i].k == 2)
		{
			checkmax(l, b[i].x);
		}
		else
		{
			if (vis[b[i].x])
			{
				continue;
			}
			last[b[i].x] = max(l, b[i].c);
			vis[b[i].x] = 1;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			checkmax(last[i], l);
		}
		printf("%d ", last[i]);
	}
	return 0;
}