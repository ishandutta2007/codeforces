#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+5;
const int max_m=1e5+5;
int End[max_m],Last[max_n],Next[max_m],E;
inline void add_edge(int x,int y)
{
	End[++E]=y;
	Next[E]=Last[x];
	Last[x]=E;
}
int dfn[max_n],low[max_n],Time,st[max_n],tp;
bool mark[max_n];
int bel[max_n],tot;
bool cycle[max_n];
void tarjan(int x)
{
	dfn[x]=low[x]=++Time;
	st[++tp]=x;
	mark[x]=true;
	for(int i=Last[x];i;i=Next[i])
	{
		int y=End[i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(mark[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		++tot;
		if(st[tp]!=x)
			cycle[tot]=true;
		while(mark[x])
		{
			bel[st[tp]]=tot;
			mark[st[tp--]]=false;
		}
	}
}
int fa[max_n],sz[max_n];
int get_fa(int x)
{
	return fa[x]!=x?fa[x]=get_fa(fa[x]):x;
}
inline void merge(int x,int y)
{
	x=get_fa(x),y=get_fa(y);
	if(x!=y)
	{
		if(sz[x]>sz[y])
			swap(x,y);
		fa[x]=y;
		cycle[y]|=cycle[x];
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add_edge(a,b);
	}
	for(int i=1;i<=n;++i)
	{
		if(!dfn[i])
			tarjan(i);
	}
	for(int i=1;i<=tot;++i)
		fa[i]=i,sz[i]=1;
	for(int x=1;x<=n;++x)
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i];
			if(bel[x]!=bel[y])
				merge(bel[x],bel[y]);
		}
	int ans=n;
	for(int i=1;i<=tot;++i)
		ans-=get_fa(i)==i&&!cycle[i];
	printf("%d\n",ans);
	return 0;
}