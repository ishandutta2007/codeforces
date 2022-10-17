#include<stdio.h>
int n,v[10],z;
int F(int x)
{
	for(;x;x/=10)
		if(v[x%10])
			return 1;
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=n;i;i/=10)
		v[i%10]=1;
	for(int i=1;i*i<=n;i++)
		if(n%i==0)
			z+=F(i)+(i*i<n&&F(n/i));
	printf("%d",z);
	return 0;
}