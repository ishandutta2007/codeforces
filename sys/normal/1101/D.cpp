#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n,head[Maxn],cnt,ct,fac[Maxn][8],ans,val[Maxn],dp[Maxn][8];
struct edg
{
	int nxt,to;
}edge[2*Maxn];
void add(int x,int y)
{
	edge[++cnt]=(edg){head[x],y};
	head[x]=cnt;
}
void dfs(int u,int fa)
{
	for(int i=1;i<=7;i++)
		dp[u][i]=1;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		int to=edge[i].to;
		if(to!=fa)
		{
			dfs(to,u);
			for(int i=1;i<=7;i++)
				if(fac[u][i])
					for(int j=1;j<=7;j++)
						if(fac[to][j]==fac[u][i])
						{
							ans=max(ans,dp[u][i]+dp[to][j]);
							dp[u][i]=max(dp[u][i],dp[to][j]+1);
						}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&val[i]);
		int maxi=sqrt(val[i]),tmp=val[i];
		ct=0;
		for(int j=2;j<=maxi;j++)
			if(tmp%j==0)
			{
				fac[i][++ct]=j;
				while(tmp%j==0) tmp/=j;
			}
		if(tmp!=1)
			fac[i][++ct]=tmp;
	}
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	dfs(1,0);
	bool tag=false;
	for(int i=1;i<=n;i++) if(val[i]!=1) tag=true;
	if(!ans&&tag) printf("1");
	else printf("%d",ans);
	return 0;
}