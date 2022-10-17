#include<stdio.h>
int x,m,d[1000020];
long long z,n;
int main()
{
	scanf("%I64d %d",&n,&m);
	for(int i=0;i<2*m;i++)
		scanf("%d",&x),d[x]++;
	z=n*(n-1)*(n-2)/3;
	for(int i=1;i<=n;i++)
		z-=d[i]*(n-d[i]-1);
	printf("%I64d",z/2);
}