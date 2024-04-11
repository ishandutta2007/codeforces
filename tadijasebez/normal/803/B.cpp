#include <stdio.h>
#define INFINITY 5000000;
int a[200005],d1[200005],d2[200005];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	d1[0]=INFINITY;
	for(i=1;i<=n;i++)
	{
		if(a[i]==0) d1[i]=0;
		else d1[i]=d1[i-1]+1;
	}
	d2[n+1]=INFINITY;
	for(i=n;i>0;i--)
	{
		if(a[i]==0) d2[i]=0;
		else d2[i]=d2[i+1]+1;
	}
	for(i=1;i<=n;i++)
	{
		if(d1[i]<d2[i]) printf("%i ",d1[i]);
		else printf("%i ",d2[i]);
	}
	return 0;
}