#include<stdio.h>
int sum[102][100011];
int a[100011];
int C[200011][102];
const int MOD=1000000007;
int main()
{
	int n, i, m, l, r, k, j;
	int s = 0;
	scanf("%d%d", &n, &m);
	C[0][0] = 1;
	for(i=1; i<=200000; i++)
	{
		C[i][0] = 1;
		for(j=1; j<=101; j++)
		{
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%MOD;
		}
	}
	for(i=1; i<=n; i++)scanf("%d", &a[i]);
	for(i=1; i<=m; i++)
	{
		scanf("%d%d%d", &l, &r, &k);
		(sum[k+1][l] += 1)%=MOD;
		for(j=k+1; j>0; j--) (sum[j][r+1] -= C[r-l + k+1-j][k+1-j])%=MOD;
	}
	for(k=101; k>0; k--)
	{
		s = 0;
		for(i=1; i<=n; i++)
		{
			(s += sum[k][i])%=MOD;
			sum[k-1][i] += s;
			sum[k-1][i] %= MOD;
		}
	}
	for(i=1; i<=n; i++)
	{
		sum[0][i]+=MOD;
		sum[0][i]%=MOD;
		printf("%d ", (sum[0][i]+a[i])%MOD);
	}
	return 0;
}