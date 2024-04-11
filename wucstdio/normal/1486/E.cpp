#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
	int to;
	int nxt;
	int len;
}e[21000005];
int n,m,edgenum,head[11000005],dis[11000005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void add(int u,int v,int l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void Dijkstra()
{
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	q.push(make_pair(0,0));
	while(!q.empty())
	{
		int d=q.top().first;
		int node=q.top().second;
		q.pop();
		if(dis[node]!=d)continue;
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(dis[to]>dis[node]+e[hd].len)
			{
				dis[to]=dis[node]+e[hd].len;
				q.push(make_pair(dis[to],to));
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		u--,v--;
		add(u*51,v*51+l,l*l);
		for(int i=1;i<=50;i++)add(u*51+i,v*51,(2*i+l)*l);
		swap(u,v);
		add(u*51,v*51+l,l*l);
		for(int i=1;i<=50;i++)add(u*51+i,v*51,(2*i+l)*l);
	}
	Dijkstra();
	for(int i=1;i<=n;i++)
	{
		if(dis[(i-1)*51]>1e9)printf("-1 ");
		else printf("%d ",dis[(i-1)*51]);
	}
	printf("\n");
	return 0;
}