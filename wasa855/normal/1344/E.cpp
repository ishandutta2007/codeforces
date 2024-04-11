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
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
signed ch[N][2],fa[N],n,m,Q;
vector<pii> G[N];
int dep[N],las[N];
bool isroot(int u) {return ch[fa[u]][0]!=u&&ch[fa[u]][1]!=u;}
bool isson(int u) {return ch[fa[u]][1]==u;}
void rotate(int u)
{
	int v=fa[u],w=fa[v],k=isson(u);
	if(!isroot(v)) ch[w][isson(v)]=u;
	ch[v][k]=ch[u][k^1];
	if(ch[u][k^1]) fa[ch[u][k^1]]=v;
	ch[u][k^1]=v,fa[v]=u,fa[u]=w;
}
void splay(int u)
{
	for(;!isroot(u);rotate(u))
	{
		if(!isroot(fa[u])) rotate(isson(u)==isson(fa[u])?fa[u]:u);
	}
}
struct Node
{
	int l,r;
	bool operator < (const Node &x) const {return r>x.r;}
};
Node a[N*70];
struct HLD
{
	signed fa[N],siz[N],dep[N],son[N],top[N],dfn[N],rev[N],dfscnt;
	void dfs1(int u,int f)
	{
		fa[u]=f,siz[u]=1,dep[u]=dep[f]+1;
		for(auto [v,w]:G[u])
		{
			if(v==f) continue;
			dfs1(v,u),siz[u]+=siz[v];
			if(siz[v]>siz[son[u]]) son[u]=v;
		}
	}
	void dfs2(int u,int tp)
	{
		top[u]=tp,dfn[u]=++dfscnt,rev[dfscnt]=u;
		if(!son[u]) return ;
		dfs2(son[u],tp);
		for(auto [v,w]:G[u])
		{
			if(v==fa[u]||v==son[u]) continue;
			dfs2(v,v);
		}
	}
	void init() {dfs1(1,0),dfs2(1,1);}
	int jump(int u,int v)
	{
		while(dep[u]>dep[v]+1&&top[u]!=top[v])
		{
			if(u==top[u]) u=fa[u];
			else u=top[u];
		}
		if(dep[u]==dep[v]+1) return u;
		else return rev[dfn[v]+1];
	}
	#define ls (u<<1)
	#define rs (u<<1|1)
	#define mid ((l+r)/2)
	int t[N*4];
	void update(int u,int l,int r,int L,int R,int v)
	{
		if(L<=l&&r<=R) {t[u]=max(t[u],v); return ;}
		if(mid>=L) update(ls,l,mid,L,R,v);
		if(mid<R) update(rs,mid+1,r,L,R,v);
	}
	int query(int u,int l,int r,int pos)
	{
		if(l==r) return t[u];
		int ans=t[u];
		if(pos<=mid) return max(ans,query(ls,l,mid,pos));
		else return max(ans,query(rs,mid+1,r,pos));
	}
	#undef mid
	void fixnd(int u,int v)
	{
		u=fa[u];
		while(u)
		{
			update(1,1,n,dfn[top[u]],dfn[u],v);
			u=fa[top[u]];
		}
	}
	int qry(int u) {return query(1,1,n,dfn[u]);}
}hld;
int badtim=INF;
int qwqson[N];
void access(int u,int bt)
{
	for(int p=0;u;p=u,u=fa[u])
	{
		splay(u),ch[u][1]=p;
		int t=fa[u];
		if(t)
		{
			int tim=hld.qry(t),qwq=hld.jump(u,t);
			// printf("jump %lld %lld - %lld ** \n",u,t,qwq,las[t]);
			if(las[t]==qwq) continue;
			if(tim)
			{
				// printf("** %lld %lld\n",tim+dep[t]+1,bt+dep[t]);
				a[++m]=(Node){tim+dep[t]+1,bt+dep[t]};
			}
			else if(qwqson[t]!=qwq)
			{
				// printf("** %lld %lld\n",1,bt+dep[t]);
				a[++m]=(Node){1,bt+dep[t]};
			}
			// printf("^ %lld %lld %lld\n",t,las[t],u);
			las[t]=qwq;
		}
	}
}
void dfs1(int u,int f)
{
	fa[u]=f;
	for(auto [v,w]:G[u])
	{
		if(v==f) continue;
		qwqson[u]=v;
		dep[v]=dep[u]+w;
		dfs1(v,u);
	}
}
bool cmp(Node x,Node y) {return x.l<y.l||(x.l==y.l&&x.r<y.r);}
int tmp[N*140];
signed main()
{
	// cout<<sizeof(a)/1024.0/1024.0<<endl;
	cin>>n>>Q;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		G[u].eb(v,w),G[v].eb(u,w);
	}
	dfs1(1,0);
	hld.init();
	for(int i=1;i<=Q;i++)
	{
		int nd=read(),d=read();
		access(nd,d);
		hld.fixnd(nd,d);
	}
	sort(a+1,a+m+1,cmp);
	// for(int i=1;i<=m;i++) printf("%lld %lld\n",a[i].l,a[i].r);
	for(int i=1;i<=m;i++) if(a[i].l>a[i].r) badtim=min(badtim,a[i].r);
	int cnt=0;
	for(int i=1;i<=m;i++) tmp[++cnt]=a[i].l,tmp[++cnt]=a[i].r;
	sort(tmp+1,tmp+cnt+1); cnt=unique(tmp+1,tmp+cnt+1)-tmp-1;
	priority_queue<Node> q;
	int ans=0,cur=1;
	tmp[cnt+1]=INF;
	int endtim=INF;
	for(int i=1;i<=cnt;i++)
	{
		int curtim=tmp[i];
		while(cur<=m&&a[cur].l==tmp[i]) q.push(a[cur++]);
		// printf("^ %lld %lld\n",curtim,tmp[i]);
		while(curtim<tmp[i+1]&&!q.empty())
		{
			// printf("%lld ^ %lld %lld\n",curtim,q.top().l,q.top().r);
			ans++,q.pop();
			if((!q.empty()&&q.top().r<=curtim))
			{
				endtim=curtim;
				break;
			}
			curtim++;
		}
		if(endtim!=INF) break;
	}
	endtim=min(endtim,badtim);
	if(endtim==INF) printf("-1 %lld\n",ans);
	else
	{
		int res=0;
		for(int i=1;i<=m;i++) if(a[i].r<endtim) res++;
		printf("%lld %lld\n",endtim,res);
	}
	return 0;
}