#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 2000;

// adjust
template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
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

int n;
int a[MaxN + 1][MaxN + 1];

int dfn[MaxN + 1], low[MaxN + 1];
int curDfn = 0;

int nScc = 0;
int sccNum[MaxN + 1];

int sta[MaxN + 1], sta_n = 0;

void dfs(const int &v)
{
	low[v] = dfn[v] = ++curDfn;
	sta[sta_n++] = v;

	for (int u = 1; u <= n; u++)
	    if (a[v][u] > 0)
	    {
		    if (!dfn[u])
		    {
			    dfs(u);
			    tension(low[v], low[u]);
		    }
		    else if (!sccNum[u])
			    tension(low[v], dfn[u]);
	    }

	if (low[v] == dfn[v])
	{
		nScc++;
		int u;
		do
			u = sta[--sta_n], sccNum[u] = nScc;
		while (u != v);
	}
}

int main()
{
	cin >> n;
	for (int v = 1; v <= n; v++)
		for (int u = 1; u <= n; u++)
			scanf("%d", &a[v][u]);
	
	for (int v = 1; v <= n; v++)
	    if (!sccNum[v])
	        dfs(v);

	if (nScc > 1)
		printf("NO\n");
	else
		printf("YES\n");

	return 0;
}