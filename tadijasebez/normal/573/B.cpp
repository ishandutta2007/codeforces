#include <stdio.h>
const int N=100050;
int ans[N],x[N];
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&x[i]);
	int naj=0;
	for(i=1;i<=n;i++)
	{
		naj=min(naj,x[i]-i);
		ans[i]=i+naj;
	}
	naj=n+1;
	for(i=n;i;i--)
	{
		naj=min(naj,x[i]+i);
		ans[i]=min(ans[i],naj-i);
	}
	int sol=0;
	for(i=1;i<=n;i++) sol=max(sol,ans[i]);
	printf("%i\n",sol);
	return 0;
}