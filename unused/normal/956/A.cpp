#include <bits/stdc++.h>
using namespace std;

char dat[55][55];

int par[105];
int gp(int t)
{
	return par[t] == t ? t : par[t] = gp(par[t]);
}
void mg(int a, int b)
{
	par[gp(a)] = gp(b);
}

int main()
{
	int n, m;
	scanf("%d%d",&n,&m);
	for (int i = 0; i < n; i++) scanf("%s",dat[i]);
	iota(par, par + n + m, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dat[i][j] == '#') mg(i, j + n);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (dat[i][j] == '.' && gp(i) == gp(j + n))
			{
				printf("No\n");
				return 0;
			}
		}
	}
	printf("Yes\n");
}