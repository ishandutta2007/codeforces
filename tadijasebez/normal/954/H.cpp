#include <stdio.h>
#define ll long long
const int mod=1e9+7;
const int N=5050;
int pow(int x, int k)
{
	int ret=1;
	for(;k;k>>=1,x=(ll)x*x%mod) if(k&1) ret=(ll)ret*x%mod;
	return ret;
}
int inv(int x){ return pow(x,mod-2);}
int a[N],sz[N],isz[N],dp[N][N*2],sol[N*2],n;
bool vis[N][N*2];
int DP(int h, int k)
{
	if(h==0) return dp[k][h]=1;
	if(k==1) return dp[k][h]=0;
	if(vis[k][h]) return dp[k][h];
	vis[k][h]=1;
	dp[k][h]=DP(h-1,k-1);
	if(h>1 && k+h-2<=n) dp[k][h]+=(ll)sz[k+h-2]*isz[k]%mod*(a[k-1]-1)%mod;
	if(dp[k][h]>=mod) dp[k][h]-=mod;
	return dp[k][h];
}
int main()
{
	int i,j;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i",&a[i]);
	sz[1]=1;for(i=2;i<=n;i++) sz[i]=(ll)sz[i-1]*a[i-1]%mod,isz[i]=inv(sz[i]);
	for(i=1;i<=n;i++)
	{
		int s=1;
		for(j=i+1;j<=n;j++)
		{
			s=(ll)s*a[j-1]%mod;
			sol[j-i]+=(ll)s*sz[i]%mod;
			if(sol[j-i]>=mod) sol[j-i]-=mod;
		}
	}
	for(i=1;i<2*n-1;i++)
	{
		for(j=1;j<=n;j++)
		{
			sol[i]+=(ll)DP(i,j)*sz[j]%mod;
			if(sol[i]>=mod) sol[i]-=mod;
		}
		sol[i]=(ll)sol[i]*inv(2)%mod;
		printf("%i ",sol[i]);
	}
	printf("\n");
	return 0;
}