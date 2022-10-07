#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
	int from;
	int to;
	int nxt;
}e[5000005];
int n,m,d,edgenum,head[5000005],dfn[5000005],low[5000005];
int st[5000005],top,scc,p[5000005],v[5000005];
bool flag[5000005];
queue<int>q;
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
	st[++top]=node;
	flag[node]=1;
	dfn[node]=low[node]=++ind;
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
		p[v]=++scc;
		while(v!=node)
		{
			v=st[top--];
			flag[v]=0;
			p[v]=scc;
		}
	}
}
char s[105];
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--;
		for(int x=1;x<d;x++)
			add(u*d+x,v*d+x+1);
		add(u*d+d,v*d+1);
	}
	for(int i=1;i<=n*d;i++)
	  Tarjan(i);
	edgenum=0;
	memset(head,0,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(flag,0,sizeof(flag));
	memset(st,0,sizeof(st));
	for(int i=1;i<=m*d;i++)
	{
		if(p[e[i].from]!=p[e[i].to])
		{
			dfn[p[e[i].from]]++;
			add(p[e[i].to],p[e[i].from]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		for(int j=1;j<=d;j++)
		{
			if(s[j]=='1')
			{
				if(!flag[p[(i-1)*d+j]])
				{
					flag[p[(i-1)*d+j]]=1;
					v[p[(i-1)*d+j]]++;
				}
			}
		}
		for(int j=1;j<=d;j++)
		  if(s[j]=='1')
			flag[p[(i-1)*d+j]]=0;
	}
	for(int i=1;i<=scc;i++)
	  if(dfn[i]==0)
	    q.push(i);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		st[node]+=v[node];
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			st[to]=max(st[to],st[node]);
			dfn[to]--;
			if(dfn[to]==0)q.push(to);
		}
	}
	printf("%d\n",st[p[1]]);
	return 0;
}