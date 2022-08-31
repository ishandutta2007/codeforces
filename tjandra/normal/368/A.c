#include<stdio.h>
#include<stdlib.h>
int l[101];
int F(const void*x,const void*y){return*(int*)x-*(int*)y;}
int main()
{
	int n,d,i,j,k;
	scanf("%i%i",&n,&d);
	for(i=0;i<n;)scanf("%i",l+i++);
	qsort(l,n,sizeof(int),F);
	scanf("%i",&i);
	for(j=0,k=-((i>n?i-n:0)*d),i=(i>n)?n:i;j<i;j++)k+=l[j];
	printf("%i\n",k);
	return 0;
}