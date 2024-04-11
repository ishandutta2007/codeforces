#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 52, MOD = 1000000007, REV2 = 500000004;
int n, d[MAXN], fac[MAXN], powrev2[MAXN];
int f[2][MAXN][MAXN][MAXN];//f[i&1][k][j1][j2]
inline void add(int &x, long long y)
{
	x = (x + y) % MOD;
}
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &d[i]);
	fac[0] = 1;
	for(int i = 1; i <= n; i++)
		fac[i] = (long long)fac[i - 1] * i % MOD;
	powrev2[0] = 1;
	for(int i = 1; i <= n; i++)
		powrev2[i] = (long long)powrev2[i - 1] * REV2 % MOD;
	memset(f, 0, sizeof(f));
	//link 1--2
	f[0][d[1] - 1][(d[2] == 2)][(d[2] == 3)] = 1;
	for(int i = 3; i <= n; i++)
	{
		memset(f[i & 1], 0, sizeof(f[i & 1]));
		long long tmp;
		for(int j1 = 0; j1 <= i - 2; j1++)
			for(int j2 = !j1; j1 + j2 <= i - 2; j2++)
				if((tmp = f[~i & 1][0][j1][j2]) && j1 + j2 * 2 <= n - i + 1)
					add(f[i & 1][j1 + j2 * 2 - 1][(d[i] == 2)][(d[i] == 3)], tmp * fac[j1 + j2 * 2] % MOD * powrev2[j2]);
		for(int k = 1; k <= n - i + 1; k++)
			for(int j1 = 0; j1 <= i - 2; j1++)
				for(int j2 = 0; j1 + j2 <= i - 2; j2++)
					if((tmp = f[~i & 1][k][j1][j2]))
					{
						add(f[i & 1][k - 1][j1 + (d[i] == 2)][j2 + (d[i] == 3)], tmp);
						if(j1)
							add(f[i & 1][k - 1][j1 - 1 + (d[i] == 3)][j2], tmp * j1);
						if(j2)
							add(f[i & 1][k - 1][j1 + 1 + (d[i] == 3)][j2 - 1], tmp * j2);
						if(d[i] == 3)
						{
							if(j1 >= 2)
								add(f[i & 1][k - 1][j1 - 2][j2], tmp * (j1 * (j1 - 1) / 2));
							if(j1 && j2)
								add(f[i & 1][k - 1][j1][j2 - 1], tmp * j1 * j2);
							if(j2 >= 2)
								add(f[i & 1][k - 1][j1 + 2][j2 - 2], tmp * (j2 * (j2 - 1) / 2));
						}
					}
	}
	printf("%d\n", f[n & 1][0][0][0]);
	return 0;
}