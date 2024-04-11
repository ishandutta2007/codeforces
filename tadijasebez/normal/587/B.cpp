#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int N=1000050;
int dp[2][N],c,p=1,a[N],id[N];
bool comp(int i, int j){ return a[i]<a[j];}
int main()
{
	ll l,sz;int n,i,j,t,k,ost;
	scanf("%i %lld %i",&n,&l,&k);
	sz=l/n;
	ost=l%n;
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id[i]=i;
	//printf("%lld %i\n",sz,ost);
	//if(sz<0) return printf("0\n"),0;
	sort(id+1,id+1+n,comp);
	for(j=1;j<=n;j++) dp[p][j]=1;
	int ans=0;
	ll sz1=sz;
	for(i=1;i<=n;i++)
	{
		if(ost>=id[i]) ans+=(ll)(sz1+1)%mod*dp[p][i]%mod;
		else ans+=(ll)sz1%mod*dp[p][i]%mod;
		if(ans>=mod) ans-=mod;
	}
	//printf("ans:%i\n",ans);
	for(i=2;i<=k;i++)
	{
		int sum=0;
		for(j=1;j<=n;j=t)
		{
			for(t=j;a[id[t]]==a[id[j]] && t<=n;t++)	sum=(sum+dp[p][t])%mod;
			for(t=j;a[id[t]]==a[id[j]] && t<=n;t++) dp[c][t]=sum;
		}
		//for(j=1;j<=n;j++) printf("%i:%i \n",a[id[j]],dp[c][j]);
		c^=1;p^=1;
		ll sz1=sz-i+1;
		//printf("sz1:%lld\n",sz1);
		if(sz1<0) break;
		for(j=1;j<=n;j++)
		{
			//printf("%i ",id[j]);
			if(ost>=id[j]) ans+=(ll)(sz1+1)%mod*dp[p][j]%mod;
			else ans+=(ll)sz1%mod*dp[p][j]%mod;
			if(ans>=mod) ans-=mod;
		}
		//printf("\n");
	}
	printf("%i\n",ans);
	return 0;
}