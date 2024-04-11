#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 80000;

// adj tab
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

inline s64 c2(const s64 &n)
{
	return n * (n - 1) / 2;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);

		addEdge(v, u);
		addEdge(u, v);
	}
	
	static int fa[MaxN + 1];
	static int weight[MaxN + 1];

	int top, bot;
	static int q[MaxN];

	top = bot = 0;
	q[bot++] = 1;
	while (top != bot)
	{
		int v = q[top++];
		for (halfEdge *i = adj[v]; i; i = i->next)
			if (i->u != fa[v])
				fa[i->u] = v, q[bot++] = i->u;
	}

	for (int i = n - 1; i >= 0; i--)
	{
		int v = q[i];
		weight[v]++;
		weight[fa[v]] += weight[v];
	}

	static s64 f[MaxN + 1];
	static s64 g[MaxN + 1];
	for (int i = n - 1; i >= 0; i--)
	{
		int v = q[i];

		g[v] = 0;
		for (halfEdge *i = adj[v]; i; i = i->next)
			if (i->u != fa[v])
				g[v] += c2(weight[i->u]);
		f[v] = g[v];
		for (halfEdge *i = adj[v]; i; i = i->next)
			if (i->u != fa[v])
				f[v] += f[i->u] + weight[i->u] * (g[v] - c2(weight[i->u]));
	}

	s64 res = 0ll;
	for (int v = 1; v <= n; v++)
	{
		s64 cur = weight[v] - 1;

		s64 sum = 0;
		for (halfEdge *i = adj[v]; i; i = i->next)
			if (i->u != fa[v])
				cur += sum * weight[i->u], sum += weight[i->u];
		res += cur * c2(n - weight[v]);
	}
	for (int v = 1; v <= n; v++)
	{
		s64 sumf = 0ll, sumw = 0ll;
		s64 sumt = 0ll;
		for (halfEdge *i = adj[v]; i; i = i->next)
			if (i->u != fa[v])
			{
				res += sumf * weight[i->u];
				res += f[i->u] * sumw;
				res += sumt * weight[i->u];
				res -= sumw * c2(weight[i->u]) * weight[i->u];

				sumf += f[i->u];
				sumw += weight[i->u];
				sumt += weight[i->u] * (g[v] - c2(weight[i->u]));
			}
		res += f[v] - g[v];
	}

	cout << res << endl;

	return 0;
}