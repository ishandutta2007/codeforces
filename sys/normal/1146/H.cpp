#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;
int n, ct, x[Maxn], y[Maxn], ord[Maxn];
long long ans, f[5][Maxn][Maxn];
long long cross(int a, int b, int c)
{
	return (x[a] - x[b]) * (long long) (y[b] - y[c]) - (x[b] - x[c]) * (long long) (y[a] - y[b]);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &x[i], &y[i]);
	for (int i = 1; i <= n; i++)
	{
		ct = 0;
		for (int c = 2; c <= 4; c++)
			for (int j = 1; j <= n; j++)
				for (int k = 1; k < j; k++)
					f[c][j][k] = 0;
		for (int j = 1; j <= n; j++)
			if (make_pair(y[j], x[j]) > make_pair(y[i], x[i])) ord[++ct] = j;
		sort(ord + 1, ord + 1 + ct, [&](int a, int b){return atan2(y[a] - y[i], x[a] - x[i]) < atan2(y[b] - y[i], x[b] - x[i]);});
		for (int j = 1; j <= ct; j++)
			f[1][j][0] = 1;
		for (int c = 2; c <= 4; c++)
			for (int j = 1; j <= ct; j++)
				for (int k = (c != 2); k < j; k++)
					if (f[c - 1][j][k])
						for (int q = j + 1; q <= ct; q++)
							if (cross(c == 2 ? i : ord[k], ord[j], ord[q]) > 0)
								f[c][q][j] += f[c - 1][j][k];
		for (int j = 1; j <= ct; j++)
			for (int k = 1; k < j; k++)
				if (cross(ord[k], ord[j], i) > 0) ans += f[4][j][k];
	}
	printf("%lld", ans);
	return 0;
}