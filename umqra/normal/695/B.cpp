#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>

#include <functional>
#include <complex>
#include <valarray>
#include <cassert>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
#define X first
#define Y second
#define mp make_pair

const int INF = (int)2e9 + 10;


const int N = 2000;
const int E = (int)5e5 + 10;

struct Edge
{
	int id, to, cost;
	Edge () : id(), to(), cost() {}
	Edge (int _id, int _to, int _cost) : id(_id), to(_to), cost(_cost) {}
};

vector <Edge> g[N];
int edgeCost[E];
int n, m;
int S, T;

void read()
{
	scanf("%d%d", &n, &m);
	scanf("%d%d", &S, &T);
	S--, T--;
	for (int i = 0; i < m; i++)
	{
		int a, b, cost;
		scanf("%d%d%d", &a, &b, &cost);
		a--, b--;
		g[a].push_back(Edge(i, b, cost));
		g[b].push_back(Edge(i, a, cost));
		edgeCost[i] = cost;
	}
}

int par[N];
int parId[N];
int used[N];

void dfs(int v)
{
	used[v] = 1;
	for (auto &e : g[v])
	{
		if (!used[e.to])
		{
			par[e.to] = v;
			parId[e.to] = e.id;
			dfs(e.to);
		}
	}
}

void Answer(int cost, vector <int> e)
{
	printf("%d\n", cost);
	if (cost == -1)
		exit(0);
	printf("%d\n", (int)e.size());
	for (int x : e)
		printf("%d ", x + 1);
	puts("");
	exit(0);
}

int usedEdge[E];
int tin[N], tup[N];
int tme = 0;
int isBridge[E];
int cc = 1;
int bridgePar[N];
int bridgeParId[N];

void findBridges(int v, int edgeId)
{
	used[v] = 1;
	tin[v] = tme++;
	tup[v] = tin[v];
	for (auto &e : g[v])
	{
		if (usedEdge[e.id])
			continue;

		if (!used[e.to])
		{
			bridgePar[e.to] = v;
			bridgeParId[e.to] = e.id;


			findBridges(e.to, e.id);
			tup[v] = min(tup[v], tup[e.to]);
			if (tup[e.to] > tin[v])
				isBridge[e.id] = cc;
		}
		else if (used[e.to] && e.id != edgeId)
		{
			tup[v] = min(tup[v], tin[e.to]);
		}
	}
}

int ansValue = INF;
vector <int> ansEdge = {};

void relaxAnswerWith(int cost, vector <int> edges)
{
	if (cost < ansValue)
	{
		ansValue = cost;
		ansEdge = edges;
	}
}

void relaxAnswer(int cost, int edge)
{
	fill(used, used + n, 0);
	tme = 0;
	cc++;
	findBridges(S, -1);
	int v = T;
	if (!used[T])
	{
		relaxAnswerWith(cost, {edge});
		return;
	}
	while (v != S)
	{
		int p = bridgePar[v];
		int e = bridgeParId[v];
		if (isBridge[e] == cc)
			relaxAnswerWith(cost + edgeCost[e], {edge, e});
		v = p;
	}
}

void solve()
{
	memset(par, -1, sizeof(par));
	dfs(S);
	if (par[T] == -1)
		Answer(0, {});
	int v = T;
	while (v != S)
	{
		int p = par[v];
		int blocked = parId[v];
		usedEdge[blocked] = 1;
		relaxAnswer(edgeCost[blocked], blocked);
		usedEdge[blocked] = 0;
		v = p;
	}
	if (ansValue != INF)
		Answer(ansValue, ansEdge);
	else
		Answer(-1, {});
}

int main()
{
#ifdef LOCAL
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#endif

	read();
	solve();

	return 0;
}