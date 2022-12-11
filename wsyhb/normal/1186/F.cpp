#include<bits/stdc++.h>
using namespace std;
const int max_n=1e6+5;
const int max_e=2e6+5;
int End[max_e<<1],Last[max_n],Next[max_e<<1],deg[max_n],cur[max_n],e=1;
bool mark[max_e<<1];
inline void add_edge(int x,int y)
{
	End[++e]=y,Next[e]=Last[x],Last[x]=e,++deg[x];
	End[++e]=x,Next[e]=Last[y],Last[y]=e,++deg[y];
}
int st[max_e],tp;
bool vis[max_n];
inline void Hierholzer(int x)
{
	vis[x]=true;
	for(int &i=cur[x];i;i=Next[i])
	{
		if(!mark[i])
		{
			mark[i]=mark[i^1]=true;
			Hierholzer(End[i]);
		}
	}
	st[++tp]=x;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
	}
	for(int i=1;i<=n;++i)
	{
		if(deg[i]&1)
			add_edge(0,i);
	}
	for(int i=0;i<=n;++i)
		cur[i]=Last[i];
	typedef pair<int,int> P;
	vector<P> edge;
	for(int i=0;i<=n;++i)
	{
		if(vis[i])
			continue;
		tp=0;
		Hierholzer(i);
		assert(st[1]==i);
		assert(st[tp]==i);
		for(int i=1;i<=tp-1;++i)
		{
			if(st[i])
			{
				if(st[i+1])
				{
					edge.push_back(P(st[i],st[i+1]));
					++i; 
				}
				else if(i>1)
					edge.push_back(P(st[i],st[i-1]));
			}
		}
	}
	printf("%d\n",(int)edge.size());
	for(int i=0;i<int(edge.size());++i)
		printf("%d %d\n",edge[i].first,edge[i].second);
	return 0;
}