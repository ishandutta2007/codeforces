#include<bits/stdc++.h>
using namespace std;
const int max_N=1e5+5;
int End[max_N<<1],Last[max_N<<1],Next[max_N<<1],e;
inline void add_edge(int x,int y)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e;
	End[++e]=x,Next[e]=Last[y],Last[y]=e;
}
bool vis[max_N<<1];
int V,E;
bool flag_self_loop;
void dfs(int x)
{
	vis[x]=true;
	++V;
	for(int i=Last[x];i;i=Next[i])
	{
		++E;
		int y=End[i];
		if(!vis[y])
			dfs(y);
		else if(x==y)
			flag_self_loop=true;
	}
}
int main()
{
	int N;
	scanf("%d",&N);
	for(int i=1;i<=N;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	const int mod=1e9+7;
	int ans=1;
	for(int i=1;i<=2*N;++i)
	{
		if(!vis[i])
		{
			V=E=0;
			flag_self_loop=false;
			dfs(i);
			E>>=1;
			assert(E==V-1||E==V);
			if(E==V-1)
				ans=1ll*ans*V%mod;
			else if(!flag_self_loop)
			{
				ans<<=1;
				ans-=ans>=mod?mod:0;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}