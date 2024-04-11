#include <stdio.h>
const int N=550;
#define ll long long
int x[N],dp[N];
int main()
{
	int n,i,j,k,l;
	ll p;
	scanf("%i %lld",&n,&p);
	if(n+5<p) l=n+5;
	for(i=0;i<n;i++) scanf("%i",&x[i]);
	while(l--)
	{
		if(x[1]>x[0])
		{
			dp[x[1]]=1;
			int tmp=x[0];
			for(i=1;i<n;i++) x[i-1]=x[i];
			x[n-1]=tmp;
		}
		else
		{
			dp[x[0]]++;
			int tmp=x[1];
			for(i=2;i<n;i++) x[i-1]=x[i];
			x[n-1]=tmp;
		}
		if(dp[x[0]]==p) return printf("%i\n",x[0]),0;
	}
	printf("%i\n",x[0]);
	return 0;
}