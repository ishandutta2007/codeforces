#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxN = 100000;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tension(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

// adj tab
const int MaxNVer = MaxN;
const int MaxNEdge = (MaxN - 1) * 2;

struct halfEdge
{
    int u;
    halfEdge *next;
};
halfEdge adj_pool[MaxNEdge], *adj_tail = adj_pool;

int n, affD;
halfEdge *adj[MaxNVer + 1];

bool affect[MaxN + 1];

inline void addEdge(const int &v, const int &u)
{
    adj_tail->u = u;
    adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int fa[MaxN + 1];
int seq[MaxN + 1];

inline void bfs()
{
	int top, bot;
	top = bot = 0;

	fa[1] = 0, seq[bot++] = 1;
	while (top != bot)
	{
		int v = seq[top++];
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (e->u != fa[v])
				fa[e->u] = v, seq[bot++] = e->u;
	}
}

int main()
{
	int m;
	cin >> n >> m >> affD;
	for (int i = 0; i < m; i++)
	{
		int v;
		scanf("%d", &v);
		affect[v] = true;
	}
	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u), addEdge(u, v);
	}

	bfs();

	static int down[MaxN + 1];
	static int downV[MaxN + 1], downU[MaxN + 1];

	for (int i = n - 1; i >= 0; i--)
	{
		int v = seq[i];
		down[v] = affect[v] ? 0 : INT_MIN;

		for (halfEdge *e = adj[v]; e; e = e->next)
			if (e->u != fa[v])
			{
				if (down[e->u] != INT_MIN)
					relax(down[v], down[e->u] + 1);

				if (!downV[v] || (down[downV[v]] < down[e->u]))
					downU[v] = downV[v], downV[v] = e->u;
				else if (!downU[v] || (down[downU[v]] < down[e->u]))
					downU[v] = e->u;
			}
	}

	static int up[MaxN + 1];
	up[1] = affect[1] ? 0 : INT_MIN;
	for (int i = 1; i < n; i++)
	{
		int v = seq[i];
		up[v] = affect[v] ? 0 : INT_MIN;

		if (up[fa[v]] != INT_MIN)
			relax(up[v], 1 + up[fa[v]]);

		int t;
		if (downV[fa[v]] != v)
			t = downV[fa[v]];
		else
			t = downU[fa[v]];

		if (!t || down[t] == INT_MIN)
			continue;
		relax(up[v], 1 + 1 + down[t]);
	}

	int res = 0;
	for (int v = 1; v <= n; v++)
		if (max(up[v], down[v]) <= affD)
			res++;
	cout << res << endl;

	return 0;
}