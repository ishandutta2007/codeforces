#include<bits/stdc++.h>
using namespace std;
int n,m;
const int max_n=2e5+5;
const int max_m=2e5+5;
int End[max_m<<1],Last[max_n],Next[max_m<<1],Len[max_m<<1],e;
inline void add_edge(int x,int y,int z)
{
	End[++e]=y;
	Next[e]=Last[x];
	Last[x]=e;
	Len[e]=z;
	End[++e]=x;
	Next[e]=Last[y];
	Last[y]=e;
	Len[e]=z;
}
typedef pair<long long,int> P;
priority_queue<P,vector<P>,greater<P> > q;
long long dis[max_n<<2];
void dijkstra()
{
	for(int i=1;i<=n;++i)
		for(int j=0;j<4;++j)
			dis[i<<2|j]=1e18;
	dis[4]=0;
	q.push(P(0,4));
	while(q.size())
	{
		long long d=q.top().first;
		int x=q.top().second;
		q.pop();
		if(dis[x]<d)
			continue;
		int u=x>>2,a=(x>>1)&1,b=x&1;
		for(int i=Last[u];i;i=Next[i])
		{
			int v=End[i],w=Len[i];
			int y=(v<<2)|(a<<1)|b;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push(P(dis[y],y));
			}
			if(a==0&&dis[y|2]>dis[x])
			{
				dis[y|2]=dis[x];
				q.push(P(dis[y|2],y|2));
			}
			if(b==0&&dis[y|1]>dis[x]+w*2)
			{
				dis[y|1]=dis[x]+w*2;
				q.push(P(dis[y|1],y|1));
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
	}
	dijkstra();
	for(int i=2;i<=n;++i)
		printf("%lld%c",min(dis[i<<2],dis[i<<2|3]),i<n?' ':'\n');
	return 0;
}