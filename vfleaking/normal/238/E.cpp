#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

const int MaxN = 100;
const int MaxNBus = 100;

const int INF = INT_MAX / 2;

template <class T>
inline void tension(T &a, const T &b)
{
	if (b < a)
		a = b;
}
template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n, m, a, b;
	static int f[MaxN + 1][MaxN + 1];
	int nBus;
	static int from[MaxNBus], to[MaxNBus];

	cin >> n >> m >> a >> b;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = i == j ? 0 : INF;
	for (int i = 0; i < m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		f[v][u] = 1;
	}
	
	cin >> nBus;
	for (int i = 0; i < nBus; i++)
		scanf("%d %d", &from[i], &to[i]);
	
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			if (f[i][k] != INF)
				for (int j = 1; j <= n; j++)
					if (f[k][j] != INF)
						tension(f[i][j], f[i][k] + f[k][j]);

	static vector<int> poss[MaxNBus][MaxN + 1];
	for (int i = 0; i < nBus; i++)
	{
		if (f[from[i]][to[i]] == INF)
			continue;
		for (int j = 1; j <= n; j++)
			if (f[from[i]][j] + f[j][to[i]] == f[from[i]][to[i]])
				poss[i][f[from[i]][j]].push_back(j);
	}
	
	static int res[MaxN + 1];
	fill(res + 1, res + n + 1, INT_MAX);
	res[b] = 0;

	bool updated = true;
	int d = 0;
	while (updated)
	{
		updated = false;
		d++;
		for (int i = 0; i < nBus; i++)
		{
			if (f[from[i]][to[i]] == INF)
				continue;

			static int t[MaxN + 1];
			t[to[i]] = res[to[i]];
			for (int j = f[from[i]][to[i]] - 1; j >= 0; j--)
			{
				for (vector<int>::iterator k = poss[i][j].begin(); k != poss[i][j].end(); k++)
				{
					t[*k] = 0;
					for (vector<int>::iterator u = poss[i][j + 1].begin(); u != poss[i][j + 1].end(); u++)
						if (f[*k][*u] == 1)
							relax(t[*k], t[*u]);
					tension(t[*k], res[*k]);
				}
				if (poss[i][j].size() == 1)
				{
					int u = poss[i][j][0];
					if (res[u] == INT_MAX && t[u] < d)
					{
						res[u] = d;
						updated = true;
					}
				}
			}
		}
	}

	cout << (res[a] != INT_MAX ? res[a] : -1) << endl;
	
	return 0;
}