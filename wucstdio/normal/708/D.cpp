#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int INF=2147483647;
struct Edge
{
	int to;
	int nxt;
	int flow;
	int cost;
}e[200005];
int n,m,s,t,edgenum=1,head[100005],dis[100005],a[100005],d[100005],pre[100005],ans;
queue<int>q;
bool flag[100005];
void add(int u,int v,int c,int f)
{
	e[++edgenum].cost=c;
	e[edgenum].flow=f;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
bool SPFA()
{
	for(int i=1;i<=n;i++)dis[i]=INF,a[i]=0;
	dis[s]=0,a[s]=INF;
	q.push(s);
	flag[s]=1;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		flag[node]=0;
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(e[hd].flow&&dis[to]>dis[node]+e[hd].cost)
			{
				dis[to]=dis[node]+e[hd].cost;
				a[to]=min(a[node],e[hd].flow);
				pre[to]=hd;
				if(!flag[to])
				{
					q.push(to);
					flag[to]=1;
				}
			}
		}
	}
	return dis[t]<INF;
}
int main()
{
	scanf("%d%d",&n,&m);
	s=n,t=n+1;
	n--;
	for(int i=1;i<=m;i++)
	{
		int u,v,f,c;
		scanf("%d%d%d%d",&u,&v,&c,&f);
		if(u==n+1)u=1;
		if(v==n+1)v=1;
		if(f<c)
		{
			add(v,u,1,f);
			add(u,v,-1,0);
			add(u,v,1,c-f);
			add(v,u,-1,0);
			add(u,v,2,INF);
			add(v,u,-2,0);
		}
		else
		{
			ans+=f-c;
			add(v,u,0,f-c);
			add(u,v,0,0);
			add(v,u,1,c);
			add(u,v,-1,0);
			add(u,v,2,INF);
			add(v,u,-2,0);
		}
		d[u]+=f;
		d[v]-=f;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]<0)
		{
			add(s,i,0,-d[i]);
			add(i,s,0,0);
		}
		else
		{
			add(i,t,0,d[i]);
			add(t,i,0,0);
		}
	}
	n+=2;
	while(SPFA())
	{
		int node=t;
		while(node!=s)
		{
			ans+=e[pre[node]].cost*a[t];
			e[pre[node]].flow-=a[t];
			e[pre[node]^1].flow+=a[t];
			node=e[pre[node]^1].to;
		}
	}
	printf("%d\n",ans);
	return 0;
}