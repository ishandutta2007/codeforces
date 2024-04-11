#include<stdio.h>
int a[51][51];
int ans[51];
int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for(i=1; i<=n; i++)for(j=1; j<=n; j++)scanf("%d", &a[i][j]);
	for(i=1; i<=n; i++)
	{
		for(j=1; j<=n; j++)
		{
			if(ans[j] != 0) continue;
			int x = -1;
			for(k=1; k<=n; k++)
			{
				if(k==j || ans[k] != 0) continue;
				if(a[j][k] != i) break;
			}
			if(k==n+1)
			{
				ans[j] = i;
				break;
			}
		}
	}
	for(i=1; i<=n; i++)printf("%d ", ans[i]);
	return 0;
}