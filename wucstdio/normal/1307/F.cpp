#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct Edge
{
	int to;
	int nxt;
}e[800005];
struct Union
{
	int pa[400005];
	Union(){for(int i=1;i<=400000;i++)pa[i]=i;}
	int find(int x)
	{
		return x==pa[x]?x:pa[x]=find(pa[x]);
	}
	void merge(int x,int y)
	{
		x=find(x),y=find(y);
		pa[y]=x;
	}
}U;
int n,k,r,m,edgenum,head[400005],dep[400005],pa[400005],anc[21][400005];
int a[400005];
queue<int>q;
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs(int node)
{
	dep[node]=dep[pa[node]]+1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
	}
}
void pre()
{
	for(int i=1;i<=n;i++)anc[0][i]=pa[i];
	for(int i=1;i<=20;i++)
	  for(int j=1;j<=n;j++)
	    anc[i][j]=anc[i-1][anc[i-1][j]];
}
int LCA(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=0;dep[u]-dep[v];i++)
	  if((1<<i)&(dep[u]-dep[v]))
		u=anc[i][u];
	if(u==v)return u;
	for(int i=20;i>=0;i--)
	{
		if(anc[i][u]!=anc[i][v])
		{
			u=anc[i][u];
			v=anc[i][v];
		}
	}
	return pa[u];
}
int kth(int x,int k)
{
	for(int i=0;k;i++)
	  if((1<<i)&k)x=anc[i][x],k^=1<<i;
	return x;
}
int main()
{
	scanf("%d%d%d",&n,&k,&r);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,i+n);
		add(i+n,u);
		add(v,i+n);
		add(i+n,v);
	}
	n+=n-1;
	memset(dep,0x3f,sizeof(dep));
	for(int i=1;i<=r;i++)
	{
		scanf("%d",&a[i]);
		q.push(a[i]);
		dep[a[i]]=0;
	}
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(dep[to]>dep[node]+1)
			{
				dep[to]=dep[node]+1;
				q.push(to);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dep[i]>k)continue;
		for(int hd=head[i];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(dep[to]<k||dep[i]<k)U.merge(i,to);
		}
	}
	dfs(1);
	pre();
	scanf("%d",&m);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int d=LCA(u,v);
		if(dep[u]+dep[v]-2*dep[d]<=2*k)
		{
			printf("YES\n");
			continue;
		}
		if(dep[u]-dep[d]>=k)u=kth(u,k);
		else u=kth(v,dep[v]-(dep[d]+k-dep[u]+dep[d]));
		if(dep[v]-dep[d]>=k)v=kth(v,k);
		else v=kth(u,dep[u]-(dep[d]+k-dep[v]+dep[d]));
		if(U.find(u)==U.find(v))printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}