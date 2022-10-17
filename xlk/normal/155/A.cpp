#include<stdio.h>
int n,i,j,z;
int a[1020];
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",a+i);	
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
			if(a[j]>=a[i])
				break;
		if(j==i)
			z++;
		for(j=0;j<i;j++)
			if(a[j]<=a[i])
				break;
		if(j==i)
			z++;
	}
	printf("%d",z);
	return 0;
}