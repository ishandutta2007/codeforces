#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1010;
const int M = 500500;

typedef pair<int, int> pii;
#define mp make_pair

struct Edge
{
	int v, u;
	int id;
	int w;

	Edge() : v(), u(), id(), w() {}

	void scan(int _id)
	{
		id = _id;
		scanf("%d%d%d", &v, &u, &w);
		v--;u--;
	}

	bool operator < (const Edge &e) const
	{
		return w > e.w;
	}
};

Edge ed[M];
pii par[N];
int sz[N];
int n, m, q;

void read()
{
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; i++)
		ed[i].scan(i + 1);
	sort(ed, ed + m);
	return;
}

pii getPar(int v)
{
	if (par[v].first == -1)
		return mp(v, 0);
	pii t = getPar(par[v].first);
	t.second ^= par[v].second;
	return par[v] = t;
}

bool unite(int v, int u)
{
	pii V = getPar(v), U = getPar(u);
	if (V.first == U.first)
		return V.second ^ U.second;
	if (sz[V.first] < sz[U.first])
		swap(V, U);
	sz[V.first] += sz[U.first];
	par[U.first] = mp(V.first, V.second ^ U.second ^ 1);
	return true;
}

int solve()
{
	int l, r;
	scanf("%d%d", &l, &r);
	for (int i = 0; i < n; i++)
	{
		par[i] = mp(-1, 0);
		sz[i] = 1;
	}
	for (int i = 0; i < m; i++)
	{
		if (ed[i].id < l || ed[i].id > r) continue;
		if (!unite(ed[i].v, ed[i].u))
			return ed[i].w;
	}
	return -1;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	while(q--)
		printf("%d\n", solve());

	return 0;
}