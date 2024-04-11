#include <iostream>
#include <cstdio>
#include <cassert>
using namespace std;

const int MaxN = 100000;
const int MaxM = 100000;

// adj tab
const int MaxNVer = MaxN;
const int MaxNEdge = MaxM * 2;

struct halfEdge
{
    int u;
    halfEdge *next;
};
halfEdge adj_pool[MaxNEdge], *adj_tail = adj_pool;

halfEdge *adj[MaxNVer + 1];
halfEdge *corE[MaxM];

inline void addEdge(const int &v, const int &u)
{
    adj_tail->u = u;
    adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int main()
{
	int n, m;

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u), addEdge(u, v);
	}

	if (m % 2 != 0)
	{
		printf("No solution\n");
		return 0;
	}

	static int fa[MaxN + 1];
	static halfEdge *faE[MaxN + 1];
	static bool book[MaxN + 1];
	static int deg[MaxN + 1];

	int top, bot;
	static int q[MaxN];

	top = bot = 0;

	fa[1] = 0, faE[1] = NULL;
	book[1] = true, q[bot++] = 1;
	while (top != bot)
	{
		int v = q[top++];
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (!corE[(e - adj_pool) >> 1])
			{
				corE[(e - adj_pool) >> 1] = e;
				deg[e->u]++;

				if (!book[e->u])
				{
					fa[e->u] = v, faE[e->u] = e;
					book[e->u] = true, q[bot++] = e->u;
				}
			}
	}

	for (int i = n - 1; i >= 0; i--)
	{
		int v = q[i];

		if (deg[v] % 2 == 1)
		{
			assert(v != 1);
			deg[v]--;
			deg[fa[v]]++;
			corE[(faE[v] - adj_pool) >> 1] = adj_pool + ((faE[v] - adj_pool) ^ 1);
		}
	}

	for (int v = 1; v <= n; v++)
	{
		int last = -1;
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (corE[(e - adj_pool) >> 1] != e)
			{
				if (last == -1)
					last = e->u;
				else
				{
					printf("%d %d %d\n", last, v, e->u);
					last = -1;
				}
			}
	}

	return 0;
}