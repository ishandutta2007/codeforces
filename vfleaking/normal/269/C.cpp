#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 200000;
const int MaxM = 200000;

struct halfEdge
{
	int u, flow;
	halfEdge *next;
};
halfEdge pool[MaxM * 2], *tail = pool;

int n, m;
halfEdge *adj[MaxN + 1];

inline void addEdge(const int &v, const int &u, const int &flow)
{
	tail->u = u, tail->flow = flow;
	tail->next = adj[v], adj[v] = tail++;
}

int main()
{
	cin >> n >> m;

	static int totF[MaxN + 1];
	for (int i = 0; i < m; i++)
	{
		int v, u, flow;
		scanf("%d %d %d", &v, &u, &flow);
		addEdge(v, u, flow);
		addEdge(u, v, flow);

		totF[v] += flow;
		totF[u] += flow;
	}

	for (int v = 2; v < n; v++)
		totF[v] /= 2;

	static int dir[MaxM];
	fill(dir, dir + m, -1);
	
	static int q[MaxN];
	int top, bottom;
	top = bottom = 0;

	q[bottom++] = 1;
	while (top != bottom)
	{
		int v = q[top++];
		for (halfEdge *i = adj[v]; i; i = i->next)
		{
			int idx = i - pool;
			if (dir[idx >> 1] == -1)
			{
				dir[idx >> 1] = idx & 1;
				totF[i->u] -= i->flow;
				if (totF[i->u] == 0)
					q[bottom++] = i->u;
			}
		}
	}

	for (int i = 0; i < m; i++)
		printf("%d\n", dir[i]);

	return 0;
}