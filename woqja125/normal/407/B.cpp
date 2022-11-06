#include<stdio.h>
int d[1001], a[1001];
int main()
{
	int n, i, j;
	int ans=0;
	scanf("%d", &n);
	for(i=1; i<=n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(i=1; i<=n; i++)
	{
		d[i] = 2;
		for(j = a[i]; j<i; j++)
		{
			(d[i] += d[j])%=1000000007;
		}
		(ans += d[i])%=1000000007;
	}
	printf("%d", ans);
	return 0;
}