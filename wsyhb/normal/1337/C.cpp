#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],e;
inline void add_edge(int x,int y)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	End[++e]=x;
	Next[e]=Last[y];
	Last[y]=e;
}
int dep[max_n],sz[max_n],val[max_n];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	sz[x]=1;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
		{
			dfs(y,x);
			sz[x]+=sz[y];
		}
	}
	val[x]=dep[x]-sz[x];
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	dfs(1,0);
	nth_element(val+1,val+(k+1),val+n+1,greater<int>());
	long long ans=0;
	for(int i=1;i<=k;++i)
		ans+=val[i];
	printf("%lld\n",ans); 
	return 0;
}