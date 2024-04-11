#include<stdio.h>
long long c[120][120];
long long f[120][120];
int a[20];
int z,n,p=1000000007;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<10;i++)
		scanf("%d",a+i);
	for(int i=0;i<=n;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%p;
	}
	f[10][0]=1;
	for(int i=9;i>0;i--)
	{
		for(int j=0;j<=n;j++)
			for(int k=a[i];k<=j;k++)
				f[i][j]=(f[i][j]+f[i+1][j-k]*c[j][k])%p;
	}
	for(int j=a[0];j<=n;j++)
		for(int k=a[0];k<j;k++)
			z=(z+f[1][j-k]*c[j-1][k])%p;
	printf("%d",z);
	return 0;
}