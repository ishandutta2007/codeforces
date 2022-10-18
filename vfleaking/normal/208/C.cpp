#include <iostream>
#include <iomanip>
#include <cstdio>
#include <climits>
using namespace std;

const int MaxN = 100;

template <class T>
inline void relax(T &a, const T &b)
{
	if (b > a)
		a = b;
}

int main()
{
	int n, m;
	static int f[MaxN + 1][MaxN + 1];
	static double g[MaxN + 1][MaxN + 1];
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = INT_MAX;
	for (int i = 1; i <= m; i++)
	{
		int v, u;
		scanf("%d %d", &v, &u);
		f[v][u] = f[u][v] = 1;
		g[v][u] = g[u][v] = 1.0;
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			if (f[i][k] != INT_MAX)
				for (int j = 1; j <= n; j++)
					if (f[k][j] != INT_MAX)
					{
						int t = f[i][k] + f[k][j];
						if (t == f[i][j])
							g[i][j] += g[i][k] * g[k][j];
						else if (t < f[i][j])
						{
							f[i][j] = t;
							g[i][j] = g[i][k] * g[k][j];
						}
					}
	
	double res = 1.0;
	for (int i = 2; i < n; i++)
		if (f[1][i] + f[i][n] == f[1][n])
			relax(res, g[1][i] * g[i][n] * 2 / g[1][n]);
	cout << setprecision(7) << setiosflags(ios::fixed) << res << endl;

	return 0;
}