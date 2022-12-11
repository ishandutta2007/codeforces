#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],deg[max_n],E;
inline void add_edge(int x,int y)
{
	End[++E]=y,Next[E]=Last[x],Last[x]=E,++deg[x];
	End[++E]=x,Next[E]=Last[y],Last[y]=E,++deg[y];
}
int dep[max_n];
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(y!=fa)
			dfs(y,x);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
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
		for(int i=1;i<=n;++i)
			printf("%d%c",dep[i]&1?-deg[i]:deg[i],i<n?' ':'\n');
		E=0;
		for(int i=1;i<=n;++i)
			Last[i]=deg[i]=0;
	}
	return 0;
}