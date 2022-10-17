#include<stdio.h>
int n,d,a[2020];
long long z;
int main()
{
	scanf("%d %d",&n,&d);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		if(a[i-1]>=a[i])
		{
			z+=(a[i-1]-a[i])/d+1;
			a[i]+=(a[i-1]-a[i])/d*d+d;
		}
	}	
	printf("%I64d\n",z);
	return 0;
}