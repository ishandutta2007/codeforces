#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MaxN = 80;

int main()
{
	int n;
	int px_n = 0;
	static int px[MaxN * 2];
	int pL[MaxN + 1], pR[MaxN + 1];

	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &pL[i], &pR[i]), px[px_n++] = pL[i], px[px_n++] = pR[i];
	sort(px, px + px_n), px_n = unique(px, px + px_n) - px;

	for (int v = 1; v <= n; v++)
	{
		static double f[MaxN + 1];
		fill(f, f + n + 1, 0);

		for (int p = 0; p + 1 < px_n; p++)
			if (pL[v] <= px[p] && px[p + 1] <= pR[v])
			{
				static double g[MaxN][MaxN];
				memset(g, 0, sizeof(g));

				g[0][0] = 1.0;
				int tot = 0;
				for (int u = 1; u <= n; u++)
					if (u != v)
					{
						double a, b;
						if (pR[u] <= px[p])
							a = 0, b = 1;
						else if (pL[u] <= px[p])
							a = (double)(px[p + 1] - px[p]) / (pR[u] - pL[u]), b = (double)(px[p] - pL[u]) / (pR[u] - pL[u]);
						else
							continue;

						tot++;

						for (int i = tot; i >= 0; i--)
							for (int j = tot - i; j >= 0; j--)
							{
								g[i][j] *= 1 - a - b;
								if (i > 0)
									g[i][j] += g[i - 1][j] * a;
								if (j > 0)
									g[i][j] += g[i][j - 1] * b;
							}
					}

				double prp = (double)(px[p + 1] - px[p]) / (pR[v] - pL[v]);
				for (int i = 0; i <= tot; i++)
					for (int j = 0; i + j <= tot; j++)
						f[j] += g[i][j] * prp / (i + 1), f[j + i + 1] -= g[i][j] * prp / (i + 1);
			}

		for (int k = 1; k <= n; k++)
			f[k] += f[k - 1];
		for (int k = 0; k < n; k++)
			printf("%.8f ", f[k]);
		printf("\n");
	}

	return 0;
}