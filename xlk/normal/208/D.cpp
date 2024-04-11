#include<stdio.h>
int p[60],n,a[6];
long long z[6],r;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",p+i);
	for(int i=0;i<5;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++)
	{
		r+=p[i];
		for(int i=4;i>=0;i--)
			z[i]+=r/a[i],r%=a[i];
	}
	for(int i=0;i<5;i++)
		printf("%I64d ",z[i]);
	printf("\n%I64d",r);
	return 0;
}