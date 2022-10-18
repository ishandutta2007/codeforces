#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MaxN = 500;
const int MaxM = 10000;

struct edge
{
	int v, u;
	edge(){}
	edge(const int &_v, const int &_u)
		: v(_v), u(_u){}
};

int n, m;
edge e[MaxM + 1];

inline int ufs_find(int *f, const int &v)
{
	if (f[v] != v)
		f[v] = ufs_find(f, f[v]);
	return f[v];
}

inline void ufs_union(int *f, const int &v, const int &u)
{
	f[ufs_find(f, v)] = ufs_find(f, u);
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);

		e[i] = edge(v, u);
	}

	static int pre[MaxM + 1][MaxN + 1];
	for (int v = 1; v <= n; v++)
		pre[0][v] = v;
	for (int i = 1; i <= m; i++)
	{
		copy(pre[i - 1] + 1, pre[i - 1] + n + 1, pre[i] + 1);
		if (pre[i][e[i].v] != pre[i][e[i].u])
		{
			int t = pre[i][e[i].u];
			for (int v = 1; v <= n; v++)
				if (pre[i][v] == t)
					pre[i][v] = pre[i][e[i].v];
		}
	}

	static int suf[1 + MaxM + 1][MaxN + 1];
	for (int v = 1; v <= n; v++)
		suf[m + 1][v] = v;
	for (int i = m; i >= 1; i--)
	{
		copy(suf[i + 1] + 1, suf[i + 1] + n + 1, suf[i] + 1);
		if (suf[i][e[i].v] != suf[i][e[i].u])
		{
			int t = suf[i][e[i].u];
			for (int v = 1; v <= n; v++)
				if (suf[i][v] == t)
					suf[i][v] = suf[i][e[i].v];
		}
	}

	int nQ;
	cin >> nQ;
	while (nQ--)
	{
		int l, r;
		scanf("%d %d", &l, &r);

		int *f = pre[l - 1], *g = suf[r + 1];

		static int cur[MaxN + 1];
		copy(f + 1, f + n + 1, cur + 1);
		for (int v = 1; v <= n; v++)
			ufs_union(cur, v, g[v]);

		int res = 0;
		for (int v = 1; v <= n; v++)
			if (cur[v] == v)
				res++;

		printf("%d\n", res);
	}

	return 0;
}