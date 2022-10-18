#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

const int MaxN = 200;
const int MaxA = 10000;

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
	const int MaxNVer = MaxN + 2;
	const int MaxNE = MaxN + MaxN * MaxN + MaxN;

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
	int n;
	static int a[MaxN + 1];

	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	static bool isPr[MaxA * 2 + 1];
	for (int i = 2; i <= MaxA * 2; i++)
		isPr[i] = true;
	for (int i = 2; i <= MaxA * 2; i++)
		if (isPr[i])
			for (int j = i + i; j <= MaxA * 2; j += i)
				isPr[j] = false;

	namespace NF = NetworkFlows;

	NF::nVer = n + 2;
	NF::source = n, NF::terminal = n + 1;
	NF::init();
	for (int i = 0; i < n; i++)
	{
		if (a[i] % 2 == 0)
			NF::addEdge(NF::source, i, 2);
		else
			NF::addEdge(i, NF::terminal, 2);
	}

	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0)
			for (int j = 0; j < n; j++)
				if (a[j] % 2 == 1)
					if (isPr[a[i] + a[j]])
						NF::addEdge(i, j, 1);

	NF::calcMaxFlows();

	if (NF::outcome_flow != n)
	{
		cout << "Impossible" << endl;
		return 0;
	}

	static vector<int> ou[MaxN];

	for (NF::halfEdge *e = NF::adj_pool; e != NF::adj_tail; e += 2)
		if (e->u != NF::terminal && NF::opposite(e)->u != NF::source && e->w == 0)
		{
			ou[opposite(e)->u].push_back(e->u);
			ou[e->u].push_back(opposite(e)->u);
		}

	vector<vector<int> > orz;

	static bool book[MaxN];
	for (int sv = 0; sv < n; sv++)
		if (!book[sv])
		{
			vector<int> res;
			int lu = ou[sv][0];
			int u = sv;
			do
			{
				int nu = ou[u][0] == lu ? ou[u][1] : ou[u][0];
				res.push_back(nu);
				book[nu] = true;
				lu = u;
				u = nu;
			}
			while (u != sv);

			orz.push_back(res);
		}

	cout << orz.size() << endl;
	for (int i = 0; i < (int)orz.size(); i++)
	{
		vector<int> res = orz[i];
		printf("%d", (int)res.size());
		for (int k = 0; k < (int)res.size(); k++)
			printf(" %d", res[k] + 1);
		printf("\n");
	}

	return 0;
}