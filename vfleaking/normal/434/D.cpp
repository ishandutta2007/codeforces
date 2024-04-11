#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxN = 50;
const int MaxM = 100;
const int L = 202;

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

// max flows
namespace NetworkFlows
{
	const int MaxNVer = MaxN * L + 2;
	const int MaxNE = MaxN * L * 2 + MaxN * 2 + MaxM * L;

	struct halfEdge
	{
		int u, w;
		halfEdge *next;
	};
	halfEdge adj_pool[MaxNE * 2], *adj_tail;

	int nVer;
	int source, terminal;
	halfEdge *adj[MaxNVer];

	inline void init()
	{
		fill(adj, adj + nVer, (halfEdge *)NULL);
		adj_tail = adj_pool;
	}
	inline void addEdge(const int &v, const int &u, const int &w)
	{
		adj_tail->u = u, adj_tail->w = w, adj_tail->next = adj[v], adj[v] = adj_tail++;
		adj_tail->u = v, adj_tail->w = 0, adj_tail->next = adj[u], adj[u] = adj_tail++;
	}

	inline halfEdge *opposite(halfEdge *e)
	{
		return adj_pool + ((e - adj_pool) ^ 1);
	}

	int outcome_flow;

	int dist[MaxNVer];
	int book[MaxNVer];

	int dfs(const int &v, const int &delta)
	{
		if (v == terminal)
			return delta;
		int flow = 0;
		for (halfEdge *i = adj[v]; i; i = i->next)
			if (i->w > 0 && dist[v] == dist[i->u] + 1)
			{
				int add = dfs(i->u, min(i->w, delta - flow));
				i->w -= add, opposite(i)->w += add;
				flow += add;

				if (flow == delta || dist[source] == INT_MAX)
					return flow;
			}
		if (flow == 0)
		{
			if (--book[dist[v]] == 0)
			{
				dist[source] = INT_MAX;
				return 0;
			}

			dist[v] = INT_MAX;
			for (halfEdge *i = adj[v]; i; i = i->next)
				if (i->w > 0 && dist[i->u] != INT_MAX)
					tension(dist[v], dist[i->u] + 1);
			if (dist[v] != INT_MAX)
				book[dist[v]]++;
		}
		return flow;
	}

	inline void calcMaxFlows()
	{
		fill(dist, dist + nVer, 0);
		fill(book, book + nVer, 0);
		book[0] = nVer;

		outcome_flow = 0;
		while (dist[source] != INT_MAX)
			outcome_flow += dfs(source, INT_MAX);
	}
}

int main()
{
	int n, m;

	cin >> n >> m;
	using namespace NetworkFlows;

	nVer = n * L + 2;
	source = n * L, terminal = n * L + 1;

	init();
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		for (int j = 0; j < L - 1; j++)
			addEdge(i * L + j + 1, i * L + j, INT_MAX);
		int last = 0;
		for (int j = 0; j < L; j++)
		{
			int x = j - 100;
			int cur = a * x * x + b * x + c;
			int delta = cur - last;
			if (delta > 0)
			{
				res += delta;
				addEdge(source, i * L + j, delta);
			}
			else
				addEdge(i * L + j, terminal, -delta);
			last = cur;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		l += 100, r += 100;
		addEdge(source, i * L + l, INT_MAX);
		addEdge(i * L + r + 1, terminal, INT_MAX);
	}
	for (int i = 0; i < m; i++)
	{
		int v, u, d;
		scanf("%d %d %d", &v, &u, &d);
		v--, u--;
		for (int j = 0; j < L; j++)
			if (0 <= j - d && j - d < L)
				addEdge(v * L + j, u * L + j - d, INT_MAX);
	}
	calcMaxFlows();

	res -= outcome_flow;

	cout << res << endl;

	return 0;
}