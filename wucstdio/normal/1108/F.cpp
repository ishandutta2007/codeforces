#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
	int to;
	int next;
	int len;
}e[400005];
int n,m,edgenum=1,head[200005],dis[200005],pa[200005],dep[200005];
int anc[26][200005],maxx[26][200005];
bool flag[200005];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
void add(int u,int v,int l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].next=head[u];
	head[u]=edgenum;
}
void Prim()
{
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;
	q.push(make_pair(0,1));
	while(!q.empty())
	{
		int d=q.top().first;
		int node=q.top().second;
		q.pop();
		if(dis[node]!=d)continue;
		flag[node]=1;
		dep[node]=dep[pa[node]]+1;
		for(int hd=head[node];hd;hd=e[hd].next)
		{
			int to=e[hd].to;
			if(flag[to])continue;
			if(dis[to]>e[hd].len)
			{
				dis[to]=e[hd].len;
				pa[to]=node;
				q.push(make_pair(dis[to],to));
			}
		}
	}
}
int ask(int u,int v)
{
	int ans=0;
	if(dep[u]<dep[v])swap(u,v);
	for(int i=0;dep[u]-dep[v];i++)
	{
		if((1<<i)&dep[u]-dep[v])
		{
			ans=max(ans,maxx[i][u]);
			u=anc[i][u];
		}
	}
	if(u==v)return ans;
	for(int i=20;i>=0;i--)
	{
		if(anc[i][u]!=anc[i][v])
		{
			ans=max(ans,maxx[i][u]);
			ans=max(ans,maxx[i][v]);
			u=anc[i][u];
			v=anc[i][v];
		}
	}
	ans=max(ans,dis[u]);
	ans=max(ans,dis[v]);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		add(u,v,l);
		add(v,u,l);
	}
	Prim();
	for(int i=1;i<=n;i++)anc[0][i]=pa[i],maxx[0][i]=dis[i];
	for(int i=1;i<=20;i++)
	  for(int j=1;j<=n;j++)
	    anc[i][j]=anc[i-1][anc[i-1][j]],
	    maxx[i][j]=max(maxx[i-1][j],maxx[i-1][anc[i-1][j]]);
	int ans=0;
	for(int i=1;i<=edgenum;i+=2)
	{
		int u=e[i].to;
		int v=e[i^1].to;
		if(pa[u]==v||pa[v]==u)continue;
		if(ask(u,v)==e[i].len)ans++;
	}
	printf("%d\n",ans);
	return 0;
}