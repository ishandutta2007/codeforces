#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<string>
using namespace std;
typedef long long LL;
const int V=2100;
struct Edge{int num,ne;}e[V*2];
int p[V],K;
void add(int x,int y)
{
	e[K].num=y;e[K].ne=p[x];p[x]=K++;
}
int is[V],dp[V];
void dfs(int u)
{
	for(int i=p[u];i!=-1;i=e[i].ne)
	{
		int v=e[i].num;
		dp[v]=dp[u]+1;
		dfs(v);
	}
}
int n,i,x,ans;
int main()
{
	while(~scanf("%d",&n))
	{
		for(i=1;i<=n;i++)p[i]=-1;K=0;
		for(i=1;i<=n;i++)is[i]=1;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x!=-1){add(x,i);is[i]=0;}
		}
		for(i=1;i<=n;i++)if(is[i]){dp[i]=0;dfs(i);}
		ans=0;
		for(i=1;i<=n;i++)ans=max(ans,dp[i]+1);
		printf("%d\n",ans);
	}
}