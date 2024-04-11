#include<stdio.h>
long long C(int n,int m)
{
	long long z=1;
	for(int i=0;i<m;i++)
		z=z*(n-i)/(i+1);
	return z;
}
int n,m,p;
int main()
{
	scanf("%d %d %d",&n,&m,&p);
	printf("%I64d",C(n+m,p)-C(n,p)-C(m,p)-C(n,1)*C(m,p-1)-C(n,2)*C(m,p-2)-C(n,3)*C(m,p-3));
	return 0;
}