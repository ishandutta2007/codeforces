#include <stdio.h>
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
const int N=100050;
int a[N],Min=1e9+1e8,Max;
int main()
{
	int n,i,sol=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),Max=max(Max,a[i]),Min=min(Min,a[i]);
	for(i=1;i<=n;i++) if(a[i]!=Min && a[i]!=Max) sol++;
	printf("%i\n",sol);
	return 0;
}