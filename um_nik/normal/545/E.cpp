#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;
#define mp make_pair
#define X first
#define Y second

const int N = (int)3e5 + 200;
int n, m;

struct Edge
{
	int v, u;
	ll w;

	Edge() : v(), u(), w() {}
	Edge(int _v, int _u, ll _w) : v(_v), u(_u), w(_w) {}

	void scan()
	{
		scanf("%d%d%I64d", &v, &u, &w);
		v--;u--;
	}

	int getOther(int V)
	{
		return v ^ u ^ V;
	}
};

const ll INF = (ll)1e17;

Edge ed[N];
vector<int> g[N];
ll dist[N];
int par[N];
set<pli> setik;
int V;

void read()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		ed[i].scan();
		g[ed[i].v].push_back(i);
		g[ed[i].u].push_back(i);
	}
	scanf("%d", &V);
	V--;
	return;
}

void solve()
{
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[V] = 0;
	for (int i = 0; i < n; i++)
		setik.insert(mp(dist[i], i));
	while(!setik.empty())
	{
		int v = setik.begin()->Y;
		setik.erase(setik.begin());
		for (int e : g[v])
		{
			int to = ed[e].getOther(v);
			ll w = ed[e].w;
			if (dist[v] + w > dist[to]) continue;
			if (dist[v] + w == dist[to] && w >= ed[par[to]].w) continue;
			setik.erase(mp(dist[to], to));
			dist[to] = dist[v] + w;
			par[to] = e;
			setik.insert(mp(dist[to], to));
		}
	}
	ll sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (i == V) continue;
		sum += ed[par[i]].w;
	}
	cout << sum << endl;
	for (int i = 0; i < n; i++)
	{
		if (i == V) continue;
		printf("%d ", par[i] + 1);
	}
	printf("\n");
	return;
}

int main()
{
	read();
	solve();

	return 0;
}