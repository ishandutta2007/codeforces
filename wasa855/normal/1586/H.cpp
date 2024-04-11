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
#define N 200005
struct Edge{int u,v,c,w;};
Edge edge[N];
struct Query{int u,c,id;};
Query q[N];
vector<pii> G[N];
int n,Q,val[N];
int fw[N],fa[N],siz[N],son[N],top[N],dep[N],dfn[N],rev[N],dfscnt;
void dfs1(int u,int f)
{
	fa[u]=f,siz[u]=1,dep[u]=dep[f]+1;
	for(auto [v,w]:G[u])
	{
		if(v==f) continue;
		fw[v]=w;
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
int st[N][20],lg[N];
pii ans[N];
int qry(int l,int r)
{
	int t=lg[r-l+1];
	return max(st[l][t],st[r-(1<<t)+1][t]);
}
int query(int u,int v)
{
	// printf("%d %d : ",u,v);
	int ans=0;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]]) ans=max(ans,qry(dfn[top[u]],dfn[u])),u=fa[top[u]];
		else ans=max(ans,qry(dfn[top[v]],dfn[v])),v=fa[top[v]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	if(u!=v) ans=max(ans,qry(dfn[v]+1,dfn[u]));
	// printf("%d\n",ans);
	return ans;
}
struct Dsu
{
	int fa[N],mxid[N],mxw[N],res[N];
	int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
	void init() {for(int i=1;i<=n;i++) fa[i]=i,mxid[i]=i,mxw[i]=val[i];}
	void merge(int u,int v)
	{
		u=find(u),v=find(v),fa[u]=v;
		// printf("^ %d %d * %d %d %d * %d %d %d\n",u,v,mxid[u],mxw[u],res[u],mxid[v],mxw[v],res[v]);
		if(mxw[u]>mxw[v]) mxw[v]=mxw[u],mxid[v]=mxid[u],res[v]=res[u];
		else if(mxw[u]==mxw[v]) res[v]=max({res[v],res[u],::query(mxid[u],mxid[v])});
		// printf("^^ %d\n",res[v]);
	}
	pii query(int u)
	{
		int f=find(u);
		return {mxw[f],max(res[f],::query(u,mxid[f]))};
	}
}dsu;
signed main()
{
	for(int i=2;i<N;i++) lg[i]=lg[i/2]+1;
	cin>>n>>Q;
	for(int i=1;i<=n;i++) val[i]=read();
	for(int i=1;i<n;i++)
	{
		edge[i].u=read(),edge[i].v=read(),edge[i].c=read(),edge[i].w=read();
		G[edge[i].u].eb(edge[i].v,edge[i].w);
		G[edge[i].v].eb(edge[i].u,edge[i].w);
	}
	sort(edge+1,edge+n,[&](Edge x,Edge y){return x.c>y.c;});
	for(int i=1;i<=Q;i++) q[i].c=read(),q[i].u=read(),q[i].id=i;
	sort(q+1,q+Q+1,[&](Query x,Query y){return x.c>y.c;});
	dfs1(1,0),dfs2(1,1);
	for(int i=1;i<=n;i++) st[i][0]=fw[rev[i]];
	// for(int i=1;i<=n;i++) printf("%d%c",st[i][0]," \n"[i==n]);
	for(int i=1;i<=18;i++) for(int j=1;j+(1<<i)-1<=n;j++) st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
	// cout<<query(1,3)<<endl;
	dsu.init();
	int cur=1;
	for(int i=1;i<=Q;i++)
	{
		while(cur<n&&edge[cur].c>=q[i].c) dsu.merge(edge[cur].u,edge[cur].v),cur++;
		ans[q[i].id]=dsu.query(q[i].u);
	}
	for(int i=1;i<=Q;i++) printf("%d %d\n",ans[i].fir,ans[i].sec);
	return 0;
}