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
typedef pair<int,int> pii;
#define N 500005
struct Opt
{
	Opt(int A,int B,int C):col(A),u(B),v(C){};
	int col,u,v;
};
stack<Opt> er;
int n,m,k,Q;
struct Dsu
{
	int fa[N+N],siz[N+N],id;
	int find(int u){return fa[u]==u?u:find(fa[u]);}
	void init(){for(int i=1;i<=n+n;i++) fa[i]=i,siz[i]=1;}
	void merge(int u,int v)
	{
		u=find(u),v=find(v);
		if(u==v) return ;
		if(siz[u]<siz[v]) swap(u,v);
		fa[v]=u; siz[u]+=siz[v];
		er.emplace(id,u,v);
	}
	bool query(int u,int v)
	{
		int A=find(u),B=find(u+n),C=find(v),D=find(v+n);
		if(A==C||B==D) return 0;
		// merge(A,B),merge(C,D);
		return 1;
	}
}dsu[55];
void reset()
{
	auto [col,u,v]=er.top(); er.pop();
	dsu[col].siz[u]-=dsu[col].siz[v];
	dsu[col].fa[v]=v;
}
int size(){return er.size();}
int u[N],v[N],nxt[N],tmp[N];
int id[N],col[N],ans[N],las[N],lid[N];
struct SMT
{
	#define mid (l+r)/2
	int ls[N*4],rs[N*4];
	vector<int> t[N*4];
	int _cnt;
	int build(int l,int r)
	{
		int u=++_cnt;
		if(l==r) return u;
		ls[u]=build(l,mid),rs[u]=build(mid+1,r);
		return u;
	}
	void update(int u,int l,int r,int L,int R,int x)
	{
		if(L>R) return ;
		if(L<=l&&r<=R) {t[u].pb(x); return ;}
		if(mid>=L) update(ls[u],l,mid,L,R,x);
		if(mid<R) update(rs[u],mid+1,r,L,R,x);
	}
	void query(int u,int l,int r)
	{
		int siz=size();
		for(int x:t[u]) dsu[col[x]].merge(::u[id[x]],v[id[x]]+n),dsu[col[x]].merge(::u[id[x]]+n,v[id[x]]);
		if(l==r)
		{
			ans[l]=dsu[col[l]].query(::u[id[l]],v[id[l]]);
			if(ans[l])
			{
				las[id[l]]=nxt[l],lid[id[l]]=l;
				update(1,1,Q,l+1,nxt[l]-1,l);
			}
			else
			{
				if(lid[id[l]]) update(1,1,Q,l+1,nxt[l]-1,lid[id[l]]);
			}
		}
		if(l!=r) query(ls[u],l,mid),query(rs[u],mid+1,r);
		int S=size();
		while(S>siz) S--,reset();
	}
}smt;
signed main()
{
	cin>>n>>m>>k>>Q;
	for(int i=1;i<=k;i++) dsu[i].id=i,dsu[i].init();
	for(int i=1;i<=m;i++) u[i]=read(),v[i]=read();
	for(int i=1;i<=Q;i++) id[i]=read(),col[i]=read();
	for(int i=1;i<=m;i++) tmp[i]=Q+1;
	for(int i=Q;i>=1;i--)
	{
		nxt[i]=tmp[id[i]];
		tmp[id[i]]=i;
	}
	smt.build(1,Q);
	smt.query(1,1,Q);
	for(int i=1;i<=Q;i++) printf("%s\n",ans[i]?"YES":"NO");
	return 0;
}