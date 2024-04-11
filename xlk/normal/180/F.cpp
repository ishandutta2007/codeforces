#include<stdio.h>
int n,a[100020],p[100020];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++)
		scanf("%d",p+a[i]-1);
	for(int i=0;i<n;i++)
		printf("%d ",p[i]);
	return 0;
}