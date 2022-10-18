#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 100000;

// adj tab
const int MaxNVer = MaxN;
const int MaxNEdge = (MaxN - 1) * 2;

struct halfEdge
{
    int u;
    halfEdge *next;
};
halfEdge adj_pool[MaxNEdge], *adj_tail = adj_pool;

halfEdge *adj[MaxNVer + 1];

inline void addEdge(const int &v, const int &u)
{
    adj_tail->u = u;
    adj_tail->next = adj[v], adj[v] = adj_tail++;
}

double outcome = 0.0;
void dfs(const int &v, const int &fa, const int &d)
{
	outcome += 1.0 / d;

	for (halfEdge *i = adj[v]; i; i = i->next)
		if (i->u != fa)
			dfs(i->u, v, d + 1);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u);
		addEdge(u, v);
	}

	dfs(1, 0, 1);
	printf("%.10lf\n", outcome);

	return 0;
}