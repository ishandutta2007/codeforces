#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

const int MaxANP = 9;

const int MaxN = 100;
const int MaxM = 100;

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
	const int MaxNVer = 1 + MaxN * MaxANP + 1;
	const int MaxNE = MaxN + MaxM * MaxANP + MaxN;

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
	static vector< pair<int, int> > a[MaxN + 1];

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int ai;
		scanf("%d", &ai);

		for (int k = 2; k * k <= ai; k++)
			if (ai % k == 0)
			{
				int al = 0;
				while (ai % k == 0)
					ai /= k, al++;
				a[i].push_back(make_pair(k, al));
			}
		if (ai > 1)
			a[i].push_back(make_pair(ai, 1));
	}

	static int aed[MaxN + 1];
	aed[0] = 0;
	for (int i = 1; i <= n; i++)
		aed[i] = aed[i - 1] + (int)a[i].size();

	namespace NF = NetworkFlows;
	NF::nVer = 1 + aed[n] + 1;
	NF::source = aed[n], NF::terminal = aed[n] + 1;
	NF::init();

	for (int i = 1; i <= n; i++)
		for (int p = 0; p < (int)a[i].size(); p++)
		{
			if (i % 2 == 0)
				NF::addEdge(NF::source, aed[i - 1] + p, a[i][p].second);
			else
				NF::addEdge(aed[i - 1] + p, NF::terminal, a[i][p].second);
		}

	for (int i = 0; i < m; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		if (l % 2 == 1)
			swap(l, r);

		for (int p = 0; p < (int)a[l].size(); p++)
			for (int q = 0; q < (int)a[r].size(); q++)
				if (a[l][p].first == a[r][q].first)
					NF::addEdge(aed[l - 1] + p, aed[r - 1] + q, INT_MAX);
	}

	NF::calcMaxFlows();

	cout << NF::outcome_flow << endl;

	return 0;
}