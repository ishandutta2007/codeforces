#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MaxN = 100000;

struct interval
{
	int le, ri;
};

// adj tab
const int MaxNVer = MaxN;
const int MaxNEdge = MaxN * 2;

struct halfEdge
{
    int u;
    halfEdge *next;
};
halfEdge adj_pool[MaxNEdge], *adj_tail = adj_pool;

halfEdge *adj[MaxNVer + 1];

inline void addEdge(const int &v, const int &u)
{
    adj_tail->u = u;
    adj_tail->next = adj[v], adj[v] = adj_tail++;
}

struct event
{
	int id;
	int pos;
	friend inline bool operator<(const event &lhs, const event &rhs)
	{
		if (lhs.pos != rhs.pos)
			return lhs.pos < rhs.pos;
		return lhs.id > rhs.id;
	}
};

bool succeed;
int col[MaxN + 1];

void dfs(int v)
{
	for (halfEdge *e = adj[v]; e; e = e->next)
	{
		if (col[e->u] == -1)
			col[e->u] = col[v] ^ 1, dfs(e->u);
		else if (col[e->u] == col[v])
			succeed = false;
	}
}

int main()
{
	int n;
	static interval a[MaxN + 1];

	cin >> n;
	int ev_n = 0;
	static event ev[MaxN * 2];
	for (int i = 1; i <= n; i++)
	{
		scanf("%d %d", &a[i].le, &a[i].ri);
		ev[ev_n].id = i, ev[ev_n].pos = a[i].le, ev_n++;
		ev[ev_n].id = -i, ev[ev_n].pos = a[i].ri, ev_n++;
	}

	sort(ev, ev + ev_n);

	int rest = 0;
	static int pa[MaxN + 1];
	for (int i = 0; i < ev_n; i++)
	{
		int id = abs(ev[i].id);

		if (ev[i].id > 0)
		{
			if (rest)
			{
				pa[rest] = id, pa[id] = rest;
				addEdge(rest, id), addEdge(id, rest);
				rest = 0;
			}
			else
				rest = id;
		}
		else
		{
			if (pa[id])
			{
				if (rest)
				{
					pa[rest] = pa[id], pa[pa[id]] = rest;
					addEdge(rest, pa[id]), addEdge(pa[id], rest);
					rest = 0;
				}
				else
					pa[rest = pa[id]] = 0;
			}
			else
				rest = 0;
		}
	}

	succeed = true;
	for (int v = 1; v <= n; v++)
		col[v] = -1;
	for (int v = 1; v <= n; v++)
		if (col[v] == -1)
			col[v] = 0, dfs(v);

	if (!succeed)
		cout << -1 << endl;
	else
	{
		for (int v = 1; v <= n; v++)
			printf("%d ", col[v]);
		cout << endl;
	}

	return 0;
}