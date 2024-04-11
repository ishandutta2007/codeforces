#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, cnt, deg[Maxn], head[Maxn];
bool del[Maxn];
queue <int> Qu;
struct edg
{
	int nxt, to;
} edge[2 * Maxn];
void add(int x, int y)
{
	edge[++cnt] = (edg){head[x], y};
	head[x] = cnt;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		deg[x]++, deg[y]++;
		add(x, y), add(y, x);
	}
	for (int i = 1; i <= n; i++)
		if (deg[i] == 1) Qu.push(i);
	int ct = n;
	while (ct >= 2)
	{
		int x = Qu.front();
		Qu.pop();
		int y = Qu.front();
		Qu.pop();
		printf("? %d %d\n", x, y);
		fflush(stdout);
		int res;
		scanf("%d", &res);
		if (res == x || res == y)
		{
			printf("! %d\n", res);
			fflush(stdout);
			return 0;
		}
		ct -= 2;
		del[x] = del[y] = true;
		for (int i = head[x]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (!del[to])
			{
				deg[to]--;
				if (deg[to] == 1) Qu.push(to);
			}
		}
		for (int i = head[y]; i; i = edge[i].nxt)
		{
			int to = edge[i].to;
			if (!del[to])
			{
				deg[to]--;
				if (deg[to] == 1) Qu.push(to);
			}
		}
	}
	for (int i = 1; i <= n; i++)
		if (!del[i])
		{
			printf("! %d\n", i);
			fflush(stdout);
			return 0;
		}
	return 0;
}