#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct Node
{
	int id;
	int len,col;
	Node(int i=0,int l=0,int c=0){id=i,len=l,col=c;}
};
struct Edge
{
	int to;
	int nxt;
}e[1000005];
int n,m,tot,edgenum,head[500005],scc,in[500005],len[500005];
int dfn[500005],low[500005],t[500005],st[500005],u[1000005],v[1000005],top,d[500005];
bool flag[500005];
vector<Node>s[50005];
queue<int>q;
bool cmp(Node a,Node b)
{
	return a.col<b.col;
}
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void solve(int node)
{
	int x=(int)s[node].size();
	for(int i=0;i<x;i++)
	{
		add(++tot,s[node][i].id+m);
		if(i)
		{
			add(tot,tot-1);
			add(s[node][i].id,tot-1);
		}
	}
	for(int i=x-1;i>=0;i--)
	{
		add(++tot,s[node][i].id+m);
		if(i!=x-1)
		{
			add(tot,tot-1);
			add(s[node][i].id,tot-1);
		}
	}
	sort(s[node].begin(),s[node].end(),cmp);
	int last=0;
	for(int i=1;i<x;i++)
	{
		if(s[node][i].col!=s[node][last].col)last=i;
		if(i-last>1)
		{
			puts("No");
			exit(0);
		}
		if(i!=last)
		{
			add(s[node][i].id,s[node][last].id+m);
			add(s[node][last].id+m,s[node][i].id);
			add(s[node][i].id+m,s[node][last].id);
			add(s[node][last].id,s[node][i].id+m);
		}
	}
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
		in[v]=++scc;
		t[scc]=max(t[scc],len[v]);
		while(v!=node)
		{
			v=st[top--];
			flag[v]=0;
			in[v]=scc;
			t[scc]=max(t[scc],len[v]);
		}
	}
}
bool check(int mid)
{
	for(int i=1;i<=scc;i++)flag[i]=(t[i]>mid);
	for(int i=1;i<=scc;i++)
	  if(flag[i])q.push(i);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(flag[to])continue;
			flag[to]=1;
			q.push(to);
		}
	}
	for(int i=1;i<=m;i++)
	  if(flag[in[i]]&&flag[in[i+m]])
	    return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	tot=2*m;
	for(int i=1;i<=m;i++)
	{
		int u,v,l,c;
		scanf("%d%d%d%d",&u,&v,&c,&l);
		len[i]=l;
		s[u].push_back(Node(i,l,c));
		s[v].push_back(Node(i,l,c));
	}
	for(int i=1;i<=n;i++)solve(i);
	for(int i=1;i<=tot;i++)Tarjan(i);
	for(int i=1;i<=m;i++)
	{
		if(in[i]==in[i+m])
		{
			printf("No\n");
			return 0;
		}
	}
	edgenum=0;
	for(int i=1;i<=tot;i++)
	{
		for(int hd=head[i];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(in[i]!=in[to])
			{
				u[++edgenum]=in[i];
				v[edgenum]=in[to];
				d[in[i]]++;
			}
		}
	}
	memset(head,0,sizeof(head));
	tot=edgenum,edgenum=0;
	for(int i=1;i<=tot;i++)add(v[i],u[i]);
	int l=0,r=1000000000;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	check(l);
	for(int i=1;i<=scc;i++)
	  if(d[i]==0)q.push(i);
	tot=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		dfn[node]=++tot;
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			d[to]--;
			if(d[to]==0)q.push(to);
		}
	}
	printf("Yes\n");
	printf("%d ",l);
	tot=0;
	for(int i=1;i<=m;i++)
	{
		if(flag[in[i+m]])tot++;
		if(!flag[in[i]]&&!flag[in[i+m]])tot+=(dfn[in[i]]<dfn[in[i+m]]);
	}
	printf("%d\n",tot);
	for(int i=1;i<=m;i++)
	{
		if(flag[in[i+m]])printf("%d ",i);
		if(!flag[in[i]]&&!flag[in[i+m]]&&dfn[in[i]]<dfn[in[i+m]])
		  printf("%d ",i);
	}
	printf("\n");
	return 0;
}