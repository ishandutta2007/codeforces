#include <iostream>
#include <cstdio>
#define maxn 1505
using namespace std;
int n, q, c[maxn][maxn], ans[maxn];
int up[maxn][maxn][12], L[maxn][maxn][12];
int x[maxn][maxn][12], y[maxn][maxn][12];
int cnt[maxn][maxn];
int t[maxn * maxn];
inline int get(int a, int b, int t)
{
	return max(a - x[a - 1][b - 1][t], b - y[a - 1][b - 1][t]);
}
void init()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			L[i][j][L[i][j][0] = 1] = j;
			for (int k = 1; k <= L[i][j - 1][0]; k++)
			{
				if(c[i][L[i][j - 1][k]] == c[i][j]) continue;
				L[i][j][++L[i][j][0]] = L[i][j - 1][k];
			}
			up[i][j][up[i][j][0] = 1] = i;
			for (int k = 1; k <= up[i - 1][j][0]; k++)
			{
				if(c[up[i - 1][j][k]][j] == c[i][j]) continue;
				up[i][j][++up[i][j][0]] = up[i - 1][j][k];
			}
			x[i][j][1] = i, y[i][j][1] = j;
			t[c[i][j]] = 1;
			
			int Lpos = 1, uppos = 1, pos = 1;
			cnt[i][j] = 11;
			for (int k = 2; k <= 11; k++)
			{
				if(Lpos > L[i][j - 1][0] && uppos > up[i - 1][j][0] && pos > cnt[i - 1][j - 1])
				{
					cnt[i][j] = k - 1;
					break;
				}
				int temp = n;
				if(Lpos <= L[i][j - 1][0]) temp = min(temp, j - L[i][j - 1][Lpos]);
				if(uppos <= up[i - 1][j][0]) temp = min(temp, i - up[i - 1][j][uppos]);
				if(pos <= cnt[i - 1][j - 1]) temp = min(temp, get(i, j, pos));
				if(Lpos <= L[i][j - 1][0] && temp == j - L[i][j - 1][Lpos])
				{
					x[i][j][k] = i;
					y[i][j][k] = L[i][j - 1][Lpos];
					Lpos++;
				}
				else if(uppos <= up[i - 1][j][0] && temp == i - up[i - 1][j][uppos]) 
				{
					x[i][j][k] = up[i - 1][j][uppos];
					y[i][j][k] = j;
					uppos++;
				}
				else
				{
					x[i][j][k] = x[i - 1][j - 1][pos];
					y[i][j][k] = y[i - 1][j - 1][pos];	
					pos++;
				}
				if(t[c[x[i][j][k]][y[i][j][k]]])
				{
					k--;
					continue;
				}
				t[c[x[i][j][k]][y[i][j][k]]] = 1;
			}
			for (int k = 1; k <= cnt[i][j]; k++)
			{
				t[c[x[i][j][k]][y[i][j][k]]] = 0;
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			scanf("%d", &c[i][j]);
		}
	}
	init();
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
//			printf("%d ", cnt[i][j]);
			int tmp = min(i, j);
			if (q < cnt[i][j]) tmp = min(tmp, max(i - x[i][j][q + 1], j - y[i][j][q + 1]));
			ans[tmp]++;
		}
//		printf("\n");
	}
	for (int i = n; i >= 1; i--)
	{
		ans[i] += ans[i + 1];
	}
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", ans[i]);
	}
	return 0;
}