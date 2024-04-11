#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

typedef long long ll;
const ll INF = (ll)1e17;

const int N = 1010;
const int M = (int)1e4 + 100;
int n, m;
ll dist[N];
vector<int> g[N];
int ed[M][2];
ll edW[M];
bool fix[M];
ll L;
int S, T;
bool used[N];

int getOther(int id, int v)
{
	return v ^ ed[id][0] ^ ed[id][1];
}

void read()
{
	scanf("%d%d%lld%d%d", &n, &m, &L, &S, &T);
	for (int i = 0; i < m; i++)
	{
		int v, u;
		ll w;
		scanf("%d%d%lld", &v, &u, &w);
		ed[i][0] = v;
		ed[i][1] = u;
		edW[i] = w;
		g[v].push_back(i);
		g[u].push_back(i);
		if (w > 0)
			fix[i] = 1;
	}
	return;
}

void build(ll w, int b)
{
	for (int i = 0; i < m; i++)
	{
		if (fix[i]) continue;
		edW[i] = w + (i >= b ? 1 : 0);
	}
	return;
}

void dijkstra()
{
	for (int i = 0; i < n; i++)
	{
		used[i] = 0;
		dist[i] = INF;
	}
	dist[S] = 0;
	for (int it = 0; it < n; it++)
	{
		int v = -1;
		for (int i = 0; i < n; i++)
		{
			if (used[i]) continue;
			if (v == -1 || dist[i] < dist[v])
				v = i;
		}
		if (v == -1 || dist[v] == INF) return;
		used[v] = 1;
		for (int id : g[v])
		{
			int u = getOther(id, v);
			dist[u] = min(dist[u], dist[v] + edW[id]);
		}
	}
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	ll l = 0, r = L + 2;
	while(r - l > 1)
	{
		ll x = (l + r) / 2;
		build(x, m);
		dijkstra();
		if (dist[T] <= L)
			l = x;
		else
			r = x;
	}
	if (l == 0)
	{
		printf("NO\n");
		return 0;
	}
	ll w = l;
	l = 0;
	r = m;
	while(r - l > 1)
	{
		ll x = (l + r) / 2;
		build(w, x);
		dijkstra();
		if (dist[T] <= L)
			r = x;
		else
			l = x;
	}
	build(w, r);
	dijkstra();
	if (dist[T] != L)
	{
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	for (int i = 0; i < m; i++)
		printf("%d %d %lld\n", ed[i][0], ed[i][1], edW[i]);

	return 0;
}