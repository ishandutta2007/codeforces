#include <iostream>
#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

typedef long long s64;

const s64 INF = 1000000000000000000ll;

const int MaxN = 100000;
const int MaxM = 300000;
const int MaxK = 100000;

struct halfEdge
{
	int u, w, c;
	halfEdge *next;
};
halfEdge adj_pool[(MaxM + MaxK) * 2], *adj_tail = adj_pool;

int n;
halfEdge *adj[MaxN + 1];

void addEdge(int v, int u, int w, int c)
{
	adj_tail->u = u, adj_tail->w = w, adj_tail->c = c;
	adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int main()
{
	int n, m, nK;
	static s64 dist[MaxN + 1];

	cin >> n >> m >> nK;
	for (int i = 0; i < m; i++)
	{
		int v, u, w;
		scanf("%d %d %d", &v, &u, &w);
		addEdge(v, u, w, 0);
		addEdge(u, v, w, 0);
	}
	for (int i = 0; i < nK; i++)
	{
		int u, w;
		scanf("%d %d", &u, &w);
		addEdge(1, u, w, 1);
		addEdge(u, 1, w, 1);
	}

	for (int v = 1; v <= n; v++)
		dist[v] = INF;
	priority_queue< pair<s64, int>, vector< pair<s64, int> >, greater< pair<s64, int> > > q;
	dist[1] = 0, q.push(make_pair(dist[1], 1));
	while (!q.empty())
	{
		pair<s64, int> cur = q.top();
		q.pop();
		int v = cur.second;
		if (cur.first != dist[v])
			continue;
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (dist[v] + e->w < dist[e->u])
				dist[e->u] = dist[v] + e->w, q.push(make_pair(dist[e->u], e->u));
	}

	int res = nK;
	for (int v = 2; v <= n; v++)
	{
		int minC = 100;
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (dist[e->u] + e->w == dist[v])
			{
				if (e->c < minC)
					minC = e->c;
			}
		res -= minC;
	}
	cout << res << endl;

	return 0;
}