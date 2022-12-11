#include<bits/stdc++.h>
using namespace std;
int F[27]={1,1};
inline void init()
{
	for(int i=2;i<=26;++i)
		F[i]=F[i-1]+F[i-2];
}
inline int Find(int x)
{
	int k=lower_bound(F,F+26+1,x)-F;
	if(k>26||F[k]!=x)
		return -1;
	return k;
}
const int max_n=2e5+5;
int End[max_n<<1],Last[max_n],Next[max_n<<1],e=1;
inline void add_edge(int x,int y)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e;
	End[++e]=x,Next[e]=Last[y],Last[y]=e;
}
bool mark_del[max_n<<1],vis[max_n];
vector<int> id;
int sz[max_n],edge_fa[max_n];
void dfs(int x,int fa)
{
	vis[x]=true;
	id.push_back(x);
	sz[x]=1;
	for(int i=Last[x];i;i=Next[i])
	{
		if(mark_del[i])
			continue;
		int y=End[i];
		if(y!=fa)
		{
			edge_fa[y]=i;
			dfs(y,x);
			sz[x]+=sz[y];
		}
	}
} 
int main()
{
	init();
	int n;
	scanf("%d",&n);
	if(Find(n)==-1)
	{
		puts("NO");
		return 0;
	}
	for(int i=1;i<=n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	for(int t=1;t<=25;++t)
	{
		for(int i=1;i<=n;++i)
			vis[i]=false;
		for(int i=1;i<=n;++i)
		{
			if(!vis[i])
			{
				id.clear();
				dfs(i,0);
				for(int j=0;j<int(id.size());++j)
				{
					int x=id[j];
					if(Find(sz[x])!=-1&&Find(sz[i]-sz[x])!=-1)
					{
						mark_del[edge_fa[x]]=mark_del[edge_fa[x]^1]=true;
						break;
					}
				}
			}
		}
	}
	bool flag=true;
	for(int i=2;i<=e;++i)
	{
		if(!mark_del[i])
		{
			flag=false;
			break;
		}
	}
	puts(flag?"YES":"NO");
    return 0;
}