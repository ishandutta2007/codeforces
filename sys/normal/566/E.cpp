#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, cnt;
bitset <Maxn> Bi[Maxn], G[Maxn];
pair <int, int> edge[Maxn];
bool vis[Maxn], E[Maxn][Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int c;
		scanf("%d", &c);
		while (c--)
		{
			int x;
			scanf("%d", &x);
			Bi[i].set(x);
		}
		G[i].set(i);
	}
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			bitset <Maxn> tmp = Bi[i] & Bi[j];
			if (tmp.count() == 2)
			{
				int x = tmp._Find_first();
				int y = tmp._Find_next(x);
				if (E[x][y]) continue;
				G[x].set(y), G[y].set(x);
				E[x][y] = E[y][x] = true;
				edge[++cnt] = make_pair(x, y);
				vis[x] = true, vis[y] = true;
			}
		}
	if (!cnt)
		for (int i = 2; i <= n; i++)
			edge[++cnt] = make_pair(i, 1);
	else if (cnt == 1)
	{
		for (int i = 1; i <= n; i++)
			if ((int) Bi[i].count() != n)
			{
				Bi[i].set(edge[1].first, 0), Bi[i].set(edge[1].second, 0);
				for (int j = 1; j <= n; j++)
				{
					if (j == edge[1].first || j == edge[1].second) continue;
					if (Bi[i][j])
						edge[++cnt] = make_pair(edge[1].first, j);
					else edge[++cnt] = make_pair(edge[1].second, j);
				}
				break;
			}
	}
	else
	{
		for (int i = 1; i <= n; i++)
			if (!vis[i])
			{
				int mini = 0x3f3f3f3f, pos = 0;
				for (int j = 1; j <= n; j++)
					if (Bi[j][i] && (int) Bi[j].count() < mini) mini = Bi[j].count(), pos = j;
				for (int j = 1; j <= n; j++)
					if (!vis[j])
						Bi[pos].set(j, 0);
				for (int j = 1; j <= n; j++)
					if (vis[j] && Bi[pos] == G[j])
					{
						edge[++cnt] = make_pair(i, j);
						break;
					}
			}
	}
	for (int i = 1; i <= n - 1; i++)
		printf("%d %d\n", edge[i].first, edge[i].second);
	return 0;
}