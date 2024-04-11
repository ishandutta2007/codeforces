#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;
typedef long long ll;

const int N = (int)1e5 + 100;
int n;
int q;

struct Edge
{
	int v, u;
	ll len;
	ll val;

	Edge() : v(), u(), len(), val() {}
	Edge (int _v, int _u, ll _len) : v(_v), u(_u), len(_len), val() {}

	void scan()
	{
		scanf("%d%d%I64d", &v, &u, &len);
	}
};

vector<int> g[N];
Edge ed[N];
ll sz[N];
bool used[N];
ll ans;

void read()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		ed[i].scan();
		g[ ed[i].v ].push_back(i);
		g[ ed[i].u ].push_back(i);
	}
	return;
}

void dfs(int v)
{
	used[v] = 1;
	sz[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		Edge e = ed[g[v][i]];
		int to = (e.v == v ? e.u : e.v);
		if (used[to]) continue;
		dfs(to);
		sz[v] += sz[to];
		ed[g[v][i]].val = sz[to] * (n - sz[to]);
		ans += sz[to] * (n - sz[to]) * e.len;
	}
	return;
}

void precalc()
{
	ans = 0;
	dfs(1);
	return;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	read();
	precalc();

	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int idx;
		ll nw;
		scanf("%d%I64d", &idx, &nw);
		ans -= ed[idx].val * (ed[idx].len - nw);
		ed[idx].len = nw;
		printf("%.10lf\n", (double)ans / (double)n / (double)(n - 1) * 6.);
	}

	return 0;
}