#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MaxN = 100000;

// adj tab
const int MaxNVer = MaxN;
const int MaxNEdge = MaxN * 2;

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

int val[MaxN + 1];

vector<int> outcome;

void dfs(int v, int fa, int f0, int f1)
{
	val[v] ^= f0;
	if (val[v] == 1)
	{
		outcome.push_back(v);
		val[v] ^= 1, f0 ^= 1;
	}
	for (halfEdge *e = adj[v]; e; e = e->next)
		if (e->u != fa)
			dfs(e->u, v, f1, f0);
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u), addEdge(u, v);
	}

	for (int v = 1; v <= n; v++)
	{
		int t;
		scanf("%d", &t);
		val[v] ^= t;
	}
	for (int v = 1; v <= n; v++)
	{
		int t;
		scanf("%d", &t);
		val[v] ^= t;
	}

	dfs(1, 0, 0, 0);

	cout << outcome.size() << endl;
	for (int i = 0; i < (int)outcome.size(); i++)
		printf("%d\n", outcome[i]);
	
	return 0;
}