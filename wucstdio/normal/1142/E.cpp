#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
struct Edge
{
	int from;
	int to;
	int nxt;
}e[200005];
int n,m,edgenum,head[100005],dfn[100005],low[100005],now[100005],d[100005],size[100005];
int st[100005],top,scc,p[100005];
bool flag[100005];
vector<int>SCC[100005];
void add(int u,int v)
{
	e[++edgenum].from=u;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int ind;
void Tarjan(int node)
{
	if(dfn[node])return;
	dfn[node]=low[node]=++ind;
	st[++top]=node;
	flag[node]=1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(!dfn[to])
		{
			Tarjan(to);
			low[node]=min(low[node],low[to]);
		}
		else if(flag[to])low[node]=min(low[node],dfn[to]);
	}
	if(dfn[node]==low[node])
	{
		int v=st[top--];
		flag[v]=0;
		SCC[++scc].push_back(v);
		p[v]=scc;
		while(v!=node)
		{
			v=st[top--];
			flag[v]=0;
			SCC[scc].push_back(v);
			p[v]=scc;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	for(int i=1;i<=n;i++)
	  Tarjan(i);
	memset(head,0,sizeof(head));
	for(int i=1;i<=scc;i++)
	  size[i]=(int)SCC[i].size();
	edgenum=0;
	for(int i=1;i<=m;i++)
	{
		if(p[e[i].from]!=p[e[i].to])
		{
			d[p[e[i].to]]++;
			add(p[e[i].from],p[e[i].to]);
		}
	}
	top=0;
	for(int i=1;i<=scc;i++)
	{
		if(d[i]==0)
		  st[++top]=i;
	}
	int x=1,y=2;
	while(y<=top)
	{
		printf("? %d %d\n",SCC[st[x]][now[st[x]]],SCC[st[y]][now[st[y]]]);
		fflush(stdout);
		int xx;
		scanf("%d",&xx);
		if(xx)
		{
			now[st[y]]++;
			if(now[st[y]]>=size[st[y]])
			{
				for(int hd=head[st[y]];hd;hd=e[hd].nxt)
				{
					int to=e[hd].to;
					d[to]--;
					if(d[to]==0)st[++top]=to;
				}
				y++;
			}
		}
		else
		{
			now[st[x]]++;
			if(now[st[x]]>=size[st[x]])
			{
				for(int hd=head[st[x]];hd;hd=e[hd].nxt)
				{
					int to=e[hd].to;
					d[to]--;
					if(d[to]==0)st[++top]=to;
				}
				x=y;
				y++;
			}
		}
	}
	printf("! %d\n",SCC[st[x]][now[st[x]]]);
	return 0;
}