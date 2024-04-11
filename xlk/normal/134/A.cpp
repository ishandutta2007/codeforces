#include<stdio.h>
int a[200020];
int s,n,z;
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i),s+=a[i];
	for(int i=0;i<n;i++)
		if(a[i]*n==s)
			z++;
	printf("%d\n",z);
	for(int i=0;i<n;i++)
		if(a[i]*n==s)
			printf("%d ",i+1);
	return 0;
}