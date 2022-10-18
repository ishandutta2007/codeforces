#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxN = 200000;

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
const int MaxNEdge = MaxN;

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
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u);
	}

	int q_n = 0;
	static int q[MaxN];
	static int dep[MaxN + 1];
	dep[1] = 0, q[q_n++] = 1;
	for (int i = 0; i < q_n; i++)
	{
		int v = q[i];
		for (halfEdge *e = adj[v]; e; e = e->next)
			dep[e->u] = dep[v] + 1, q[q_n++] = e->u;
	}

	static int f[MaxN + 1], g[MaxN + 1], wei[MaxN + 1];
	for (int i = q_n - 1; i >= 0; i--)
	{
		int v = q[i];
		if (!adj[v])
			wei[v] = 1, f[v] = 1, g[v] = 1;
		else
		{
			wei[v] = 0;
			for (halfEdge *e = adj[v]; e; e = e->next)
				wei[v] += wei[e->u];
			if (dep[v] % 2 == 0)
			{
				f[v] = 0, g[v] = 0;
				for (halfEdge *e = adj[v]; e; e = e->next)
					f[v] += f[e->u], relax(g[v], wei[v] - wei[e->u] + g[e->u]);
			}
			else
			{
				f[v] = wei[v], g[v] = 1;
				for (halfEdge *e = adj[v]; e; e = e->next)
					tension(f[v], f[e->u]), g[v] += g[e->u] - 1;
			}
		}
	}

	cout << g[1] << " " << f[1] << endl;

	return 0;
}