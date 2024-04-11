#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
const int max_m=2e5+5;
int End[max_m],Last[max_n],Next[max_m],deg_in[max_n],E;
inline void add_edge(int x,int y)
{
	End[++E]=y;
	Next[E]=Last[x];
	Last[x]=E;
	++deg_in[y];
}
int dis[max_n];
bool vis[max_n];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(v,u);
	}
	for(int i=1;i<=n-1;++i)
		dis[i]=1e9;
	typedef pair<int,int> P;
	priority_queue<P,vector<P>,greater<P> > q;
	q.push(P(0,n));
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x])
			continue;
		vis[x]=true;
		for(int i=Last[x];i;i=Next[i])
		{
			int y=End[i],d_now=dis[x]+(deg_in[y]--);
			if(d_now<dis[y])
			{
				dis[y]=d_now;
				q.push(P(dis[y],y));
			}
		}
	}
	printf("%d\n",dis[1]);
	return 0;
}