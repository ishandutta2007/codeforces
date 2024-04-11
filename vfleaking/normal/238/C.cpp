#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxN = 3000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

struct halfEdge
{
	int u;
	bool forward;
	halfEdge *next;
};
halfEdge pool[MaxN * 2];
halfEdge *tail = pool;

int n;
halfEdge *adj[MaxN + 1];

inline void addEdge(const int &v, const int &u, bool forward)
{
	tail->u = u, tail->forward = forward;
	tail->next = adj[v], adj[v] = tail++;
}

int d[MaxN + 1];
int f[MaxN + 1][2];
void dfs(const int &v, const int &father)
{
	d[v] = 0;
	for (halfEdge *i = adj[v]; i; i = i->next)
		if (i->u != father)
		{
			dfs(i->u, v);
			d[v] += d[i->u] + (i->forward ? 0 : 1);
		}

	f[v][true] = d[v];
	f[v][false] = d[v];
	for (halfEdge *i = adj[v]; i; i = i->next)
		if (i->u != father)
		{
			if (i->forward)
			{
				tension(f[v][true], f[i->u][true] + d[v] - d[i->u]);
				tension(f[v][false], f[i->u][false] + d[v] - d[i->u] + 1);
			}
			else
			{
				tension(f[v][true], f[i->u][false] + d[v] - d[i->u] - 1);
				tension(f[v][true], f[i->u][true] + d[v] - d[i->u] - 1 + 1);
				tension(f[v][false], f[i->u][false] + d[v] - d[i->u] - 1);
			}
		}
}

inline int handle(const int &root)
{
	dfs(root, 0);
	return f[root][true];
}

int main()
{
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u, true);
		addEdge(u, v, false);
	}

	int res = INT_MAX;
	for (int i = 1; i <= n; i++)
		tension(res, handle(i));
	cout << res << endl;

	return 0;
}