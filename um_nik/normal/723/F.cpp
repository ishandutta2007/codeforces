#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 200200;
int n, m;
vector<int> g[N];
int S, T, dS, dT;
int sz[N], par[N];
bool haveST = false, haveCommon = false;
int ans[N][2];
int ansSz;
int roots[N];
int rootId[N];
int rootCnt;
int toRoot[2][N];

int getPar(int v)
{
	return (par[v] == -1 ? v : par[v] = getPar(par[v]));
}
bool unite(int v, int u)
{
	v = getPar(v);
	u = getPar(u);
	if (v == u) return false;
	if (sz[v] < sz[u]) swap(v, u);
	sz[v] += sz[u];
	par[u] = v;
	return true;
}

void read()
{
	scanf("%d%d", &n, &m);
	while(m--)
	{
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	scanf("%d%d%d%d", &S, &T, &dS, &dT);
	S--;T--;
	for (int u : g[S])
		if (u == T)
			haveST = true;
	for (int v = 0; v < n; v++)
	{
		sz[v] = 1;
		par[v] = -1;
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	read();
	for (int v = 0; v < n; v++)
	{
		if (v == S || v == T) continue;
		for (int u : g[v])
		{
			if (u == S || u == T) continue;
			if (unite(v, u))
			{
				ans[ansSz][0] = v;
				ans[ansSz][1] = u;
				ansSz++;
			}
		}
	}

	rootCnt = 0;
	for (int v = 0; v < n; v++)
	{
		rootId[v] = -1;
		if (v == S || v == T || par[v] != -1) continue;
		rootId[v] = rootCnt;
		roots[rootCnt] = v;
		toRoot[0][rootCnt] = toRoot[1][rootCnt] = -1;
		rootCnt++;
	}

	for (int v : g[S])
	{
		if (v == T) continue;
		int u = rootId[getPar(v)];
		if (toRoot[0][u] == -1)
			toRoot[0][u] = v;
	}
	for (int v : g[T])
	{
		if (v == S) continue;
		int u = rootId[getPar(v)];
		if (toRoot[1][u] == -1)
			toRoot[1][u] = v;
	}

	for (int i = 0; i < rootCnt; i++)
	{
		if (toRoot[0][i] == -1 && toRoot[1][i] == -1) throw;
		if (toRoot[0][i] == -1)
		{
			dT--;
			ans[ansSz][0] = T;
			ans[ansSz][1] = toRoot[1][i];
			ansSz++;
			continue;
		}
		if (toRoot[1][i] == -1)
		{
			dS--;
			ans[ansSz][0] = S;
			ans[ansSz][1] = toRoot[0][i];
			ansSz++;
			continue;
		}
		haveCommon = true;
	}

	if (!haveST && !haveCommon) throw;

	if (!haveCommon)
	{
		dS--;
		dT--;
		ans[ansSz][0] = S;
		ans[ansSz][1] = T;
		ansSz++;
	}
	else
	{
		bool fnd = false;
		for (int i = 0; i < rootCnt; i++)
		{
			if (toRoot[0][i] == -1 || toRoot[1][i] == -1) continue;
			if (!fnd)
			{
				fnd = true;
				dS--;
				dT--;
				ans[ansSz][0] = S;
				ans[ansSz][1] = toRoot[0][i];
				ansSz++;
				ans[ansSz][0] = T;
				ans[ansSz][1] = toRoot[1][i];
				ansSz++;
				continue;
			}
			if (dS > dT)
			{
				dS--;
				ans[ansSz][0] = S;
				ans[ansSz][1] = toRoot[0][i];
				ansSz++;
			}
			else
			{
				dT--;
				ans[ansSz][0] = T;
				ans[ansSz][1] = toRoot[1][i];
				ansSz++;
			}
		}
	}

	if (dS < 0 || dT < 0)
	{
		printf("No\n");
		return 0;
	}

	if (ansSz != n - 1) throw;
	printf("Yes\n");
	for (int i = 0; i < ansSz; i++)
		printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);

	return 0;
}