#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

typedef long long s64;

const s64 INF = 1000000000000000000ll;

const int MaxN = 10000;
const int MaxNS = 100;
const int MaxM = 10100;

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
	int u, w;
	halfEdge *next;
};
halfEdge adj_pool[MaxM * 2], *adj_tail = adj_pool;

inline void addEdge(halfEdge **adj, int v, int u, int w)
{
	adj_tail->u = u, adj_tail->w = w, adj_tail->next = adj[v], adj[v] = adj_tail++;
}

int main()
{
	int n, m, nS;
	int vA, vB, vT;
	cin >> n >> m >> nS;
	cin >> vA >> vB >> vT;

	static halfEdge *oriG[MaxN + 1];
	static halfEdge *oppG[MaxN + 1];

	for (int i = 0; i < m; i++)
	{
		int v, u, w;
		scanf("%d %d %d", &v, &u, &w);
		addEdge(oriG, v, u, w);
		addEdge(oppG, u, v, w);
	}

	static halfEdge *sE[MaxNS + 1];
	static int sL[MaxNS + 1], sR[MaxNS + 1];
	for (int i = 1; i <= nS; i++)
	{
		int v, u;
		scanf("%d %d %d %d", &v, &u, &sL[i], &sR[i]);

		addEdge(oriG, v, u, sR[i]);
		sE[i] = adj_tail, addEdge(oppG, u, v, -i);
	}

	priority_queue< pair<s64, int> > q;
	static s64 dB[MaxN + 1];
	for (int v = 1; v <= n; v++)
		dB[v] = INF;
	dB[vB] = 0, q.push(make_pair(-dB[vB], vB));
	while (!q.empty())
	{
		pair<s64, int> cur = q.top();
		q.pop();
		if (dB[cur.second] != -cur.first)
			continue;
		int v = cur.second;
		for (halfEdge *e = oriG[v]; e; e = e->next)
			if (tension(dB[e->u], dB[v] + e->w))
				q.push(make_pair(-dB[e->u], e->u));
	}

	static s64 d[MaxN + 1];
	for (int v = 1; v <= n; v++)
		d[v] = INF;
	d[vT] = 0, q.push(make_pair(-d[vT], vT));
	while (!q.empty())
	{
		pair<s64, int> cur = q.top();
		q.pop();
		if (d[cur.second] != -cur.first)
			continue;
		int v = cur.second;
		for (halfEdge *e = oppG[v]; e; e = e->next)
		{
			if (e->w < 0)
			{
				if (dB[e->u] == INF)
					e->w = sL[-e->w];
				else
					e->w = max(dB[vT] - dB[e->u] - d[v], (s64)sL[-e->w]);
			}
			if (tension(d[e->u], d[v] + e->w))
				q.push(make_pair(-d[e->u], e->u));
		}
	}

	if (d[vA] <= dB[vT])
	{
		puts(d[vA] < dB[vT] ? "WIN" : "DRAW");
		for (int i = 1; i <= nS; i++)
			printf("%d ", sE[i]->w < 0 ? sR[i] : sE[i]->w);
		printf("\n");
	}
	else
		puts("LOSE");

	return 0;
}