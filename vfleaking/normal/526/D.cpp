#include <iostream>
#include <cstdio>
using namespace std;

typedef long long s64;

const int MaxN = 1000000;

struct halfEdge
{
	int u;
	halfEdge *next;
};
halfEdge adj_pool[MaxN + 1], *adj_tail = adj_pool;

halfEdge *adj[MaxN + 1];

inline void addEdge(int v, int u)
{
	adj_tail->u = u, adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int n, vk;
char s[MaxN + 2];
int prev[MaxN + 1];
int next[MaxN + 1];

char res[MaxN + 2];

void dfs(int v, int p)
{
	if (v != 0)
	{
		while ((s64)p * vk < (s64)v * (vk - 1))
			p = prev[p];
		res[v] = (s64)(vk + 1) * p <= (s64)vk * v ? '1' : '0';
	}

	for (halfEdge *e = adj[v]; e; e = e->next)
	{
		prev[v] = e->u;
		dfs(e->u, p);
	}
}

int main()
{
	cin >> n >> vk;
	scanf("%s", s + 1);

	next[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		int j = next[i - 1];
		while (j > 0 && s[i] != s[j + 1])
			j = next[j];
		if (s[i] == s[j + 1])
			j++;
		next[i] = j;
	}
	for (int i = 1; i <= n; i++)
		addEdge(next[i], i);

	dfs(0, 0);

	printf("%s\n", res + 1);

	return 0;
}