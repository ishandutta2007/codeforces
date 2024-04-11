#include <iostream>
#include <iomanip>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <cmath>
using namespace std;

const int MaxN = 400;

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

template <class T>
inline T sqr(const T &a)
{
	return a * a;
}

namespace NetworkFlows
{
	const int MaxNV = MaxN * 2 + 2;
	const int MaxNE = (MaxN * MaxN + MaxN + MaxN) * 2;

	struct halfEdge
	{
		int u, limit;
		double cost;
		halfEdge *next;
	};
	halfEdge pool[MaxNE], *tail = pool;

	int nV;
	int source, terminal;
	halfEdge *adj[MaxNV];

	inline void addEdge(
			const int &v, const int &u,
			const int &limit, const double &cost)
	{
		tail->u = u, tail->limit = limit, tail->cost = cost;
		tail->next = adj[v], adj[v] = tail++;

		tail->u = v, tail->limit = 0, tail->cost = -cost;
		tail->next = adj[u], adj[u] = tail++;
	}

	inline halfEdge *opposite(const halfEdge *i)
	{
		return pool + ((i - pool) ^ 1);
	}

	int outcome_flow;
	double outcome_cost;
	inline bool findPath()
	{
		static double dist[MaxNV];
		static halfEdge *backE[MaxNV];
		static bool book[MaxNV];
		static int q[MaxNV];
		int top, bottom;
		
		fill(dist, dist + nV, HUGE_VAL);
		fill(book, book + nV, false);

		top = bottom = 0;

		dist[source] = 0.0, backE[source] = NULL;
		book[source] = true, q[bottom++] = source;
		while (top != bottom)
		{
			int v = q[top++];
			if (top == nV)
				top = 0;
			book[v] = false;

			for (halfEdge *i = adj[v]; i; i = i->next)
				if (i->limit > 0 && tension(dist[i->u], dist[v] + i->cost))
				{
					backE[i->u] = opposite(i);
					if (!book[i->u])
					{
						book[i->u] = true, q[bottom++] = i->u;
						if (bottom == nV)
							bottom = 0;
					}
				}
		}

		if (dist[terminal] == HUGE_VAL)
			return false;

		int add = INT_MAX;
		for (int v = terminal; v != source; v = backE[v]->u)
			tension(add, opposite(backE[v])->limit);
		for (int v = terminal; v != source; v = backE[v]->u)
			opposite(backE[v])->limit -= add, backE[v]->limit += add;

		outcome_flow += add;
		for (int k = 0; k < add; k++)
			outcome_cost += dist[terminal];

		return true;
	}

	inline void calcMinCostMaxFlow()
	{
		outcome_cost = 0.0, outcome_flow = 0;
		while (findPath());
	}
};

int main()
{
	int n;
	static int px[MaxN + 1];
	static int py[MaxN + 1];
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &px[i], &py[i]);

	int root = max_element(py + 1, py + n + 1) - py;
	if (count(py + 1, py + n + 1, py[root]) > 1)
	{
		printf("-1\n");
		return 0;
	}

	namespace NW = NetworkFlows;

	NW::nV = n * 2 + 2;
	NW::source = 0;
	NW::terminal = n + n + 1;
	for (int i = 1; i <= n; i++)
	{
		if (i != root)
		{
			NW::addEdge(n + i, NW::terminal, 1, 0.0);
			for (int j = 1; j <= n; j++)
				if (py[j] > py[i])
					NW::addEdge(j, n + i, 1, sqrt(sqr(px[i] - px[j]) + sqr(py[i] - py[j])));
		}
		NW::addEdge(NW::source, i, 2, 0.0);
	}

	NW::calcMinCostMaxFlow();

	if (NW::outcome_flow != n - 1)
		cout << "-1" << endl;
	else
		cout << fixed << setprecision(8) << NW::outcome_cost << endl;

	return 0;
}