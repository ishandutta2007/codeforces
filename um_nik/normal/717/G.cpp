#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int INF = (int)1e9 + 10;

struct Edge
{
	int v, to, cap, cost;

	Edge() : v(), to(), cap(), cost() {}
	Edge(int _v, int _to, int _cap, int _cost) : v(_v), to(_to), cap(_cap), cost(_cost) {}
};

const int V = 550;
const int E = (int)3e5;
Edge ed[E];
int dist[V];
int par[V];
int n, m, p;

void addEdge(int v, int to, int cap, int cost)
{
	ed[m++] = Edge(v, to, cap, cost);
	ed[m++] = Edge(to, v, 0, -cost);
	return;
}

void read()
{
	cin >> n;
	n++;
	string s;
	cin >> s;
	int k;
	cin >> k;
	while(k--)
	{
		string t;
		int val;
		cin >> t >> val;
		val *= -1;
		for (int i = 0; i + t.length() <= s.length(); i++)
			if (s.substr(i, t.length()) == t)
				addEdge(i, i + t.length(), 1, val);
	}
	cin >> p;
	for (int i = 0; i < n - 1; i++)
		addEdge(i, i + 1, p, 0);
	return;
}

int FB()
{
	for (int i = 0; i < n; i++)
		dist[i] = INF;
	dist[0] = 0;
	bool ch = true;
	while(ch)
	{
		ch = false;
		for (int id = 0; id < m; id++)
		{
			Edge e = ed[id];
			if (e.cap == 0) continue;
			int v = e.v, to = e.to;
			if (dist[v] == INF) continue;
			if (dist[to] <= dist[v] + e.cost) continue;
			dist[to] = dist[v] + e.cost;
			par[to] = id;
			ch = true;
		}
	}
	int v = n - 1;
	if (dist[v] == INF) throw;
	while(v)
	{
		int id = par[v];
		ed[id].cap--;
		ed[id ^ 1].cap++;
		v = ed[id].v;
	}
	return dist[n - 1];
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	int ans = 0;
	for (int i = 0; i < p; i++)
		ans -= FB();
	printf("%d\n", ans);

	return 0;
}