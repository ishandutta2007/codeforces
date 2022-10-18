#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

typedef long long s64;
const s64 S64_MAX = 9223372036854775807ll;

const int MaxN = 500;
const int MaxNC = 500;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}

int n, maxD, nC;
int cCost[MaxN + 1];
int mat[MaxN + 1][MaxN + 1];
s64 dist[MaxN + 1][MaxN + 1];

struct dpArray
{
	int *f;
	int f_n;

	dpArray()
	{
		f_n = 0;
		f = new int[1];
	}
	dpArray(const int &_f_n)
		: f_n(_f_n)
	{
		f = new int[f_n + 1];
	}
	~dpArray()
	{
		delete []f;
	}

	inline void print()
	{
		for (int i = 0; i <= f_n; i++)
			cout << f[i] << " ";
		cout << endl;
	}

	inline dpArray& operator=(const dpArray &rhs)
	{
		f_n = rhs.f_n;
		f = new int[f_n + 1];
		copy(rhs.f, rhs.f + rhs.f_n + 1, f);
		return *this;
	}
	inline dpArray& operator+=(const dpArray &rhs)
	{
		int *nf = new int[f_n + rhs.f_n + 1];
		fill(nf, nf + f_n + rhs.f_n + 1, nC + 1);
		for (int i = 0; i <= f_n; i++)
			if (f[i] != nC + 1)
				for (int j = 0; j <= rhs.f_n; j++)
					tension(nf[i + j], f[i] + rhs.f[j]);
		delete []f;
		f = nf;
		f_n += rhs.f_n;

		return *this;
	}
	inline dpArray& update(const dpArray &rhs)
	{
		if (rhs.f_n <= f_n)
		{
			for (int i = 0; i <= rhs.f_n; i++)
				tension(f[i], rhs.f[i]);
		}
		else
		{
			int *nf = new int[rhs.f_n + 1];
			for (int i = 0; i <= f_n; i++)
				nf[i] = min(f[i], rhs.f[i]);
			for (int i = f_n + 1; i <= rhs.f_n; i++)
				nf[i] = rhs.f[i];
			delete []f;
			f = nf;
			f_n = rhs.f_n;
		}
		return *this;
	}
};

dpArray f[MaxN + 1][MaxN + 1];

void dfs(const int &v, const int &fa)
{
	for (int u = 1; u <= n; u++)
		if (mat[v][u] != INT_MAX && u != fa)
			dfs(u, v);

	dpArray inTreeF;
	inTreeF.f[0] = nC + 1;
	for (int x = 1; x <= n; x++)
		if (dist[1][x] == dist[1][v] + dist[v][x])
		{
			dpArray &fvx = f[v][x];
			fvx.f[0] = nC + 1;
			if (dist[v][x] <= maxD)
			{
				if (x != v)
					fvx.f[0] = 0;
				else
					fvx = dpArray(1), fvx.f[0] = nC + 1, fvx.f[1] = cCost[x];
				for (int u = 1; u <= n; u++)
					if (mat[v][u] != INT_MAX && u != fa)
						fvx += f[u][x];
			}

			inTreeF.update(fvx);
		}

	for (int x = 1; x <= n; x++)
		if (dist[1][x] != dist[1][v] + dist[v][x])
		{
			dpArray &fvx = f[v][x];
			fvx.f[0] = nC + 1;
			if (dist[v][x] <= maxD)
			{
				fvx.f[0] = 0;
				for (int u = 1; u <= n; u++)
					if (mat[v][u] != INT_MAX && u != fa)
						fvx += f[u][x];
			}

			fvx.update(inTreeF);
		}
}

int main()
{
	cin >> n >> maxD;
	for (int v = 1; v <= n; v++)
	{
		scanf("%d", &cCost[v]);
		nC += cCost[v] == 1;
		cCost[v] = 1 - cCost[v];
	}
	for (int v = 1; v <= n; v++)
		for (int u = 1; u <= n; u++)
			mat[v][u] = INT_MAX;
	for (int i = 0; i < n - 1; i++)
	{
		int v, u, w;
		scanf("%d %d %d", &v, &u, &w);
		mat[v][u] = mat[u][v] = w;
	}

	for (int v = 1; v <= n; v++)
		for (int u = 1; u <= n; u++)
			dist[v][u] = mat[v][u] == INT_MAX ? S64_MAX : mat[v][u];
	for (int v = 1; v <= n; v++)
		dist[v][v] = 0;
	for (int k = 1; k <= n; k++)
		for (int v = 1; v <= n; v++)
			if (dist[v][k] != S64_MAX)
				for (int u = 1; u <= n; u++)
					if (dist[k][u] != S64_MAX)
						tension(dist[v][u], dist[v][k] + dist[k][u]);

	dfs(1, 0);

	int res = nC + 1;
	for (int v = 1; v <= n; v++)
		if (f[1][v].f_n >= nC)
			tension(res, f[1][v].f[nC]);
	if (res == nC + 1)
		cout << -1 << endl;
	else
		cout << res << endl;

	return 0;
}