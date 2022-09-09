#include <stdio.h>
#define ll long long
const int N=5050;
const int M=250050;
const int inf=1e9;
const ll oo=9e18;
int max(int a, int b){ return a>b?a:b;}
ll max(ll a, ll b){ return a>b?a:b;}
int a[51][N],len[51],pref[51],suff[51],dp[51][N],best[51],all[51];
int ids[M];
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&len[i]);
		int sum=0;
		pref[i]=-inf;
		suff[i]=-inf;
		best[i]=-inf;
		for(j=1;j<=len[i];j++)
		{
			scanf("%i",&a[i][j]);
			all[i]+=a[i][j];
			dp[i][j]=max(dp[i][j-1],0)+a[i][j];
			best[i]=max(best[i],dp[i][j]);
			sum+=a[i][j];
			pref[i]=max(pref[i],sum);
		}
		sum=0;
		for(j=len[i];j;j--)
		{
			sum+=a[i][j];
			suff[i]=max(suff[i],sum);
		}
	}
	ll sol=-oo;
	for(i=1;i<=m;i++) scanf("%i",&ids[i]),sol=max(sol,(ll)best[ids[i]]);
	ll cur=0;
	for(i=1;i<=m;i++)
	{
		sol=max(sol,cur+pref[ids[i]]);
		cur=max(cur+all[ids[i]],(ll)suff[ids[i]]);
	}
	printf("%lld\n",sol);
	return 0;
}