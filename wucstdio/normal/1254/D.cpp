#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#define ll long long
#define lson o<<1
#define rson o<<1|1
#define mid (l+r)/2
using namespace std;
const ll MOD=998244353;
struct Edge
{
	int to;
	int nxt;
}e[300005];
struct Tree
{
	ll add;
}tree[1200005];
int B,n,m,edgenum,head[200005],dep[200005],dfn[200005],pa[200005],size[200005];
int a[400005],p[200005],minp[21][400005],tot,lg2[400005];
int d[400005],st[400005],top;
ll tag[200005];
ll quick_pow(ll x,ll a)
{
	ll ans=1;
	while(a)
	{
		if(a&1)ans=ans*x%MOD;
		x=x*x%MOD;
		a>>=1;
	}
	return ans;
}
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].nxt=head[u];
	head[u]=edgenum;
}
int ind=0;
void dfs(int node)
{
	dfn[node]=++ind;
	size[node]=1;
	a[++tot]=node;
	p[node]=tot;
	dep[node]=dep[pa[node]]+1;
	for(int hd=head[node];hd;hd=e[hd].nxt)
	{
		int to=e[hd].to;
		if(to==pa[node])continue;
		pa[to]=node;
		dfs(to);
		size[node]+=size[to];
		a[++tot]=node;
	}
}
void pre()
{
	for(int i=1;i<=tot;i++)minp[0][i]=i;
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j<=tot;j++)
		{
			if(dep[a[minp[i-1][j]]]<dep[a[minp[i-1][j+(1<<(i-1))]]])minp[i][j]=minp[i-1][j];
			else minp[i][j]=minp[i-1][j+(1<<(i-1))];
		}
	}
	for(int i=2;i<=tot;i++)lg2[i]=lg2[i>>1]+1;
}
int LCA(int u,int v)
{
	u=p[u],v=p[v];
	if(u>v)swap(u,v);
	if(u==v)return u;
	int d=lg2[v-u+1];
	return dep[a[minp[d][u]]]<dep[a[minp[d][v-(1<<d)+1]]]?a[minp[d][u]]:a[minp[d][v-(1<<d)+1]];
}
int LCA2(int u,int v)
{
	u=p[u],v=p[v];
	if(u>v)swap(u,v);
	if(u==v)return u;
	int d=lg2[v-u+1];
	int ans=dep[a[minp[d][u]]]<dep[a[minp[d][v-(1<<d)+1]]]?minp[d][u]:minp[d][v-(1<<d)+1];
	return a[ans+1];
}
void update(int o,int l,int r,int from,int to,ll v)
{
	if(l>=from&&r<=to)
	{
		tree[o].add+=v;
		return;
	}
	if(from<=mid)update(lson,l,mid,from,to,v);
	if(to>mid)update(rson,mid+1,r,from,to,v);
}
ll query(int o,int l,int r,int p)
{
	if(l==r)return tree[o].add;
	ll ans=tree[o].add;
	if(p<=mid)ans+=query(lson,l,mid,p);
	else ans+=query(rson,mid+1,r,p);
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	B=(int)(sqrt(n)*0.5);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		d[u]++,d[v]++;
	}
	for(int i=1;i<=n;i++)
	  if(d[i]>B)st[++top]=i;
	dfs(1);
	pre();
	ll inv=quick_pow(n,MOD-2);
	while(m--)
	{
		int type,x;
		scanf("%d%d",&type,&x);
		if(type==1)
		{
			ll y;
			scanf("%lld",&y);
			update(1,1,n,1,n,y);
			if(d[x]<=B)
			{
				for(int hd=head[x];hd;hd=e[hd].nxt)
				{
					int to=e[hd].to;
					if(pa[to]==x)update(1,1,n,dfn[to],dfn[to]+size[to]-1,MOD-y*inv%MOD*size[to]%MOD);
					else
					{
						update(1,1,n,1,n,MOD-y*inv%MOD*(n-size[x])%MOD);
						update(1,1,n,dfn[x],dfn[x]+size[x]-1,y*inv%MOD*(n-size[x])%MOD);
					}
				}
			}
			else tag[x]+=y;
		}
		else
		{
			ll ans=query(1,1,n,dfn[x]);
			for(int i=1;i<=top;i++)
			{
				if(x==st[i])continue;
				int lca=LCA(x,st[i]);
				if(lca==st[i])ans-=tag[st[i]]%MOD*inv%MOD*size[LCA2(st[i],x)]%MOD;
				else ans-=tag[st[i]]%MOD*inv%MOD*(n-size[st[i]])%MOD;
			}
			ans%=MOD;
			if(ans<0)ans+=MOD;
			printf("%lld\n",ans);
		}
	}
	return 0;
}