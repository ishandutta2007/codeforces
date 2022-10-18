#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
// #define int long long
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<signed,signed> pii;
#define N 200005
vector<pii> G[N];
int p[N],n,Q;
signed fa[N],dep[N],siz[N],dfn[N],son[N],top[N],rev[N],_cnt;
ll dis[N];
void dfs1(int u,int f)
{
	fa[u]=f,dep[u]=dep[f]+1,siz[u]=1;
	for(auto [v,w]:G[u])
	{
		if(v==f) continue;
		dis[v]=dis[u]+w;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int tp)
{
	top[u]=tp,dfn[u]=++_cnt; rev[_cnt]=u;
	if(!son[u]) return ;
	dfs2(son[u],tp);
	for(auto [v,w]:G[u])
	{
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
/*
struct Node
{
	signed ls,rs;
	short tag;
	int sum;
};
Node t[N*160];
*/
#define LIM 187
signed ls[N*LIM],rs[N*LIM];
signed tag[N*LIM];
ll sum[N*LIM];
int cnt,last;
signed rt[N];
void build(signed &u,int l,int r)
{
	u=++cnt; ls[u]=rs[u]=tag[u]=sum[u]=0;
	if(l==r) return ;
	int mid=(l+r)/2;
	build(ls[u],l,mid),build(rs[u],mid+1,r);
}
signed update(signed p,int l,int r,int L,int R)
{
#define v 1
	signed u;
	if(p>last) u=p;
	else u=++cnt;
	ls[u]=ls[p],rs[u]=rs[p],tag[u]=tag[p],sum[u]=sum[p];
	// printf("%d %d\n",u,sum[u]);
	if(L<=l&&r<=R)
	{
		sum[u]+=v*(dis[rev[r]]-dis[fa[rev[l]]]);
		tag[u]+=v;
		// printf("%d %d %d - %d %d %d\n",u,dis[rev[r]],dis[fa[rev[l]]],l,r,sum[u]);
		return u;
	}
	int mid=(l+r)/2;
	if(mid>=L) ls[u]=update(ls[p],l,mid,L,R);
	if(mid<R) rs[u]=update(rs[p],mid+1,r,L,R);
	// if(tag[u]) assert(top[rev[r]]==top[rev[l]]); 
	sum[u]=sum[ls[u]]+sum[rs[u]]+tag[u]*(dis[rev[r]]-dis[fa[rev[l]]]);
	// printf("%d %d\n",u,sum[u]);
	return u;
#undef v
}
ll query(int u,int l,int r,int L,int R)
{
	if(!u) return 0;
	if(L<=l&&r<=R) return sum[u];
	ll ans=tag[u]*(dis[rev[min(r,R)]]-dis[fa[rev[max(l,L)]]]);
	// if(tag[u]) assert(top[rev[R]]==top[rev[L]]);
	int mid=(l+r)/2;
	if(mid>=L) ans+=query(ls[u],l,mid,L,R);
	if(mid<R) ans+=query(rs[u],mid+1,r,L,R);
	return ans;
}
void upd(int nd,int pre,signed &cur)
{
	signed t=pre; last=cnt;
	while(nd)
	{
		signed q=t;
		t=update(q,1,n,dfn[top[nd]],dfn[nd]);
		nd=fa[top[nd]];
	}
	cur=t;
}
ll qry(int u){return sum[u];}
ll query(int u,int nd)
{
	ll ans=0;
	while(nd)
	{
		ans+=query(u,1,n,dfn[top[nd]],dfn[nd]);
		nd=fa[top[nd]];
	}
	return ans;
}
ll getans(int u,int v)
{
	// printf("%d %d - %d\n",u,v,qry(rt[u]));
	// printf("- %d %d\n",n,dis[v]);
	// printf("*  %d\n",query(rt[u],v));
	ll ans=qry(rt[u])+u*dis[v]-2*query(rt[u],v);
	return ans;
}
signed main()
{
	// cout<<N*160<<endl;
	// cout<<sizeof(t)/1024.0/1024.0<<endl;
	cin>>n>>Q;
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		G[u].eb(v,w),G[v].eb(u,w);
	}
	dfs1(1,0),dfs2(1,1);
	build(rt[0],1,n);
	for(int i=1;i<=n;i++) upd(p[i],rt[i-1],rt[i]);
	// for(int i=1;i<=n;i++) printf("%d%c",qry(rt[i])," \n"[i==n]);
	ll las=0;
	while(Q--)
	{
		int opt=read();
		if(opt==1)
		{
			int l=read()^las,r=read()^las,x=read()^las;
			las=getans(r,x)-getans(l-1,x);
			// printf("%d %d %d : ",l,r,x);
			printf("%lld\n",las);
			las&=((1<<30)-1);
		}
		else
		{
			int x=read()^las;
			rt[x]=0; swap(p[x],p[x+1]);
			upd(p[x],rt[x-1],rt[x]);
		}
		if(cnt>N*LIM-10000)
		{
			cerr<<"Passed\n";
			memset(rt,0,sizeof(rt));
			memset(ls,0,sizeof(ls));
			memset(rs,0,sizeof(rs));
			memset(tag,0,sizeof(tag));
			memset(sum,0,sizeof(sum));
			cnt=0;
			build(rt[0],1,n);
			for(int i=1;i<=n;i++) upd(p[i],rt[i-1],rt[i]);
		}
	}
	return 0;
}