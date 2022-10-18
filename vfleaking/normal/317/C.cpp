#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
using namespace std;

const int MaxN = 300;
const int MaxM = 50000;

int n, maxV, m;
int a[MaxN + 1], b[MaxN + 1];

struct halfEdge
{
	int u;
	halfEdge *next;
};
halfEdge adj_pool[MaxM * 2], *adj_tail = adj_pool;

halfEdge *adj[MaxN + 1];

void addEdge(int v, int u)
{
	adj_tail->u = u, adj_tail->next = adj[v], adj[v] = adj_tail++;
}

vector<pair<pair<int, int>, int> > outcome;

int fa[MaxN + 1];

void submit(int v, int u, int d)
{
	outcome.push_back(make_pair(make_pair(v, u), d));
	a[v] -= d, a[u] += d;
}

void deliver(int v, int d)
{
	if (!fa[v])
		return;
	if (a[fa[v]] + d <= maxV)
	{
		submit(v, fa[v], d);
		deliver(fa[v], d);
	}
	else
	{
		deliver(fa[v], d);
		submit(v, fa[v], d);
	}
}

void bfs(int sv)
{
	int q_n = 0;
	static int q[MaxN];

	for (int v = 1; v <= n; v++)
		fa[v] = -1;
	
	fa[sv] = 0, q[q_n++] = sv;
	for (int i = 0; i < q_n; i++)
	{
		int v = q[i];
		for (halfEdge *e = adj[v]; e; e = e->next)
			if (fa[e->u] == -1)
				fa[e->u] = v, q[q_n++] = e->u;
	}

	for (int ev = 1; ev <= n && a[sv] < b[sv]; ev++)
		if (fa[ev] != -1 && a[ev] > b[ev])
		{
			int delta = min(a[ev] - b[ev], b[sv] - a[sv]);
			if (delta > maxV / 2)
				deliver(ev, maxV / 2), deliver(ev, delta - maxV / 2);
			else
				deliver(ev, delta);
		}
}

int main()
{
	cin >> n >> maxV >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		addEdge(v, u);
		addEdge(u, v);
	}

	for (int v = 1; v <= n; v++)
		if (a[v] < b[v])
			bfs(v);

	bool ok = true;
	for (int v = 1; v <= n; v++)
		if (a[v] != b[v])
			ok = false;
	if (!ok)
		printf("NO\n");
	else
	{
		printf("%d\n", (int)outcome.size());
		for (int i = 0; i < (int)outcome.size(); i++)
			printf("%d %d %d\n", outcome[i].first.first, outcome[i].first.second, outcome[i].second);
	}

	return 0;
}