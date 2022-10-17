#include<stdio.h>
int n;
void P(int x)
{
	for(int i=x;i<n;i++)
		printf("  ");
	for(int i=0;i<x;i++)
		printf("%d ",i);
	for(int i=x;~i;i--)
		printf("%d%c",i,i?' ':'\n');
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		P(i);
	for(int i=n;~i;i--)
		P(i);
	return 0;
}