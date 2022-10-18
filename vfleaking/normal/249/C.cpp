#include <iostream>
#include <cstdio>
using namespace std;

const int MaxN = 100000;
const int MaxA = 100;
const int MaxK = 5;

inline double C(const int &n, const int &m)
{
	double res = 1.0;
	for (int i = 0; i < m; i++)
		res *= n - i, res /= i + 1;
	return res;
}

int main()
{
	int n;
	static int orig[MaxN + 1];
	static int a[MaxN + 1];
	static double p[MaxN + 1][MaxA + 1];
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &orig[i]);
		a[i] = orig[i];
	}
	
	for (int i = 1; i <= n; i++)
		p[i][a[i]] = 1.0;
	
	double res = 0.0;
	for (int i = 1; i <= n; i++)
		res += p[i][0];
	
	int q;
	cin >> q;
	while (q--)
	{
		int u, v, k;
		scanf("%d %d %d", &u, &v, &k);
		
		res -= p[u][0];

		double tot = C(a[u], k);
		for (int i = 0; i <= orig[u]; i++)
		{
			double t = p[u][i];
			p[u][i] = 0.0;

			int minj = max(k - a[u] + i, 0);
			int maxj = min(k, i);
			if (minj <= maxj)
			{
				t *= C(i, minj) * C(a[u] - i, k - minj) / tot;
				for (int j = minj; j <= maxj; j++)
				{
					p[u][i - j] += t;
					t *= (i - j) * (k - j);
					t /= (j + 1) * (a[u] - i - k + j + 1);
				}
			}
		}
		
		a[u] -= k, a[v] += k;
		
		res += p[u][0];
		printf("%.13lf\n", res);
	}
	
	return 0;
}