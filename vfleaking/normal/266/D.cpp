#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

const int MaxN = 200;
const int MaxM = MaxN * (MaxN - 1) / 2;

struct compareInArray
{
	const int *a;
	compareInArray(const int *_a)
		: a(_a){}

	inline bool operator()(const int &lhs, const int &rhs) const
	{
		return a[lhs] < a[rhs];
	}
};

int main()
{
	int n, m;
	static int e_v[MaxM], e_u[MaxM], e_w[MaxM];
	static int f[MaxN + 1][MaxN + 1];

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = i == j ? 0 : INT_MAX;
	for (int i = 0; i < m; i++)
	{
		cin >> e_v[i] >> e_u[i] >> e_w[i];
		f[e_v[i]][e_u[i]] = f[e_u[i]][e_v[i]] = e_w[i];
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			if (f[i][k] != INT_MAX)
				for (int j = 1; j <= n; j++)
					if (f[k][j] != INT_MAX && f[i][k] + f[k][j] < f[i][j])
						f[i][j] = f[i][k] + f[k][j];

	double res = HUGE_VAL;
	for (int v = 1; v <= n; v++)
	{
		int cur = 0;
		for (int u = 1; u <= n; u++)
			if (f[v][u] > cur)
				cur = f[v][u];
		if (cur < res)
			res = cur;
	}
	for (int i = 0; i < m; i++)
	{
		int v = e_v[i], u = e_u[i], w = e_w[i];
		
		int q_n = 0;
		static int q[MaxN];
		for (int s = 1; s <= n; s++)
			q[q_n++] = s;
		sort(q, q + q_n, compareInArray(f[v]));

		q_n = 0;
		for (int i = 0; i < n; i++)
		{
			while (q_n > 0 && f[u][q[i]] >= f[u][q[q_n - 1]])
				q_n--;
			q[q_n++] = q[i];
		}

		for (int i = 0; i + 1 < q_n; i++)
		{
			int s = q[i + 1], t = q[i];
			double cur = (double)(f[u][s] + w + f[v][t]) / 2;
			if (cur < res)
				res = cur;
		}
	}

	cout << res << endl;

	return 0;
}