#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],e;
inline void add_edge(int x,int y)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e;
	End[++e]=x,Next[e]=Last[y],Last[y]=e;
}
int a[max_n],dp_in[max_n],dp_out[max_n];
void dfs1(int x,int fa)
{
	dp_in[x]=a[x];
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs1(y,x);
			dp_in[x]+=max(dp_in[y],0);
		}
	}
}
void dfs2(int x,int fa)
{
	dp_out[x]=a[x];
	if(fa)
		dp_out[x]+=max(dp_out[fa]+(dp_in[fa]-a[fa]-max(dp_in[x],0)),0);
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
			dfs2(y,x);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		if(!a[i])
			--a[i];
	}
	for(int i=1;i<=n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i)
		printf("%d%c",dp_in[i]+dp_out[i]-a[i],i<n?' ':'\n');
	return 0;
}