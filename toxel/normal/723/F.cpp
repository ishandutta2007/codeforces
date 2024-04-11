#include<bits/stdc++.h>
#define N (800010)                                                                                                                                            

using namespace std;

typedef struct point
{
	int parent, s, t, first;
	bool visited;
};

typedef struct edge
{
	int next, to, flag;
};

point points[N];
edge edges[N];
int e = 1, n, m, edg[N][2], s, t, ds, dt;
vector <int> vs,vt;

void addedge(int u, int v, bool flag)
{
	edges[++e].next = points[u].first;
	points[u].first = e;
	edges[e].to = v;
	edges[e].flag = flag;
	edges[++e].next = points[v].first;
	points[v].first = e;
	edges[e].to = u;
	edges[e].flag = flag;
}

int find(int x)
{
	if (x == points[x].parent)
		return x;
	if (points[x].s)
		points[points[x].parent].s = points[x].s;
	if (points[x].t)
		points[points[x].parent].t = points[x].t;
	points[x].parent = find(points[x].parent);
	if (points[points[x].parent].s)
		points[x].s = points[points[x].parent].s;
	if (points[points[x].parent].t)
		points[x].t = points[points[x].parent].t;
	return points[x].parent;
}

int unite(int u, int v)
{
	int x = find(u), y = find(v);
	if (x != y)
	{
		points[x].parent = y;
		find(u);
	}
}

void dfs(int i)
{
	points[i].visited = true;
	for (int j = points[i].first; j; j = edges[j].next)
	{
		if (!points[edges[j].to].visited)
		{
			edges[j].flag = true;
			edges[j ^ 1].flag = true;
			dfs(edges[j].to);
		}
	}
}
int main()
{
	memset(points, 0, sizeof(points));
	memset(edges, 0, sizeof(edges));
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		points[i].parent = i;
	for (int i = 0; i < m; i++)
		scanf("%d%d", &edg[i][0], &edg[i][1]);
	scanf("%d%d%d%d", &s, &t, &ds, &dt);
	for (int i = 0; i < m; i++)
	{
		if (edg[i][0] == s)
		{
			if (edg[i][1] != t)
				points[edg[i][1]].s = edg[i][1];
		}
		else if (edg[i][0] == t)
		{
			if (edg[i][1] != s)
				points[edg[i][1]].t = edg[i][1];
		}
		else
		{
			if (edg[i][1] == s)
				points[edg[i][0]].s = edg[i][0];
			else if (edg[i][1] == t)
				points[edg[i][0]].t = edg[i][0];
			else
				unite(edg[i][0], edg[i][1]);
		}
	}
	for (int i = 0; i < m; i++)
		if (edg[i][0] != s && edg[i][0] != t && edg[i][1] != s && edg[i][1] != t)
			addedge(edg[i][0], edg[i][1], false);
	for (int i = 1; i <= n; i++)
		if (i !=s && i != t)
			find(i);
	for (int i = 1; i <= n; i++)
		if (i !=s && i != t)
		{
			if (points[i].parent == i)
			{
				if (points[i].s)
					vs.push_back(points[i].s);
				else if (points[i].t)
					vt.push_back(points[i].t);
			}
			if (!points[i].visited)
				dfs(i);
		}
	for (int i = 0; i < vs.size(); i++)
		if (!points[vs[i]].t)
		{
			ds--;
			if (ds < 0)
			{
				printf("No\n");
				return 0;
			}
			addedge(points[vs[i]].s, s, true);
		}
	for (int i = 0; i < vt.size(); i++)
		if (!points[vt[i]].s)
		{
			dt--;
			if (dt < 0)
			{
				printf("No\n");
				return 0;
			}
			addedge(points[vt[i]].t, t, true);
		}
	bool flag = false;
	for (int i = 0; i < vs.size(); i++)
		if (points[vs[i]].t)
			if (!flag)
			{
				addedge(points[vs[i]].s, s, true);
				addedge(points[vs[i]].t, t, true);
				ds--;
				dt--;
				if (ds < 0 || dt < 0)
				{
					printf("No\n");
					return 0;
				}
				flag = true;
			}
			else
			{
				if (ds > 0)
				{
					addedge(points[vs[i]].s, s, true);
					ds--;
				}
				else
				{
					addedge(points[vs[i]].t, t, true);
					dt--;
					if (dt < 0)
					{
						printf("No\n");
						return 0;
					}
				}
			}
	if (!flag)
	{
		addedge(s, t, true);
		ds--;
		dt--;
		if (ds < 0 || dt < 0)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	for (int i = 1; i <= m; i++)
		if (edges[2 * i].flag)
			printf("%d %d\n", edges[2 * i].to, edges[2 * i + 1].to);
	return 0;
}