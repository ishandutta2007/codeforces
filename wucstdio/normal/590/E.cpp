#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int INF=2147483647;
struct Tree
{
	int child[2];
	int fail;
	vector<int>s;
}tree[10000005];
struct Edge
{
	int to;
	int nxt;
	int flow;
}e[2000005];
int n,m,s,t,tot=1,edgenum=1,en[10000005],head[2005],cur[2005],dep[2005],sa[10000005];
bool a[1005][1005];
queue<int>q;
char ss[10000005];
int ins(char*s,int len,int id)
{
	int x=1;
	for(int i=1;i<=len;i++)
	{
		if(!tree[x].child[s[i]-'a'])tree[x].child[s[i]-'a']=++tot;
		x=tree[x].child[s[i]-'a'];
		tree[x].s.push_back(id);
	}
	return x;
}
void build()
{
	q.push(1);
	int tot=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		sa[++tot]=node;
		for(int i=0;i<2;i++)
		{
			if(!tree[node].child[i])
			{
				if(node==1)tree[node].child[i]=1;
				else tree[node].child[i]=tree[tree[node].fail].child[i];
			}
			else
			{
				if(node==1)tree[tree[node].child[i]].fail=1;
				else tree[tree[node].child[i]].fail=tree[tree[node].fail].child[i];
				q.push(tree[node].child[i]);
			}
		}
	}
}
void add(int u,int v,int f)
{
	e[++edgenum].flow=f;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int dfs(int node,int nowf)
{
	if(node==t)return nowf;
	for(int&hd=cur[node];hd;hd=e[hd].nxt)
	{
		if(e[hd].flow==0)continue;
		int to=e[hd].to;
		if(dep[to]==dep[node]+1)
		{
			int d=dfs(to,min(nowf,e[hd].flow));
			if(d)
			{
				e[hd].flow-=d;
				e[hd^1].flow+=d;
				return d;
			}
		}
	}
	return 0;
}
bool bfs()
{
	while(!q.empty())q.pop();
	for(int i=1;i<=t;i++)dep[i]=0;
	dep[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			if(e[hd].flow==0)continue;
			int to=e[hd].to;
			if(!dep[to])
			{
				dep[to]=dep[node]+1;
				q.push(to);
			}
		}
		if(dep[t])return 1;
	}
	return dep[t];
}
int Dinic()
{
	int ans=0,d;
	while(bfs())
	{
		for(int i=1;i<=t;i++)cur[i]=head[i];
		while((d=dfs(s,INF)))ans+=d;
	}
	return ans;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",ss+1);
		int l=(int)strlen(ss+1);
		en[ins(ss,l,i)]=i;
	}
	build();
	for(int t=1;t<=tot;t++)
	{
		int i=sa[t];
		if(!en[tree[i].fail])tree[i].fail=tree[tree[i].fail].fail;
		if(en[tree[i].fail])
		{
			for(auto t:tree[i].s)a[en[tree[i].fail]][t]=1;
		}
		if(en[i])
		{
			for(auto t:tree[i].s)
			{
				if(t==en[i])continue;
				a[en[i]][t]=1;
			}
		}
	}
	for(int k=1;k<=n;k++)
	  for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++)
	      a[i][j]|=a[i][k]&a[k][j];
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
	    if(a[i][j])add(i,j+n,1),add(j+n,i,0);
	s=2*n+1,t=2*n+2;
	for(int i=n;i>=1;i--)
	{
		add(s,i,1);
		add(i,s,0);
		add(i+n,t,1);
		add(t,i+n,0);
	}
	printf("%d\n",n-Dinic());
	for(int i=1;i<=n;i++)
	  if(dep[i]&&!dep[i+n])printf("%d ",i);
	printf("\n");
	return 0;
}