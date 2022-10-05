#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;
int T, n, m, cnt, fa[Maxn];
bitset <Maxn> Bi[Maxn];
vector <int> G[Maxn];
int get_fa(int x)
{
	return x == fa[x] ? x : fa[x] = get_fa(fa[x]);
}
struct edg
{
	int x, y, w;
	bool operator < (const edg &tmp) const
	{
		return w > tmp.w;
	}
} edge[Maxn * Maxn];
int main()
{
	scanf("%d", &T);
	while (T--)
	{
		cnt = 0;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) G[i].clear(), Bi[i].reset();
		for (int i = 1; i <= m; i++)
		{
			string str;
			cin >> str;
			for (int j = 1; j <= n; j++)
				Bi[j][i] = str[j - 1] - '0';
		}
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				edge[++cnt] = (edg){i, j, (int) (Bi[i] & Bi[j]).count()};
		sort(edge + 1, edge + 1 + cnt);
		for (int i = 1; i <= n; i++) fa[i] = i;
		for (int i = 1; i <= cnt; i++)
			if (get_fa(edge[i].x) != get_fa(edge[i].y))
				fa[get_fa(edge[i].x)] = get_fa(edge[i].y), G[edge[i].x].push_back(edge[i].y), G[edge[i].y].push_back(edge[i].x);
		for (int i = 1; i <= m; i++)
		{
			int tot = 0;
			for (int u = 1; u <= n; u++)
			{
				if (Bi[u][i])
				{
					tot++;
					for (auto to : G[u])
						if (u < to && Bi[to][i]) tot--;
				}
			}
			if (tot != 1)
			{
				puts("NO");
				goto END;
			}
		}
		puts("YES");
		for (int u = 1; u <= n; u++)
			for (auto to : G[u])
				if (u < to) printf("%d %d\n", u, to);
		END:;
	}
	return 0;
}