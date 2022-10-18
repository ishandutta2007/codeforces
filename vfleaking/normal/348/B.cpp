#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

typedef long long s64;

const s64 S64_MAX = 9223372036854775807ll;

const int MaxN = 100000;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

struct halfEdge
{
	int u;
	halfEdge *next;
};
halfEdge adj_pool[(MaxN - 1) * 2], *adj_tail = adj_pool;

int n;
int a[MaxN + 1];
halfEdge *adj[MaxN + 1];

inline void addEdge(const int &v, const int &u)
{
	adj_tail->u = u, adj_tail->next = adj[v], adj[v] = adj_tail++;
}

s64 f[MaxN + 1];
s64 stdA[MaxN + 1], lambda[MaxN + 1];

inline s64 gcd(s64 a, s64 b)
{
	while (b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

const s64 BIG_LAM = 1000000000000000000ll;

void dfs(const int &v, const int &fa)
{
	int nSon = 0;

	for (halfEdge *e = adj[v]; e; e = e->next)
		if (e->u != fa)
		{
			nSon++;
			dfs(e->u, v);
		}

	if (nSon == 0)
	{
		f[v] = 0, stdA[v] = a[v], lambda[v] = 1;
		return;
	}

	lambda[v] = 1;
	for (halfEdge *e = adj[v]; e; e = e->next)
		if (e->u != fa)
		{
			if (lambda[e->u] == BIG_LAM)
			{
				lambda[v] = BIG_LAM;
				break;
			}
			lambda[v] *= lambda[e->u] / gcd(lambda[v], lambda[e->u]);
			if (lambda[v] > BIG_LAM)
			{
				lambda[v] = BIG_LAM;
				break;
			}
		}

	stdA[v] = S64_MAX;
	for (halfEdge *e = adj[v]; e; e = e->next)
		if (e->u != fa)
			tension(stdA[v], stdA[e->u] / lambda[v] * lambda[v]);
	f[v] = 0;
	for (halfEdge *e = adj[v]; e; e = e->next)
		if (e->u != fa)
			f[v] += f[e->u], f[v] += stdA[e->u] - stdA[v];
	lambda[v] = min(lambda[v] * nSon, BIG_LAM);
	stdA[v] *= nSon;
}

int main()
{
	cin >> n;
	for (int v = 1; v <= n; v++)
		scanf("%d", &a[v]);
	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u), addEdge(u, v);
	}

	dfs(1, 0);

	cout << f[1] << endl;

	return 0;
}