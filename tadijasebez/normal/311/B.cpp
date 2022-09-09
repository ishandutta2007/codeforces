#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
const int N=100050;
const ll inf=1e18;
int min(int a, int b){ return a>b?b:a;}
ll pr[N],dp[N];
int val[N],dist[N];
ll x[N];
ll Get(int l, int r){ return (ll)(r-l+1)*val[r]-x[r]+x[l-1];}
void Solve(int l, int r, int L, int R)
{
	if(l>r) return;
	int mid=l+r>>1;
	int taj=0;
	dp[mid]=inf;
	ll sum;
	for(int i=min(mid,R);i>=L;i--)
	{
		sum=Get(i,mid);
		if(dp[mid]>=pr[i-1]+sum)
		{
			dp[mid]=pr[i-1]+sum;
			taj=i;
		}
	}
	Solve(l,mid-1,L,taj);
	Solve(mid+1,r,taj,R);
}
int main()
{
	int n,m,p,i,t;
	scanf("%i %i %i",&n,&m,&p);
	for(i=2;i<=n;i++) scanf("%i",&dist[i]),dist[i]+=dist[i-1];
	for(i=1;i<=m;i++) scanf("%i %i",&t,&val[i]),val[i]-=dist[t];
	sort(val+1,val+1+m);
	for(i=1;i<=m;i++) x[i]=x[i-1]+val[i];
	for(i=1;i<=m;i++) pr[i]=inf;
	while(p--)
	{
		Solve(1,m,1,m);
		for(i=1;i<=m;i++) pr[i]=dp[i];
	}
	printf("%lld\n",dp[m]);
	return 0;
}