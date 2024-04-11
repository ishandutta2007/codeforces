#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxN = 2500;
const int MaxM = (MaxN - 1) * 2;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}
template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

struct halfEdge
{
	int u;
	halfEdge *next;
};
halfEdge adj_pool[MaxM * 2], *adj_tail = adj_pool;

int n;
halfEdge *adj[MaxN + 1];

inline void addEdge(const int &v, const int &u)
{
	adj_tail->u = u, adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int fa[MaxN + 1];
int dfn[MaxN + 1], dfnCnt;
int low[MaxN + 1];

int onlyA[] = {INT_MIN, 0};
int onlyB[] = {1, INT_MIN};
int onlyX[] = {0, INT_MIN};

int weight[MaxN + 1];
int fA[MaxN + 1][MaxN + 1], fB[MaxN + 1][MaxN + 1], fX[MaxN + 1][MaxN + 1];

inline void merge(int *a, const int &a_n, const int *b, const int &b_n)
{
	fill(a + a_n + 1, a + a_n + b_n + 1, INT_MIN);
	for (int i = a_n; i >= 0; i--)
	{
		if (a[i] == INT_MIN)
			continue;
		int ai = a[i];
		a[i] = INT_MIN;
		for (int j = 0; j <= b_n; j++)
			if (b[j] != INT_MIN)
				relax(a[i + j], ai + b[j]);
	}
}

inline void cirDP(int *tA, int *tB, int *tX, int &t_n, const int *li, const int &li_n)
{
	for (int iu = 0; iu < li_n; iu++)
	{
		int u = li[iu];
		for (int i = 0; i <= t_n; i++)
		{
			int tAi = tA[i], tBi = tB[i], tXi = tX[i];
			tA[i] = max(tAi, tXi);
			tB[i] = max(tBi, tXi);
			tX[i] = max(tAi, max(tBi, tXi));
		}
		merge(tA, t_n, fA[u], weight[u]);
		merge(tB, t_n, fB[u], weight[u]);
		merge(tX, t_n, fX[u], weight[u]);

		t_n += weight[u];
	}
}

void dfs(const int &v)
{
	low[v] = dfn[v] = ++dfnCnt;
	for (halfEdge *e = adj[v]; e; e = e->next)
	{
		if (!dfn[e->u])
		{
			fa[e->u] = v, dfs(e->u);
			tension(low[v], low[e->u]);
		}
		else if (fa[v] != e->u)
			tension(low[v], dfn[e->u]);
	}

	weight[v] = 1;
	copy(onlyA, onlyA + 2, fA[v]);
	copy(onlyB, onlyB + 2, fB[v]);
	copy(onlyX, onlyX + 2, fX[v]);

	static int g[MaxN + 1];
	for (halfEdge *e = adj[v]; e; e = e->next)
	{
		if (low[e->u] > dfn[v])
		{
			for (int i = 0; i <= weight[e->u]; i++)
				g[i] = max(fA[e->u][i], fX[e->u][i]);
			merge(fA[v], weight[v], g, weight[e->u]);

			for (int i = 0; i <= weight[e->u]; i++)
				g[i] = max(fB[e->u][i], fX[e->u][i]);
			merge(fB[v], weight[v], g, weight[e->u]);

			for (int i = 0; i <= weight[e->u]; i++)
				g[i] = max(fA[e->u][i], max(fB[e->u][i], fX[e->u][i]));
			merge(fX[v], weight[v], g, weight[e->u]);

			weight[v] += weight[e->u];
		}
		else if (fa[e->u] != v && low[e->u] == dfn[v])
		{
			int li_n = 0;
			static int li[MaxN];

			for (int u = e->u; u != v; u = fa[u])
				li[li_n++] = u;

			int t_n;
			static int tA[MaxN + 1], tB[MaxN + 1], tX[MaxN + 1];

			t_n = 0;
			tA[0] = 0, tB[0] = INT_MIN, tX[0] = INT_MIN;
			cirDP(tA, tB, tX, t_n, li, li_n);
			for (int i = 0; i <= t_n; i++)
				g[i] = max(tA[i], tX[i]);
			merge(fA[v], weight[v], g, t_n);

			t_n = 0;
			tA[0] = INT_MIN, tB[0] = 0, tX[0] = INT_MIN;
			cirDP(tA, tB, tX, t_n, li, li_n);
			for (int i = 0; i <= t_n; i++)
				g[i] = max(tB[i], tX[i]);
			merge(fB[v], weight[v], g, t_n);

			t_n = 0;
			tA[0] = INT_MIN, tB[0] = INT_MIN, tX[0] = 0;
			cirDP(tA, tB, tX, t_n, li, li_n);
			for (int i = 0; i <= t_n; i++)
				g[i] = max(tA[i], max(tB[i], tX[i]));
			merge(fX[v], weight[v], g, t_n);

			weight[v] += t_n;
		}
	}
}

int main()
{
	int m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u), addEdge(u, v);
	}

	fa[1] = 0;
	dfnCnt = 0;
	dfs(1);

	for (int i = 0; i <= n; i++)
		printf("%d ", max(fA[1][i], max(fB[1][i], fX[1][i])));
	cout << endl;

	return 0;
}