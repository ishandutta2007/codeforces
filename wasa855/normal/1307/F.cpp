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
#define N 400005
vector<int> G[N];
int n,k,r,a[N];
struct Dsu
{
	int fa[N];
	void init() {for(int i=1;i<=n*2;i++) fa[i]=i;}
	int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
	void merge(int u,int v) {fa[find(u)]=find(v);}
}dsu;
int dep[N],fa[N],siz[N],son[N],top[N],st[N][20];
void dfs1(int u,int f)
{
	fa[u]=f,dep[u]=dep[f]+1,siz[u]=1;
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs1(v,u),siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int tp)
{
	top[u]=tp;
	if(!son[u]) return ;
	dfs2(son[u],tp);
	for(int v:G[u])
	{
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]]) u=fa[top[u]];
		else v=fa[top[v]];
	}
	if(dep[u]>dep[v]) return v;
	else return u;
}
int vis[N],cur;
void bfs()
{
	queue<pii> q;
	for(int i=1;i<=r;i++) q.emplace(a[i],0);
	while(!q.empty())
	{
		auto [u,dep]=q.front(); q.pop();
		for(int v:G[u])
		{
			if(dsu.find(v)==dsu.find(u)) continue;
			else if(dsu.find(v)) dsu.merge(v,u);
			else if(dep<k/2) dsu.fa[v]=dsu.find(u),q.emplace(v,dep+1);
		}
	}
	// for(int i=1;i<=n*2-1;i++) printf("%d%c",dsu.find(i)," \n"[i==n*2-1]);
}
int jump(int u,int v)
{
	for(int i=0;i<20;i++) if(v>>i&1) u=st[u][i];
	return u;
}
int jump(int u,int v,int L,int d)
{
	if(dep[u]-dep[L]>=d) return jump(u,d);
	else return jump(v,dep[u]+dep[v]-dep[L]-dep[L]-d);
}
signed main()
{
	cin>>n>>k>>r; k*=2;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(i+n),G[i+n].pb(u);
		G[v].pb(i+n),G[i+n].pb(v);
		// printf("%d %d\n",u,i+n);
		// printf("%d %d\n",v,i+n);
	}
	dfs1(1,0),dfs2(1,1);
	int m=n*2-1;
	for(int i=1;i<=m;i++) st[i][0]=fa[i];
	for(int i=1;i<20;i++) for(int j=1;j<=m;j++) st[j][i]=st[st[j][i-1]][i-1];
	for(int i=1;i<=r;i++) a[i]=read(),dsu.fa[a[i]]=a[i];
	bfs();
	// for(int i=1;i<=n*2-1;i++) printf("%d%c",dsu.find(i)," \n"[i==n*2-1]);
	int Q=read();
	while(Q--)
	{
		int u=read(),v=read(),L=lca(u,v);
		if(dep[u]+dep[v]-dep[L]-dep[L]<=k) printf("YES\n");
		else
		{
			int A=jump(u,v,L,k/2),B=jump(v,u,L,k/2);
			// printf("%d %d - %d %d\n",u,v,A,B);
			if(dsu.find(A)&&dsu.find(A)==dsu.find(B)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}