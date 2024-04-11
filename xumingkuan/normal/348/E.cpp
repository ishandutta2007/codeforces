#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 101010, MAXNUM = 1010101010;
int n, m;
bool sp[MAXN];
class Edge
{
	public:
		int to, v, next;
}e[MAXN * 2];
int head[MAXN], en = 1;
bool visit[MAXN];
void insert()
{
	int u, v, w;
	scanf("%d%d%d", &u, &v, &w);
	e[++en].to = v;
	e[en].v = w;
	e[en].next = head[u];
	head[u] = en;
	e[++en].to = u;
	e[en].v = w;
	e[en].next = head[v];
	head[v] = en;
}
pair <int, int> down[MAXN][3];
int up[MAXN], ups[MAXN], downs[MAXN], ans[MAXN];
void dfs1(int p)
{
	for(int i = 0; i < 3; i++)
		down[p][i].first = -MAXNUM - i;
	if(sp[p])
	{
		down[p][0].first = 0;
		down[p][0].second = p;
	}
	visit[p] = true;
	for(int i = head[p]; i > 0; i = e[i].next)
		if(!visit[e[i].to])
		{
			dfs1(e[i].to);
			const pair <int, int> now = make_pair(down[e[i].to][0].first + e[i].v, e[i].to);
			for(int j = 0; j < 3; j++)
				if(now > down[p][j])
				{
					for(int jj = 2; jj > j; jj--)
						down[p][jj] = down[p][jj - 1];
					down[p][j] = now;
					break;
				}
		}
}
void dfs2(int p)
{
	if(up[p] < 0 && sp[p])
		up[p] = 0;
	visit[p] = true;
	for(int i = head[p]; i > 0; i = e[i].next)
		if(!visit[e[i].to])
		{
			up[e[i].to] = e[i].v + max(up[p], down[p][0].second == e[i].to ? down[p][1].first : down[p][0].first);
			dfs2(e[i].to);
		}
}
void dfs3(int p)
{
	visit[p] = true;
	for(int i = head[p]; i > 0; i = e[i].next)
		if(!visit[e[i].to])
		{
			dfs3(e[i].to);
			if(!ups[e[i].to])
				continue;
			ans[p] += ups[e[i].to];
			const int mx1 = down[p][0].second == e[i].to ? down[p][1].first : down[p][0].first;
			const int mx2 = (down[p][0].second == e[i].to || down[p][1].second == e[i].to) ? down[p][2].first : down[p][1].first;
			if(mx1 != mx2 && mx1 > up[p])
				downs[down[p][0].second == e[i].to ? down[p][1].second : down[p][0].second] += ups[e[i].to];
			else if(up[p] > mx1)
				ups[p] += ups[e[i].to];
		}
	if(sp[p])
	{
		ans[p]++;
		if(down[p][0].first != down[p][1].first && down[p][0].first > up[p])
			downs[down[p][0].second]++;
		else if(up[p] > down[p][0].first)
			ups[p]++;
	}
}
void dfs4(int p)
{
	ans[p] += downs[p];
	if(down[p][0].first > 0 && down[p][0].first != down[p][1].first)
		downs[down[p][0].second] += downs[p];
	visit[p] = true;
	for(int i = head[p]; i > 0; i = e[i].next)
		if(!visit[e[i].to])
			dfs4(e[i].to);
}
int main()
{
	scanf("%d%d", &n, &m);
	memset(sp, false, sizeof(sp));
	for(int i = 1; i <= m; i++)
	{
		int u;
		scanf("%d", &u);
		sp[u] = true;
	}
	for(int i = 1; i < n; i++)
		insert();
	memset(visit, false, sizeof(visit));
	dfs1(1);
	up[1] = -MAXNUM;
	memset(visit, false, sizeof(visit));
	dfs2(1);
	memset(ups, 0, sizeof(ups));
	memset(ans, 0, sizeof(ans));
	memset(downs, 0, sizeof(downs));
	memset(visit, false, sizeof(visit));
	dfs3(1);
	memset(visit, false, sizeof(visit));
	dfs4(1);
	int ret1 = 0, ret2 = 0;
	for(int i = 1; i <= n; i++)
	{
		if(sp[i])
			continue;
		if(ans[i] > ret1)
			ret1 = ans[i], ret2 = 1;
		else if(ans[i] == ret1)
			ret2++;
	}
	printf("%d %d\n", ret1, ret2);
	return 0;
}