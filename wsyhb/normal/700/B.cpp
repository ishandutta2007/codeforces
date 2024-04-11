#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],e;
inline void add_edge(int x,int y)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e;
	End[++e]=x,Next[e]=Last[y],Last[y]=e;
}
int sum[max_n];
void dfs(int x,int fa)
{
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs(y,x);
			sum[x]+=sum[y];
		}
	}
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=2*k;++i)
	{
		int u;
		scanf("%d",&u);
		sum[u]=1;
	}
	for(int i=1;i<=n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v); 
	}
	dfs(1,0);
	long long ans=0;
	for(int i=1;i<=n;++i)
		ans+=sum[i]<=k?sum[i]:2*k-sum[i];
	printf("%lld\n",ans);
	return 0;
}