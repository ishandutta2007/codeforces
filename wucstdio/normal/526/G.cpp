#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=2147483647;
struct Edge
{
	int to;
	int nxt;
	int len;
}e[200005];
int n,m,root,edgenum,head[100005],f1[100005],f2[100005],pa[100005],son[100005];
int dis[100005],l[100005],sa[100005],rnk[100005],num,s[100005],minn[100005],anc[19][100005];
int dep[100005],d2[100005],dfn[100005],size[100005],top[100005],bot[100005],lca[100005];
void add(int u,int v,int l)
{
	e[++edgenum].len=l;
	e[edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
void dfs_pre(int node)
{
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs_pre(to);
		f2[node]=max(f2[node],f1[node]+f1[to]+e[hd].len);
		f1[node]=max(f1[node],f1[to]+e[hd].len);
	}
}
void dfs(int node)
{
	dep[node]=dep[pa[node]]+dis[node];
	d2[node]=d2[pa[node]]+1;
	dfn[node]=n;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dis[to]=e[hd].len;
		dfs(to);
		dfn[node]=min(dfn[node],dfn[to]);
		size[node]+=size[to];
		l[node]=max(l[node],l[to]);
		if(l[to]>l[son[node]])son[node]=to;
	}
	l[node]+=dis[node];
	if(!son[node])
	{
//		printf("%d ",node);
		sa[++num]=node;
		size[node]=1;
		bot[node]=node;
		dfn[node]=num;
	}
	if(son[node])bot[node]=bot[son[node]];
	else bot[node]=node;
	l[bot[node]]=l[node];
	top[bot[node]]=node;
}
void pre()
{
	for(int i=1;i<=n;i++)anc[0][i]=pa[i];
	for(int i=1;i<=18;i++)
	  for(int j=1;j<=n;j++)
	    anc[i][j]=anc[i-1][anc[i-1][j]];
}
int LCA(int u,int v)
{
	if(d2[u]<d2[v])swap(u,v);
	for(int i=0;d2[u]-d2[v];i++)
	  if((1<<i)&(d2[u]-d2[v]))
		u=anc[i][u];
	if(u==v)return u;
	for(int i=18;i>=0;i--)
	{
		if(anc[i][u]!=anc[i][v])
		{
			u=anc[i][u];
			v=anc[i][v];
		}
	}
	return pa[u];
}
bool cmp(int a,int b)
{
	return l[a]>l[b];
}
struct Tree
{
	#define lson tree[o].child[0]
	#define rson tree[o].child[1]
	#define mid (l+r)/2
	struct Node
	{
		int child[2];
		int tag;
		int top;
	}tree[10000005];
	int root[100005],tot;
	int query(int o,int l,int r,int p)
	{
		if(!o)return INF;
		int ans=tree[o].tag;
		if(p<=mid)ans=min(ans,query(lson,l,mid,p));
		else ans=min(ans,query(rson,mid+1,r,p));
		return ans;
	}
	int ask(int o,int l,int r,int p)
	{
		if(!o)return 0;
		int ans=dep[tree[o].top];
		if(p<=mid)ans=max(ans,ask(lson,l,mid,p));
		else ans=max(ans,ask(rson,mid+1,r,p));
		return ans;
	}
	void update(int pre,int o,int l,int r,int from,int to,int v,int t)
	{
		if(l>=from&&r<=to)
		{
			tree[o].tag=min(tree[o].tag,v);
			tree[o].top=t;
			return;
		}
		if(from<=mid)
		{
			if(lson==tree[pre].child[0])
			{
				lson=++tot;
				tree[lson]=tree[tree[pre].child[0]];
			}
			update(tree[pre].child[0],lson,l,mid,from,to,v,t);
		}
		if(to>mid)
		{
			if(rson==tree[pre].child[1])
			{
				rson=++tot;
				tree[rson]=tree[tree[pre].child[1]];
			}
			update(tree[pre].child[1],rson,mid+1,r,from,to,v,t);
		}
	}
	void debug()
	{
		for(int i=1;i<=num;i++)
		{
			printf("Tree %d:\n",i);
			printf("top:");
			for(int j=1;j<=num;j++)printf("%d ",ask(root[i],1,num,j));
			printf("\nlen:");
			for(int j=1;j<=num;j++)printf("%d ",query(root[i],1,num,j));
			printf("\n");
		}
	}
	#undef lson
	#undef rson
	#undef mid
}T;
void solve(int node)
{
	int t=top[node],len=0;
	T.root[rnk[bot[node]]]=++T.tot;
	T.tree[T.root[rnk[bot[node]]]]=T.tree[T.root[rnk[bot[node]]-1]];
	while(node!=pa[t])
	{
		for(int hd=head[node];hd;hd=e[hd].nxt)
		{
			int to=e[hd].to;
			if(to==pa[node])continue;
			if(to==son[node])continue;
//			if(t==root)printf("update(%d,[%d,%d],%d,%d)\n",to,dfn[to],dfn[to]+size[to]-1,len,node);
			T.update(T.root[rnk[bot[node]]-1],T.root[rnk[bot[node]]],1,num,dfn[to],dfn[to]+size[to]-1,len,node);
		}
		len+=dis[node];
		node=pa[node];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		add(u,v,l);
		add(v,u,l);
	}
	dfs_pre(1);
	for(int i=1;i<=n;i++)
	  if(f2[root]<f2[i])
	    root=i;
	memset(pa,0,sizeof(pa));
	dfs(root);
	root=bot[root];
	memset(son,0,sizeof(son));
	memset(l,0,sizeof(l));
	memset(pa,0,sizeof(pa));
	memset(dis,0,sizeof(dis));
	memset(size,0,sizeof(size));
	num=0;
//	printf("dfn:");
	dfs(root);
//	printf("\n");
	sort(sa+1,sa+num+1,cmp);
//	printf("%d\n",root);
//	for(int i=1;i<=num;i++)printf("%d ",sa[i]);
//	printf("\n");
	T.tree[0].tag=INF;
	minn[0]=INF;
	lca[0]=sa[1];
	pre();
//	printf("minn:");
	for(int i=1;i<=num;i++)
	{
		rnk[sa[i]]=i;
		s[i]=s[i-1]+l[sa[i]];
		lca[i]=LCA(lca[i-1],sa[i]);
		minn[i]=min(minn[i-1],l[sa[i]]);
		minn[i]=min(minn[i],dep[lca[i]]);
		if(i!=1)minn[i]=min(minn[i],dep[bot[pa[top[sa[i]]]]]-dep[pa[top[sa[i]]]]);
		solve(sa[i]);
//		printf("%d ",minn[i]);
	}
//	printf("\n");
//	T.debug();
	int lastans=0;
	while(m--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x=(x+lastans-1)%n+1;
		y=(y+lastans-1)%n+1;
//		printf("real:%d %d\n",x,y);
		x=bot[x];
		y=min(2*y-1,num);
		if(rnk[x]<=y)printf("%d\n",lastans=s[y]);
		else printf("%d\n",lastans=s[y]-min(T.query(T.root[y],1,num,dfn[x]),min(minn[y],dep[LCA(lca[y],x)]))+dep[x]-T.ask(T.root[y],1,num,dfn[x]));
	}
	return 0;
}