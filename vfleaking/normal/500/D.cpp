#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 100000;

const int MaxNVer = MaxN;
const int MaxNEdge = MaxN * 2;

struct halfEdge
{
    int u;
    halfEdge *next;
};
halfEdge adj_pool[MaxNEdge], *adj_tail = adj_pool;

int n;
halfEdge *adj[MaxNVer + 1];

inline void addEdge(const int &v, const int &u)
{
    adj_tail->u = u;
    adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int main()
{
	static int curW[MaxN];

	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int v, u, w;
		scanf("%d %d %d", &v, &u, &w);
		addEdge(v, u);
		addEdge(u, v);

		curW[i] = w;
	}

	static int fa[MaxN + 1];
	int q_n = 0;
	static int q[MaxN];

	fa[1] = 0, q[q_n++] = 1;
	for (int i = 0; i < q_n; i++)
	{
		int v = q[i];
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (e->u != fa[v])
				fa[e->u] = v, q[q_n++] = e->u;
	}

	static int wei[MaxN + 1];
	for (int i = q_n - 1; i >= 0; i--)
	{
		int v = q[i];
		wei[v] = 1;
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (e->u != fa[v])
				wei[v] += wei[e->u];
	}

	double res = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int v = adj_pool[i << 1 | 0].u;
		int u = adj_pool[i << 1 | 1].u;
		int s = min(wei[v], wei[u]);
		int t = n - s;
		res += ((double)s * (s - 1) * t + (double)t * (t - 1) * s) / ((double)n * (n - 1) * (n - 2) / 6) * curW[i];
	}

	int nQ;
	cin >> nQ;
	while (nQ--)
	{
		int i, w;
		scanf("%d %d", &i, &w);
		i--;

		int v = adj_pool[i << 1 | 0].u;
		int u = adj_pool[i << 1 | 1].u;
		int s = min(wei[v], wei[u]);
		int t = n - s;
		res -= ((double)s * (s - 1) * t + (double)t * (t - 1) * s) / ((double)n * (n - 1) * (n - 2) / 6) * curW[i];

		curW[i] = w;

		res += ((double)s * (s - 1) * t + (double)t * (t - 1) * s) / ((double)n * (n - 1) * (n - 2) / 6) * curW[i];

		printf("%.10f\n", res);
	}

	return 0;
}