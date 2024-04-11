#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 200000;

// adj tab
const int MaxNVer = MaxN;
const int MaxNEdge = MaxN * 2;

struct halfEdge
{
    int u;
    halfEdge *next;
};
halfEdge adj_pool[MaxNEdge], *adj_tail = adj_pool;

int n, m;
int a[MaxN + 1];
halfEdge *adj[MaxNVer + 1];

inline void addEdge(const int &v, const int &u)
{
    adj_tail->u = u;
    adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int dfs_n = 0;
int posL[MaxN + 1], posR[MaxN + 1];
int dep[MaxN + 1];

int bit[MaxN * 2 + 1];

inline void bit_add(int pos, int delta)
{
	for (int i = pos; i <= n * 2; i += i & -i)
		bit[i] += delta;
}
inline int bit_query(int pos)
{
	int res = 0;
	for (int i = pos; i >= 1; i -= i & -i)
		res += bit[i];
	return res;
}

void dfs(int v, int fa)
{
	posL[v] = ++dfs_n;
	dep[v] = dep[fa] + 1;

	int s = bit_query(posL[v]);
	if (dep[v] % 2 == 0)
		bit_add(posL[v], a[v] - s);
	else
		bit_add(posL[v], -a[v] - s);

	for (halfEdge *e = adj[v]; e; e = e->next)
		if (e->u != fa)
			dfs(e->u, v);

	posR[v] = ++dfs_n;
	if (dep[v] % 2 == 0)
		bit_add(posR[v], -a[v] - s);
	else
		bit_add(posR[v], a[v] - s);
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u), addEdge(u, v);
	}

	dfs(1, 0);

	while (m--)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			int v, val;
			scanf("%d %d", &v, &val);
			if (dep[v] % 2 == 0)
				bit_add(posL[v], val), bit_add(posR[v], -val);
			else
				bit_add(posL[v], -val), bit_add(posR[v], val);
		}
		else
		{
			int v;
			scanf("%d", &v);
			int s = bit_query(posL[v]);

			if (dep[v] % 2 == 0)
				printf("%d\n", s);
			else
				printf("%d\n", -s);
		}
	}

	return 0;
}