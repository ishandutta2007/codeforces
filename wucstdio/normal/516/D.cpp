#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Edge
{
	int to;
	int nxt;
	ll len;
}e[200005];
int n,m,edgenum,head[100005],cnt[100005],pa[100005],son[100005],anc[21][100005],d[100005],maxx[100005],a[100005];
ll d1[100005],d2[100005];
void add(int u,int v,ll l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs1(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(pa[node]==to)continue;
		pa[to]=node;
		dfs1(to);
		if(d1[to]+e[hd].len>d1[node])
		{
			d2[node]=d1[node];
			d1[node]=d1[to]+e[hd].len;
			son[node]=to;
		}
		else if(d1[to]+e[hd].len>d2[node])
		  d2[node]=d1[to]+e[hd].len;
	}
}
void dfs2(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		ll d=0;
		if(to==son[node])d=d2[node]+e[hd].len;
		else d=d1[node]+e[hd].len;
		if(d>d1[to])
		{
			d1[to]=d;
			son[to]=0;
		}
		else if(d>d2[to])d2[to]=d;
		dfs2(to);
	}
}
int ind=0;
void dfs3(int node)
{
	a[++ind]=node;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs3(to);
	}
}
void pre()
{
	for(int i=1;i<=n;i++)anc[0][i]=pa[i];
	for(int i=1;i<=20;i++)
	  for(int j=1;j<=n;j++)
	    anc[i][j]=anc[i-1][anc[i-1][j]];
	for(int i=1;i<=n;i++)
	{
		maxx[i]=20;
		while(maxx[i]&&anc[maxx[i]][i]==0)maxx[i]--;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		ll l;
		scanf("%d%d%lld",&u,&v,&l);
		add(u,v,l);
		add(v,u,l);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]!=1)
		{
			dfs1(i);
			dfs2(i);
			break;
		}
	}
	int root=0;
	d1[root]=1000000000000000000;
	for(int i=1;i<=n;i++)
	  if(d1[i]<d1[root])root=i;
	memset(pa,0,sizeof(pa));
	dfs3(root);
	pre();
	scanf("%d",&m);
	while(m--)
	{
		ll l;
		scanf("%lld",&l);
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			cnt[i]++;
			int x=i;
			for(int j=maxx[x];j>=0;j=min(j-1,maxx[x]))
			{
				if(d1[anc[j][x]]+l>=d1[i])
				  x=anc[j][x];
			}
			cnt[pa[x]]--;
		}
		int ans=0;
		for(int i=n;i>=1;i--)
		{
			int node=a[i];
			ans=max(ans,cnt[node]);
			cnt[pa[node]]+=cnt[node];
		}
		printf("%d\n",ans);
	}
	return 0;
}