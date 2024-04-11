#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long s64;

const int Mod = 1000000007;

const int MaxN = 50;
const int MaxM = 1225;
const int MaxL = MaxN * 2;

int n, m, lmax;
int a[MaxN + 1][MaxN + 1][MaxN + 1];
int a_n[MaxN + 1][MaxN + 1];

inline int &modaddto(int &a, const int &b)
{
	return (a += b) %= Mod;
}

int path_n;
int path[MaxL + MaxN];

bool extend_path(int sv, int su, int sp, int d)
{
	path_n = 0;
	if (d == 1)
	{
		for (int i = sp; i < a_n[sv][su]; i++)
			path[path_n++] = a[sv][su][i];
	}
	else
	{
		for (int i = sp; i >= 0; i--)
			path[path_n++] = a[sv][su][i];
	}

	for (int i = 0; i + 1 < path_n && path_n <= lmax; i++)
	{
		int v = path[i], u = path[i + 1];
		if (d == 1)
		{
			if (a_n[v][u] == -1)
				return false;
			for (int j = 0; j < a_n[v][u]; j++)
				path[path_n++] = a[v][u][j];
		}
		else
		{
			if (a_n[u][v] == -1)
				return false;
			for (int j = a_n[u][v] - 1; j >= 0; j--)
				path[path_n++] = a[u][v][j];
		}
	}
	return path_n <= lmax;
}

int main()
{
	cin >> n >> m;
	lmax = n * 2;
	for (int v = 1; v <= n; v++)
		for (int u = 1; u <= n; u++)
			a_n[v][u] = -1;
	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		scanf("%d", &a_n[v][u]);
		for (int k = 0; k < a_n[v][u]; k++)
			scanf("%d", &a[v][u][k]);
	}

	static int g[MaxL + 1][MaxN + 1][MaxN + 1];
	for (int ev = 1; ev <= n; ev++)
		for (int eu = 1; eu <= n; eu++)
			if (a_n[ev][eu] >= 2)
				for (int p = 0; p + 1 < a_n[ev][eu]; p++)
					if (a[ev][eu][p] == ev && a[ev][eu][p + 1] == eu)
					{
						int st, ed;
						int cur_n = 0;
						if (!extend_path(ev, eu, p, -1))
							continue;
						st = path[path_n - 1];
						cur_n += path_n;

						if (!extend_path(ev, eu, p + 1, 1))
							continue;
						ed = path[path_n - 1];
						cur_n += path_n;

						cur_n--;

						if (cur_n <= lmax)
							g[cur_n][st][ed]++;
					}

	int li_n;
	static int li_v[MaxM], li_u[MaxM], li_l[MaxM];

	li_n = 0;
	for (int ev = 1; ev <= n; ev++)
		for (int eu = 1; eu <= n; eu++)
			if (a_n[ev][eu] >= 1 && a[ev][eu][a_n[ev][eu] - 1] == ev)
			{
				if (!extend_path(ev, eu, a_n[ev][eu] - 1, -1))
					continue;
				li_v[li_n] = path[path_n - 1], li_u[li_n] = eu, li_l[li_n] = path_n, li_n++;
			}
	for (int l = 1; l <= lmax; l++)
		for (int u = 1; u <= n; u++)
			for (int i = 0; i < li_n; i++)
				if (l + li_l[i] <= lmax)
					modaddto(g[l + li_l[i]][li_v[i]][u], g[l][li_u[i]][u]);

	li_n = 0;
	for (int ev = 1; ev <= n; ev++)
		for (int eu = 1; eu <= n; eu++)
			if (a_n[ev][eu] >= 1 && a[ev][eu][0] == eu)
			{
				if (!extend_path(ev, eu, 0, 1))
					continue;
				li_v[li_n] = ev, li_u[li_n] = path[path_n - 1], li_l[li_n] = path_n, li_n++;
			}
	for (int l = 1; l <= lmax; l++)
		for (int v = 1; v <= n; v++)
			for (int i = 0; i < li_n; i++)
				if (l + li_l[i] <= lmax)
					modaddto(g[l + li_l[i]][v][li_u[i]], g[l][v][li_v[i]]);

	static int ga[MaxL + 1][MaxN + 1][MaxN + 1];
	for (int l = 1; l <= lmax - 1; l++)
		for (int v = 1; v <= n; v++)
			for (int u = 1; u <= n; u++)
				for (int k = 1; k <= n; k++)
					if (a_n[k][v] == 0)
						modaddto(ga[l + 1][k][u], g[l][v][u]);

	static int res[MaxL + 1][MaxN + 1];
	for (int l = 1; l <= lmax; l++)
		for (int v = 1; v <= n; v++)
			for (int u = 1; u <= n; u++)
				modaddto(res[l][u], g[l][v][u]);
	for (int l = 1; l <= lmax; l++)
		for (int u = 1; u <= n; u++)
			for (int k = 1; k <= n; k++)
				for (int p = 1; l + p <= lmax; p++)
					modaddto(res[l + p][k], (s64)res[l][u] * ga[p][u][k] % Mod);

	for (int l = 1; l <= lmax; l++)
	{
		int cur = 0;
		for (int v = 1; v <= n; v++)
			(cur += res[l][v]) %= Mod;
		printf("%d\n", cur);
	}

	return 0;
}