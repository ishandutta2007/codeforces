#include <stdio.h>
#define ll long long
const int N=100050;
ll dp[N],b[N],a[N],T[N],t,p,n,i;
ll Get(int u, int v){ return (dp[u]-dp[v]+b[v]-b[u]-1)/(b[v]-b[u]);}
int main()
{
	scanf("%lld",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<=n;i++) scanf("%lld",&b[i]);
	T[t++]=1;
	for(i=2;i<=n;i++)
	{
		while(t-p>1 && Get(T[p],T[p+1])<=a[i]) p++;
		dp[i]=a[i]*b[T[p]]+dp[T[p]];
		while(t-p>1 && Get(T[t-1],i)<=Get(T[t-1],T[t-2])) t--;
		T[t++]=i;
	}
	printf("%lld\n",dp[n]);
	return 0;
}