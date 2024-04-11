#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 1000;
const int MaxM = 5000;
const int INF = 1000000000;

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

struct halfEdge
{
	int u;
	halfEdge *next;
};
halfEdge pool[MaxM * 2];
halfEdge *tail = pool;

inline void addEdge(halfEdge **adj, const int &v, const int &u)
{
	tail->u = u;
	tail->next = adj[v], adj[v] = tail++;
}

void dfs(const int &v, halfEdge **adj, bool *book)
{
	book[v] = true;
	for (halfEdge *i = adj[v]; i; i = i->next)
		if (!book[i->u])
			dfs(i->u, adj, book);
}

int main()
{
	int n, m;
	static halfEdge *orig[MaxN + 1];
	static halfEdge *oppo[MaxN + 1];
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		
		addEdge(orig, v, u);
		addEdge(oppo, u, v);
	}

	static bool valid[MaxN + 1], tempValid[MaxN + 1];
	dfs(1, orig, valid);
	dfs(n, oppo, tempValid);
	for (int i = 1; i <= n; i++)
		valid[i] &= tempValid[i];

	static int dist[MaxN + 1];
	bool changed = true;
	fill(dist + 1, dist + n + 1, INF);
	dist[1] = 0;
	for (int times = 0; times < n && changed; times++)
	{
		changed = false;
		for (int i = 1; i <= n; i++)
			if (valid[i])
				for (halfEdge *j = orig[i]; j; j = j->next)
					if (valid[j->u])
					{
						if (tension(dist[i], dist[j->u] - 1))
							changed = true;
						if (tension(dist[j->u], dist[i] + 2))
							changed = true;
					}
	}
	
	if (changed)
	{
		puts("No");
		return 0;
	}

	puts("Yes");
	for (int i = 0; i < m; i++)
	{
		int v = pool[i << 1 | 1].u;
		int u = pool[i << 1].u;
		if (valid[v] && valid[u])
			printf("%d\n", dist[u] - dist[v]);
		else
			printf("1\n");
	}
	
	return 0;
}