#include<stdio.h>
#include<iostream>
using namespace std;
int n,m,k,i,j,p=1000000007;
long long z=1;
int f[2020];
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;	
}
void U(int x,int y)
{
	f[F(x)]=F(y);	
}
int main()
{
	scanf("%d %d %d",&n,&m,&k);
	for(i=1;i<=n;i++)
		f[i]=i;
	for(i=1;i<=n;i++)
		for(j=max(1,i-k+1);j<=min(i,n-k+1);j++)
			U(i,j+k-1-(i-j));
	for(i=1;i<=n;i++)
		if(f[i]==i)
			z=z*m%p;
	printf("%I64d",z);
	return 0;
}