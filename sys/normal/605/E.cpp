#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;
int n, p[Maxn][Maxn];
double E[Maxn], P[Maxn];
bool vis[Maxn];
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &p[i][j]);
	for (int i = 1; i < n; i++)
		E[i] = 1, P[i] = 1 - p[i][n] / 100.0;
	int now = n;
	vis[n] = true;
	for (int i = 1; i <= n; i++)
	{
		double mini = 0x3f3f3f3f3f3f3f3fLL;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && E[j] / (1 - P[j]) < mini) mini = E[j] / (1 - P[j]), now = j;
		vis[now] = true;
		if (now == 1)
		{
			printf("%.12lf", E[1] / (1 - P[1]));
			return 0;
		}
		for (int j = 1; j <= n; j++)
			E[j] += (E[now] / (1 - P[now])) * p[j][now] / 100.0 * P[j], P[j] *= 1 - (p[j][now] / 100.0);
	}
	return 0;
}