#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 33;
const int K = 210;
double dp[K][N][N];
int n, k;
int a[N];
double ans;

int getNewPos(int l, int r, int x)
{
	if (x < l) return x;
	if (x > r) return x;
	return l + r - x;
}

void calcDP()
{
	double nn = n * (n + 1) / 2.;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j) dp[0][i][j] = 1.;
	for (int it = 1; it <= k; it++)
		for (int x = 0; x < n; x++)
			for (int y = 0; y < n; y++)
			{
				if (x == y) continue;
				dp[it][x][y] = 0.;
				for (int l = 0; l < n; l++)
					for (int r = l; r < n; r++)
					{
						int nx = getNewPos(l, r, x);
						int ny = getNewPos(l, r, y);
						if (l <= min(x, y) && max(x, y) <= r)
							dp[it][x][y] += (1. - dp[it - 1][nx][ny]) / nn;
						else
							dp[it][x][y] += dp[it - 1][nx][ny] / nn;
					}
			}

/*	for (int it = 0; it <= k; it++)
	{
		for (int x = 0; x < n; x++)
		{
			for (int y = 0; y < n; y++)
				printf("%.5lf ", dp[it][x][y]);
			printf("\n");
		}
		printf("----------------\n");
	}*/
	return;
}

int main()
{
	scanf("%d%d", &n, &k);
	calcDP();
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] < a[j])
				ans += 1. - dp[k][i][j];
			else
				ans += dp[k][i][j];
		}
	printf("%.10lf\n", ans);

	return 0;
}