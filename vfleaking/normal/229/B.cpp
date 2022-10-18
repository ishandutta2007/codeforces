#include <iostream>
#include <cstdio>
#include <functional>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;

const int MaxN = 100000;

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
	int u, time;

	halfEdge(){}
	halfEdge(const int &_u, const int &_time) : u(_u), time(_time){}
};

int main()
{
	int n, m;
	static vector<halfEdge> adj[MaxN + 1];

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int v, u, time;
		scanf("%d %d %d", &v, &u, &time);

		adj[v].push_back(halfEdge(u, time));
		adj[u].push_back(halfEdge(v, time));
	}

	static vector<int> forbidden[MaxN + 1];
	for (int i = 1; i <= n; i++)
	{
		int nForbidden;
		scanf("%d", &nForbidden);
		for (int j = 0; j < nForbidden; j++)
		{
			int t;
			scanf("%d", &t);
			forbidden[i].push_back(t);
		}
		forbidden[i].push_back(INT_MAX);
	}

	priority_queue< pair<int, int>,
		            vector< pair<int, int> >,
					greater< pair<int, int> > > q;
	static int dist[MaxN + 1];
	static bool finished[MaxN + 1];
	
	fill(dist + 1, dist + n + 1, INT_MAX);
	fill(finished + 1, finished + n + 1, false);

	dist[1] = 0;
	q.push(make_pair(dist[1], 1));

	while (!q.empty())
	{
		int v = q.top().second;
		q.pop();

		if (finished[v])
			continue;

		finished[v] = true;

		if (v == n)
			break;

		int dv = dist[v];
		while (*lower_bound(forbidden[v].begin(), forbidden[v].end(),
					        dv) == dv)
			dv++;

		for (vector<halfEdge>::iterator j = adj[v].begin();
			 j != adj[v].end(); j++)
			if (tension(dist[j->u], dv + j->time))
				q.push(make_pair(dist[j->u], j->u));
	}

	printf("%d\n", dist[n] != INT_MAX ? dist[n] : -1);

	return 0;
}