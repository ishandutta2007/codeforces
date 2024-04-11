#include<bits/stdc++.h>
using namespace std;
const int N=800005;
int n,m,a[N],p[N],ans,d[N],st[N][19],cnt,lg[N],dfn[N];
vector<int>e[N];
void dfs(int u,int f)
{
	d[u]=d[f]+1;
	st[++cnt][0]=u;
	dfn[u]=cnt;
	for(auto v:e[u])
	{
		dfs(v,u);
		st[++cnt][0]=u;
	}
}
int mn(int u,int v)
{	
	if(!u||!v)
		return u^v;
	return d[u]<d[v]?u:v;
}
int lca(int u,int v)
{
	u=dfn[u],v=dfn[v];
	if(u>v)
		swap(u,v);
	int x=lg[v-u+1];
	int ans=mn(st[u][x],st[v-(1<<x)+1][x]);
	return ans;
}
int can(int u,int v)
{
	int l=lca(u,v);
	return l==u;
}
struct node
{
	int x,y;
	node(){}
	node(int _x,int _y):x(_x),y(_y){}
}tr[N],t;
int path(int u1,int v1,int u2,int v2)
{
	int l=lca(u1,v1);
	if(!can(l,u2)||!can(l,v2))
		return 0;
	if(!can(u2,u1)&&!can(u2,v1))
		return 0;
	if(!can(v2,u1)&&!can(v2,v1))
		return 0;
	return 1;
}
node merge(node u,node v)
{
	if(u.x==-1||u.y==-1)
		return node(-1,-1);
	if(u.x==0)
		return v;
	if(v.x==0)
		return u;
	if(path(u.x,u.y,v.x,v.y))
		return node(u.x,u.y);
	if(path(u.x,v.x,u.y,v.y))
		return node(u.x,v.x);
	if(path(u.x,v.y,u.y,v.x))
		return node(u.x,v.y);
	if(path(u.y,v.x,u.x,v.y))
		return node(u.y,v.x);
	if(path(u.y,v.y,u.x,v.x))
		return node(u.y,v.y);
	if(path(v.x,v.y,u.x,u.y))
		return node(v.x,v.y);
	return node(-1,-1);
}
void build(int k,int l,int r)
{
	if(l==r)
	{
		tr[k]=node(p[l],p[l]);
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
}
void update(int k,int l,int r,int x)
{
	if(l==r)
	{
		tr[k]=node(p[x],p[x]);
		return;
	}
	int mid=l+r>>1;
	if(x<=mid) update(k<<1,l,mid,x);
	else update(k<<1|1,mid+1,r,x);
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
}
void query(int k,int l,int r)
{
	if(l==r)
	{
		node u=merge(t,tr[k]);
		if(u.x!=-1)
			ans=l;
		return;
	}
	int mid=l+r>>1;
	node u=merge(t,tr[k<<1]);
	if(u.x!=-1)
	{
		t=u;
		ans=mid;
		query(k<<1|1,mid+1,r);
	}
	else
		query(k<<1,l,mid);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]++;
		p[a[i]]=i;
	}
	for(int i=2;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		e[x].push_back(i);
	}
	dfs(1,0);
	for(int i=2;i<=n*2;i++)
		lg[i]=lg[i>>1]+1;
	for(int j=1;j<=18;j++)
		for(int i=1;i<=n*2;i++)
			st[i][j]=mn(st[i][j-1],st[i+(1<<j-1)][j-1]);
	build(1,1,n);
	scanf("%d",&m);
	while(m--)
	{
		int ty;
		scanf("%d",&ty);
		if(ty==1)
		{
			int u,v,x,y;
			scanf("%d%d",&u,&v);
			x=a[u],y=a[v];
			swap(a[u],a[v]);
			swap(p[x],p[y]);
			update(1,1,n,x);
			update(1,1,n,y);
		}
		else
		{
			ans=0,t=node(0,0);
			query(1,1,n);
			printf("%d\n",ans);
		}
	}
	return 0;
}