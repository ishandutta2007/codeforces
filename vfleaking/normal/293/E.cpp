#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;

typedef long long s64;

const int MaxN = 100000;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

struct halfEdge
{
	int u, w;
	halfEdge *next;
};
halfEdge adj_pool[(MaxN - 1) * 2], *adj_tail = adj_pool;

int n;
int maxL, maxW;
halfEdge *adj[MaxN + 1];
inline void addEdge(int v, int u, int w)
{
	adj_tail->u = u, adj_tail->w = w, adj_tail->next = adj[v], adj[v] = adj_tail++;
}
inline void delEdge(int v, int u)
{
	halfEdge **prev = &adj[v];
	for (halfEdge *e = adj[v]; e; prev = &e->next, e = e->next)
		if (e->u == u)
			*prev = e->next;
}

s64 outcome = 0;

int q_n;
int fa[MaxN + 1];
int wei[MaxN + 1];
int distL[MaxN + 1], distW[MaxN + 1];
int q[MaxN];

int bit[MaxN + 1];
inline void bit_init(int n)
{
	for (int i = 0; i <= n; i++)
		bit[i] = 0;
}
inline void bit_add(int n, int p, int delta)
{
	if (p == 0)
	{
		bit[p] += delta;
		return;
	}
	while (p <= n)
		bit[p] += delta, p += p & (-p);
}
inline int bit_query(int n, int p)
{
	if (p < 0)
		return 0;
	if (p > n)
		p = n;
	int res = bit[0];
	while (p > 0)
		res += bit[p], p -= p & (-p);
	return res;
}

inline bool cmpInDistW(const int &i, const int &j)
{
	return distW[i] < distW[j];
}

s64 calc(int *a, int n)
{
	sort(a, a + n, cmpInDistW);
	bit_init(n);
	for (int j = 0; j < n; j++)
		bit_add(n, distL[a[j]], 1);
	s64 res = 0;
	for (int i = 0, j = n - 1; i < n; i++)
	{
		while (j >= 0 && distW[a[i]] + distW[a[j]] > maxW)
		{
			bit_add(n, distL[a[j]], -1);
			j--;
		}
		res += bit_query(n, maxL - distL[a[i]]);

		if (distL[a[i]] * 2 <= maxL && distW[a[i]] * 2 <= maxW)
			res--;
	}
	return res;
}

void dfs(int root)
{
	q_n = 0;
	fa[root] = 0, q[q_n++] = root;
	for (int i = 0; i < q_n; i++)
	{
		int v = q[i];
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (e->u != fa[v])
				fa[e->u] = v, q[q_n++] = e->u;
	}

	int vC, cW = INT_MAX;
	for (int i = q_n - 1; i >= 0; i--)
	{
		int v = q[i];
		int vW = 0;
		wei[v] = 1;
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (e->u != fa[v])
			{
				wei[v] += wei[e->u];
				relax(vW, wei[e->u]);
			}
		relax(vW, q_n - wei[v]);

		if (vW < cW)
			cW = vW, vC = v;
	}

	q_n = 0;
	distL[vC] = 0, distW[vC] = 0;
	q[q_n++] = vC;
	for (halfEdge *cE = adj[vC]; cE; cE = cE->next)
	{
		int oq_n = q_n;
		distL[cE->u] = 1, distW[cE->u] = cE->w;
		fa[cE->u] = vC, q[q_n++] = cE->u;
		for (int i = oq_n; i < q_n; i++)
		{
			int v = q[i];
			for (halfEdge *e = adj[v]; e; e = e->next)
				if (e->u != fa[v])
				{
					distL[e->u] = distL[v] + 1, distW[e->u] = distW[v] + e->w;
					fa[e->u] = v, q[q_n++] = e->u;
				}
		}
		outcome -= calc(q + oq_n, q_n - oq_n);
	}
	outcome += calc(q, q_n);

	for (halfEdge *cE = adj[vC]; cE; cE = cE->next)
	{
		delEdge(cE->u, vC);
		dfs(cE->u);
	}
}

int main()
{
	cin >> n >> maxL >> maxW;
	for (int v = 2; v <= n; v++)
	{
		int u, w;
		scanf("%d %d", &u, &w);
		addEdge(v, u, w);
		addEdge(u, v, w);
	}

	dfs(1);

	outcome /= 2;

	cout << outcome << endl;

	return 0;
}