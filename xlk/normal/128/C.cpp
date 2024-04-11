#include<stdio.h>
int n,m,s,p=1000000007,c[2020][2020];
int main()
{
	for(int i=0;i<2000;i++)
	{
		c[i][0]=1;
		for(int j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%1000000007;
	}
	scanf("%d %d %d",&n,&m,&s);
	printf("%I64d\n",1LL*c[n-1][2*s]*c[m-1][2*s]%1000000007);
	return 0;
}