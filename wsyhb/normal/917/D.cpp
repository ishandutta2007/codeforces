#include<bits/stdc++.h>
using namespace std;
const int max_n=100+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],e;
inline void add_edge(int x,int y)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e;
	End[++e]=x,Next[e]=Last[y],Last[y]=e;
}
const int mod=1e9+7;
int sz[max_n],dp[max_n][max_n][2],f[max_n][2];
inline int get_sum(int a,int b)
{
	return a+b-(a+b>=mod?mod:0);
}
void dfs(int x,int fa)
{
	dp[x][1][0]=dp[x][1][1]=1,sz[x]=1;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs(y,x);
			for(int j=1;j<=sz[x];++j)
				for(int k=1;k<=sz[y];++k)
				{
					f[j+k][0]=(f[j+k][0]+1ll*dp[x][j][0]*dp[y][k][1])%mod;
					f[j+k][1]=(f[j+k][1]+1ll*dp[x][j][1]*dp[y][k][1])%mod;
					f[j+k-1][0]=(f[j+k-1][0]+1ll*dp[x][j][0]*dp[y][k][0])%mod;
					f[j+k-1][1]=(f[j+k-1][1]+1ll*dp[x][j][1]*dp[y][k][0]+1ll*dp[x][j][0]*dp[y][k][1])%mod;
				}
			sz[x]+=sz[y];
			for(int j=1;j<=sz[x];++j)
				for(int k=0;k<=1;++k)
				{
					dp[x][j][k]=f[j][k];
					f[j][k]=0;
				}
		}
	}
}
int C[max_n][max_n],power[max_n];
inline void init(int n)
{
	for(int i=0;i<=n;++i)
		for(int j=0;j<=i;++j)
			C[i][j]=(j==0||j==i?1:get_sum(C[i-1][j-1],C[i-1][j]));
	power[0]=1;
	for(int i=1;i<=n;++i)
		power[i]=1ll*power[i-1]*n%mod;
}
int F[max_n],G[max_n];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	dfs(1,0);
	init(n);
	for(int i=0;i<=n-1;++i)
		F[i]=n-i==1?1:1ll*dp[1][n-i][1]*power[n-i-2]%mod;
	for(int i=0;i<=n-1;++i)
	{
		for(int j=i;j<=n-1;++j)
		{
			if((j^i)&1)
				G[i]=get_sum(G[i]-1ll*C[j][i]*F[j]%mod,mod);
			else
				G[i]=(G[i]+1ll*C[j][i]*F[j])%mod;
		}
		printf("%d%c",G[i],i<n-1?' ':'\n');
	}
	return 0;
}