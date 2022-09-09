#include <stdio.h>
const int N=105;
int sol;
int min(int a, int b){ return a>b?b:a;}
int a[N];
int main()
{
	int v1,v2,t,d,i;
	scanf("%i %i",&v1,&v2);
	scanf("%i %i",&t,&d);
	for(i=0;i<t;i++)
	{
		a[i]=v1+d*i;
	}
	for(i=0;i<t;i++)
	{
		a[t-1-i]=min(a[t-1-i],v2+d*i);
	}
	for(i=0;i<t;i++) sol+=a[i];
	printf("%i\n",sol);
	return 0;
}