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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
vector<int> G[N];
int siz[N],fa[N],dep[N],son[N],top[N],dfn[N],dfscnt,n,m;
void dfs1(int u,int f)
{
	fa[u]=f,siz[u]=1,dep[u]=dep[f]+1;
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs1(v,u),siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int tp)
{
	top[u]=tp,dfn[u]=++dfscnt;
	if(!son[u]) return ;
	dfs2(son[u],tp);
	for(int v:G[u])
	{
		if(v==son[u]||v==fa[u]) continue;
		dfs2(v,v);
	}
}
vector<int> nds[N*4];
struct Edge{int v,nxt;};
Edge edge[N*160];
int fir[N*80],ss,cnt;
void add(int u,int v)
{
	// printf("%d %d\n",u,v);
	edge[++ss]=(Edge){v,fir[u]}; fir[u]=ss;
	edge[++ss]=(Edge){u^1,fir[v^1]}; fir[v^1]=ss;
}
#define ls (u<<1)
#define rs (u<<1|1)
#define mid ((l+r)/2)
void insert(int u,int l,int r,int L,int R,int w)
{
	assert(L<=R);
	if(L<=l&&r<=R) {nds[u].pb(w); return ;}
	if(mid>=L) insert(ls,l,mid,L,R,w);
	if(mid<R) insert(rs,mid+1,r,L,R,w);
}
void solve(int u,int l,int r,int fa)
{
	int tu=++cnt; cnt+=(int)nds[u].size(); int go=cnt;
	if(!nds[u].empty()) add((go-1)*2,go*2);
	else if(fa) add(fa*2,go*2);
	for(int i=0;i<(int)nds[u].size();i++)
	{
		int v=nds[u][i]; add(v,(tu+i)*2);
		if(i) add((tu+i-1)*2,(tu+i)*2),add((tu+i-1)*2,v^1);
		else if(fa) add(fa*2,tu*2),add(fa*2,v^1);
	}
	/*
	int go=0;
	for(int i=0;i<(int)nds[u].size();i++) for(int j=i+1;j<(int)nds[u].size();j++) add(nds[u][i],nds[u][j]^1);
	*/
	if(l==r) return ;
	solve(ls,l,mid,go),solve(rs,mid+1,r,go);
}
#undef mid
void get(int u,int v,int w)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]]) insert(1,1,n,dfn[top[u]],dfn[u],w),u=fa[top[u]];
		else insert(1,1,n,dfn[top[v]],dfn[v],w),v=fa[top[v]];
	}
	// printf("%d %d\n",u,v);
	if(dep[u]>dep[v]) swap(u,v);
	if(u!=v) insert(1,1,n,dfn[u]+1,dfn[v],w);
}
namespace N1
{
	int low[N*80],dfn[N*80],st[N*80],vis[N*80],bel[N*80],tp,dfscnt,comcnt;
	void tarjan(int u)
	{
		low[u]=dfn[u]=++dfscnt,vis[u]=1,st[++tp]=u;
		for(int i=fir[u];i!=0;i=edge[i].nxt)
		{
			int v=edge[i].v;
			if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
			else if(vis[v]) low[u]=min(low[u],dfn[v]);
		}
		if(low[u]==dfn[u])
		{
			++comcnt;
			while(1)
			{
				int tmp=st[tp--];
				bel[tmp]=comcnt,vis[tmp]=0;
				if(tmp==u) break;
			}
		}
	}
	void print()
	{
		// for(int i=1;i<=cnt*2+1;i++)
		// {
			// for(int j=fir[i];j!=0;j=edge[j].nxt) printf("%d ",edge[j].v);
			// cout<<"\n";
		// }
		// for(int i=1;i<=m;i++) printf("^ %d %d\n",bel[i*2],bel[i*2+1]);
		for(int i=1;i<=m;i++) if(bel[i*2]==bel[i*2+1]) cout<<"NO\n",exit(0);
		cout<<"YES\n";
		for(int i=1;i<=m;i++) printf("%d\n",(bel[i*2]>bel[i*2+1])+1);
	}
	void solve()
	{
		for(int i=1;i<=cnt*2+1;i++) if(!dfn[i]) tarjan(i),assert(!tp);
		print();
	}
};
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,0),dfs2(1,1);
	// for(int i=1;i<=n;i++) printf("%d%c",top[i]," \n"[i==n]);
	cin>>m; cnt=m;
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();
		get(a,b,i*2);
		a=read(),b=read();
		get(a,b,i*2+1);
	}
	solve(1,1,n,0);
	N1::solve();
	return 0;
}