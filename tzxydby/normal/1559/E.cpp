#include<bits/stdc++.h>
using namespace std;
const int N=100005,mx=100000,M=55,mod=998244353;
int fl[N],p[N],pr,mu[N],c,n,m,l[N],r[N],ans,dp[M][N],s[N];
int sol(int g)
{
	int k=m/g,t=0;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
			s[j]=(j?s[j-1]+dp[i-1][j]:dp[i-1][0])%mod;
		int al=(l[i]+g-1)/g,ar=r[i]/g;
		if(al>ar)
			return 0;
		for(int j=0;j<=k;j++)
			dp[i][j]=((j-al>=0?s[j-al]:0)+mod-(j-ar-1>=0?s[max(0,j-ar-1)]:0))%mod;
	}
	for(int j=0;j<=k;j++)
		t=(t+dp[n][j])%mod;
	return t;
}
int main()
{
	mu[1]=1;
	for(int i=2;i<=mx;i++)
	{
		if(!fl[i])
			p[++pr]=i,mu[i]=-1;
		for(int j=1;j<=pr&&i*p[j]<=mx;j++)
		{
			fl[i*p[j]]=1;
			if(i%p[j]==0)
			{
				mu[i*p[j]]=0;
				break;
			}
			mu[i*p[j]]=-mu[i];
		}
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	for(int i=1;i<=m;i++)
	{
		if(mu[i]==1)
			ans=(ans+sol(i))%mod;
		if(mu[i]==-1)
			ans=(ans+mod-sol(i))%mod;
	}
	printf("%d\n",ans);
	return 0;
}