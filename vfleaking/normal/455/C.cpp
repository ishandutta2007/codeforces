#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 300000;

struct halfEdge
{
    int u;
    halfEdge *next;
};
halfEdge adj_pool[MaxN * 2], *adj_tail = adj_pool;

halfEdge *adj[MaxN + 1];

inline void addEdge(const int &v, const int &u)
{
    adj_tail->u = u;
    adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int ufs[MaxN + 1];
int ufsD[MaxN + 1];
inline int ufs_find(int v)
{
	int res;
	for (res = v; ufs[res] != res; res = ufs[res]);
	for (int u = v, p = ufs[u]; u != res; u = p, p = ufs[u])
		ufs[u] = res;
	return res;
}

int dist[MaxN + 1];
int q_n;
int q[MaxN];

void bfs(int sv)
{
	q_n = 0;
	static int fa[MaxN + 1];

	fa[sv] = 0, dist[sv] = 0, q[q_n++] = sv;
	for (int i = 0; i < q_n; i++)
	{
		int v = q[i];
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (e->u != fa[v])
				fa[e->u] = v, dist[e->u] = dist[v] + 1, q[q_n++] = e->u;
	}
}

int main()
{
	int n, m, nQ;
	cin >> n >> m >> nQ;
	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u), addEdge(u, v);
	}

	for (int v = 1; v <= n; v++)
		dist[v] = -1;

	for (int sv = 1; sv <= n; sv++)
		if (dist[sv] == -1)
		{
			bfs(sv);
			bfs(q[q_n - 1]);
			for (int i = 0; i < q_n; i++)
				ufs[q[i]] = sv;
			ufsD[sv] = dist[q[q_n - 1]];
		}

	while (nQ--)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int v;
			scanf("%d", &v);
			printf("%d\n", ufsD[ufs_find(v)]);
		}
		else
		{
			int v, u;
			scanf("%d %d", &v, &u);
			v = ufs_find(v);
			u = ufs_find(u);
			if (v != u)
			{
				int d1 = ufsD[v];
				int d2 = ufsD[u];
				ufsD[u] = max(max(d1, d2), (d1 + 1) / 2 + 1 + (d2 + 1) / 2);
				ufs[v] = u;
			}
		}
	}

	return 0;
}