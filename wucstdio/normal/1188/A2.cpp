#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int nxt;
	int len;
}e[200005];
int n,m,edgenum,root,head[1005],d[1005],s1[1005],s2[1005],pa[1005],dep[1005],dis[1005];
int from[1000005],to[1000005],len[1000005],tot,cnt[1005];
void add(int u,int v,int l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs_pre(int node)
{
	dep[node]=dep[pa[node]]+1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dis[to]=e[hd].len;
		dfs_pre(to);
		if(!s1[node])s1[node]=s1[to];
		else s2[node]=s1[to];
	}
	if(!s1[node])s1[node]=node;
}
void dfs(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		dfs(to);
		cnt[node]+=cnt[to];
	}
	if(node!=root)dis[node]-=cnt[node];
	if(!dis[node])return;
	if(d[node]==1)
	{
		from[++tot]=node;
		to[tot]=root;
		len[tot]=dis[node];
		cnt[node]+=dis[node];
		dis[node]=0;
	}
	else if(!s2[node])
	{
		printf("NO\n");
		exit(0);
	}
	else
	{
		from[++tot]=s1[node];
		to[tot]=root;
		len[tot]=dis[node]/2;
		from[++tot]=s2[node];
		to[tot]=root;
		len[tot]=dis[node]/2;
		from[++tot]=s1[node];
		to[tot]=s2[node];
		len[tot]=-dis[node]/2;
		cnt[node]+=dis[node];
		dis[node]=0;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		add(u,v,l);
		add(v,u,l);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(d[i]==1)
		{
			root=i;
			break;
		}
	}
	dfs_pre(root);
	dfs(root);
	printf("YES\n");
	printf("%d\n",tot);
	for(int i=1;i<=tot;i++)printf("%d %d %d\n",from[i],to[i],len[i]);
	return 0;
}