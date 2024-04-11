#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int T,n,m,a[maxn];
const int mod = 1000000007;
int mx[22][maxn],mxid[22][maxn],Log2[maxn];
int querymxid(int l,int r)
{
	int k=Log2[r-l+1];
	if(mx[k][l]>=mx[k][r-(1<<k)+1])return mxid[k][l];
	else return mxid[k][r-(1<<k)+1];
}
int lc[maxn],rc[maxn],rt;
int build(int l,int r)
{
	int u=querymxid(l,r);
	if(u!=l)lc[u]=build(l,u-1);
	if(u!=r)rc[u]=build(u+1,r);
	return u;
}
int dp[2000005],sp[2000005],vis[2000005];
int ID(int u,int x){return (u-1)*(m+1)+x;}
void solve(int u)
{
	if(!lc[u]&&!rc[u])
	{
		for(int x=1;x<=m;++x)dp[ID(u,x)]=1,sp[ID(u,x)]=x;
	}
	else if(!lc[u])
	{
		solve(rc[u]);
		for(int x=1;x<=m;++x)dp[ID(u,x)]=sp[ID(rc[u],x)];
		for(int x=1;x<=m;++x)sp[ID(u,x)]=(sp[ID(u,x-1)]+dp[ID(u,x)])%mod;
	}
	else if(!rc[u])
	{
		solve(lc[u]);
		for(int x=1;x<=m;++x)dp[ID(u,x)]=sp[ID(lc[u],x-1)];
		for(int x=1;x<=m;++x)sp[ID(u,x)]=(sp[ID(u,x-1)]+dp[ID(u,x)])%mod;
	}
	else
	{
		solve(lc[u]);solve(rc[u]);
		for(int x=1;x<=m;++x)dp[ID(u,x)]=1ll*sp[ID(lc[u],x-1)]*sp[ID(rc[u],x)]%mod;
		for(int x=1;x<=m;++x)sp[ID(u,x)]=(sp[ID(u,x-1)]+dp[ID(u,x)])%mod;
	}
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)lc[i]=rc[i]=0;
		for(int i=0;i<=n*m;++i)vis[i]=0,dp[i]=0,sp[i]=0;
		for(int i=1;i<=n;++i)mx[0][i]=a[i],mxid[0][i]=i,Log2[i]=log2(i);
		for(int j=1;j<=20;++j)
			for(int i=1;i+(1<<j)-1<=n;++i)
			{
				if(mx[j-1][i]>=mx[j-1][i+(1<<(j-1))])mx[j][i]=mx[j-1][i],mxid[j][i]=mxid[j-1][i];
				else mx[j][i]=mx[j-1][i+(1<<(j-1))],mxid[j][i]=mxid[j-1][i+(1<<(j-1))];
			}
		rt=build(1,n);
		solve(rt);
		printf("%d\n",sp[ID(rt,m)]);
	}
}