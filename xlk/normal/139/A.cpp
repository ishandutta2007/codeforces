#include<stdio.h>
int z,n,a[10];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<7;i++)
		scanf("%d",a+i);
	for(;n>a[z%7];)
		n-=a[z++%7];
	printf("%d",z%7+1);
	return 0;
}