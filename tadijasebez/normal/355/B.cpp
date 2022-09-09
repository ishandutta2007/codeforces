#include <stdio.h>
const int N=100050;
int a[N],b[N];
int cost1,cost2;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,m,c1,c2,c3,c4,i;
	scanf("%i %i %i %i",&c1,&c2,&c3,&c4);
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		cost1+=min(c1*a[i],c2);
	}
	cost1=min(cost1,c3);
	for(i=1;i<=m;i++)
	{
		scanf("%i",&b[i]);
		cost2+=min(c1*b[i],c2);
	}
	cost2=min(cost2,c3);
	printf("%i\n",min(cost1+cost2,c4));
	return 0;
}