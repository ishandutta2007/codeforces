#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
inline char rdch()
{
	char ch=getchar();
	while(!(ch>='A'&&ch<='Z')) ch=getchar();
	return ch;
}
typedef pair<int,int> pii;
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 1000005
struct Query
{
	char opt;
	signed x,y;
};
struct _Query
{
	signed u,x,id;
};
Query q[N];
signed l[N];
int ans[N];
int n,Q;
struct Seg_tr1
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	signed t[N*4];
	void pushdown(int u)
	{
		if(t[u]) t[ls]=t[rs]=t[u],t[u]=0;
	}
	void assign(int u,int l,int r,int L,int R,int d)
	{
		if(L<=l&&r<=R) {t[u]=d; return ;}
		pushdown(u);
		int mid=(l+r)/2;
		if(mid>=L) assign(ls,l,mid,L,R,d);
		if(mid<R) assign(rs,mid+1,r,L,R,d);
	}
	int query(int u,int l,int r,int p)
	{
		if(l==r) return t[u];
		int mid=(l+r)/2;
		pushdown(u);
		if(p<=mid) return query(ls,l,mid,p);
		else return query(rs,mid+1,r,p);
	}
};
struct Seg_tr2
{
	#define ls (u<<1)
	#define rs (u<<1|1)
	int t[N*4],tag[N*4];
	void pushdown(int u,int l,int r)
	{
		int mid=(l+r)/2;
		if(!tag[u]) return ;
		t[ls]+=tag[u]*(mid-l+1);
		t[rs]+=tag[u]*(r-mid);
		tag[ls]+=tag[u];
		tag[rs]+=tag[u];
		tag[u]=0;
	}
	void update(int u,int l,int r,int L,int R,int d)
	{
		if(L<=l&&r<=R)
		{
			tag[u]+=d;
			t[u]+=d*(r-l+1);
			return ;
		}
		pushdown(u,l,r);
		int mid=(l+r)/2;
		if(mid>=L) update(ls,l,mid,L,R,d);
		if(mid<R) update(rs,mid+1,r,L,R,d);
	}
	int query(int u,int l,int r,int p)
	{
		if(l==r) return t[u];
		pushdown(u,l,r);
		int mid=(l+r)/2;
		if(p<=mid) return query(ls,l,mid,p);
		else return query(rs,mid+1,r,p);
	}
};
struct _B
{
	vector<signed> G[N];
	signed fa[N],tot,f[N],id[N],dfn[N],cnt,siz[N];
	Seg_tr1 t;
	int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
	void init()
	{
		tot=n;
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	void update(int u,int v)
	{
		u=find(u),v=find(v);
		tot++;
		fa[u]=fa[v]=fa[tot]=tot;
		f[u]=f[v]=tot;
		G[tot].pb(u),G[tot].pb(v);
	}
	void dfs(int u)
	{
		dfn[u]=++cnt; siz[u]=1;
		for(int v:G[u])
		{
			dfs(v);
			siz[u]+=siz[v];
		}
	}
	void solve()
	{
		for(int i=1;i<=tot;i++) if(find(i)==i) dfs(i);
		for(int i=1;i<=n;i++) id[i]=i;
		for(int i=1;i<=Q;i++)
		{
			if(q[i].opt=='Z')
			{
				int u=id[q[i].x];
				t.assign(1,1,tot,dfn[u],dfn[u]+siz[u]-1,i);
			}
			if(q[i].opt=='Q')
			{
				int u=q[i].x;
				l[i]=t.query(1,1,tot,dfn[u]);
			}
			if(q[i].opt=='M')
			{
				int u=q[i].x;
				id[u]=f[id[u]];
			}
		}
	}
}B;

struct _A
{
	vector<signed> G[N];
	signed fa[N],tot,f[N],id[N],dfn[N],cnt,siz[N],r[N];
	Seg_tr2 t;
	int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
	vector<_Query> a[N];
	void init()
	{
		tot=n;
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	void update(int u,int v)
	{
		u=find(u),v=find(v);
		tot++;
		fa[u]=fa[v]=fa[tot]=tot;
		f[u]=f[v]=tot;
		G[tot].pb(u),G[tot].pb(v);
	}
	void dfs(int u)
	{
		dfn[u]=++cnt; siz[u]=1;
		for(int v:G[u])
		{
			dfs(v);
			siz[u]+=siz[v];
		}
	}
	void solve()
	{
		for(int i=1;i<=tot;i++) if(find(i)==i) dfs(i);
		for(int i=1;i<=n;i++) id[i]=i,r[i]=1;
		for(int i=1;i<=Q;i++)
		{
			if(q[i].opt=='Q')
			{
				int u=q[i].x;
				a[l[i]].pb((_Query){u,-1,i});
				a[i].pb((_Query){u,1,i});
			}
		}
		for(int i=1;i<=Q;i++)
		{
			if(q[i].opt=='A')
			{
				int u=id[q[i].x];
				t.update(1,1,tot,dfn[u],dfn[u]+siz[u]-1,r[q[i].x]);
			}
			if(q[i].opt=='U')
			{
				int u=q[i].x;
				r[u]+=r[q[i].y];
				id[u]=f[id[u]];
			}
			for(int j=0;j<(int)a[i].size();j++)
			{
				// printf("%d %d %d\n",a[i][j].u,a[i][j].x,a[i][j].id);
				int u=a[i][j].u;
				if(a[i][j].x==1) ans[a[i][j].id]+=t.query(1,1,tot,dfn[u]);
				else ans[a[i][j].id]-=t.query(1,1,tot,dfn[u]);
			}
		}
	}
}A;
signed main()
{
	cin>>n>>Q;
	B.init(); A.init();
	for(int i=1;i<=Q;i++)
	{
		q[i].opt=rdch();
		q[i].x=read();
		if(q[i].opt=='U')
		{
			q[i].y=read();
			A.update(q[i].x,q[i].y);
		}
		if(q[i].opt=='M')
		{
			q[i].y=read();
			B.update(q[i].x,q[i].y);
		}
	}
	B.solve(); A.solve();
	// for(int i=1;i<=Q;i++)
	// {
		// if(q[i].opt=='Q') printf("%lld\n",l[i]);
	// }	
	for(int i=1;i<=Q;i++)
	{
		if(q[i].opt=='Q') printf("%lld\n",ans[i]);
	}
	return 0;
}