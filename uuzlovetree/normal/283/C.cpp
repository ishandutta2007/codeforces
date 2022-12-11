#include<bits/stdc++.h>
#define maxn 305
#define maxt 100005 
#define ll long long
using namespace std;
const ll mod = 1000000007;
int n,q,t;
int a[maxn];
int pre[maxn],vis[maxn];
bool h[maxn],hx[maxn];
ll dp[maxt],f[maxt];
int main()
{
	scanf("%d%d%d",&n,&q,&t);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)h[i]=1,hx[i]=1;
	for(int i=1;i<=q;++i)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		pre[b]=c;h[c]=0;hx[b]=0;
	}
	for(int i=1;i<=n;++i)if(h[i])
		for(int x=i;x;x=pre[x])a[pre[x]]+=a[x],vis[x]=1;
	for(int i=1;i<=n;++i)if(!vis[i])
	{
		puts("0");exit(0);
	}
	dp[0]=1;
	for(int i=1;i<=n;++i)
	{
		if(hx[i])
		{
			for(int j=a[i];j<=t;++j)dp[j]=(dp[j]+dp[j-a[i]])%mod;
		}
		else
		{
			memcpy(f,dp,sizeof(f));
			for(int j=a[i];j<=t;++j)dp[j]=(dp[j]+dp[j-a[i]])%mod;
			for(int j=0;j<=t;++j)dp[j]=(dp[j]-f[j]+mod)%mod;
		}
	}
	printf("%I64d\n",dp[t]);
	return 0;
}