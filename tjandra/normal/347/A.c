#include<stdio.h>
#include<stdlib.h>
int F(const void*a,const void*b){return *(int*)a-*(int*)b;}
int a[100];
int main()
{
	int t=0,T;
	for(scanf("%i",&T);t<T;scanf("%i",a+t++));
	qsort(a,t,sizeof(int),F);
	printf("%i",a[--T]);
	for(t=1;t<T;printf(" %i",a[t++]));
	printf(" %i\n",a[0]);
	return 0;
}