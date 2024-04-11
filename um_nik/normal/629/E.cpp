#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 100100;
const int L = 17;
vector<int> g[N];
int par[N][L];
int h[N];
ll sumAll[N];
ll sumDown[N];
ll sz[N];
int n, q;

void dfs(int v)
{
	sumDown[v] = 0;
	sz[v] = 1;
	for (int u : g[v])
	{
		if (h[u] != -1) continue;
		h[u] = h[v] + 1;
		par[u][0] = v;
		for (int k = 1; k < L; k++)
		{
			int w = par[u][k - 1];
			if (w == -1) break;
			par[u][k] = par[w][k - 1];
		}
		dfs(u);
		sumDown[v] += sumDown[u] + sz[u];
		sz[v] += sz[u];
	}
	return;
}

void dfs2(int v)
{
	for (int u : g[v])
	{
		if (h[u] < h[v]) continue;
		sumAll[u] = sumAll[v] - sz[u] + n - sz[u];
		dfs2(u);
	}
	return;
}

void precalc()
{
	for (int i = 0; i < n; i++)
	{
		h[i] = -1;
		for (int j = 0; j < L; j++)
			par[i][j] = -1;
	}
	h[0] = 0;
	dfs(0);
	sumAll[0] = sumDown[0];
	dfs2(0);
	return;
}

int up(int v, int dh)
{
	for (int k = L - 1; k >= 0; k--)
	{
		if (dh < (1 << k)) continue;
		v = par[v][k];
		dh -= 1 << k;
	}
	return v;
}
int LCA(int v, int u)
{
	if (h[v] > h[u]) swap(v, u);
	u = up(u, h[u] - h[v]);
	if (v == u) return v;
	for (int k = L - 1; k >= 0; k--)
	{
		if (par[v][k] != par[u][k])
		{
			v = par[v][k];
			u = par[u][k];
		}
	}
	return par[v][0];
}

void query()
{
	int v, u;
	scanf("%d%d", &v, &u);
	v--;u--;
	int w = LCA(v, u);
	double res = 1 + h[v] + h[u] - 2 * h[w];
	if (v == w)
	{
		int z = up(u, h[u] - h[v] - 1);
		res += (double)(sumAll[v] - sumDown[z] - sz[z]) / (n - sz[z]);
	}
	else
		res += (double)sumDown[v] / sz[v];
	if (u == w)
	{
		int z = up(v, h[v] - h[u] - 1);
		res += (double)(sumAll[u] - sumDown[z] - sz[z]) / (n - sz[z]);
	}
	else
		res += (double)sumDown[u] / sz[u];
	printf("%.13lf\n", res);
	return;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 0; i < n - 1; i++)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	precalc();
	while(q--)
		query();

	return 0;
}