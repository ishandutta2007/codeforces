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
#define N 250005
vector<int> G[N];
vector<int> H[N];
int dep[N],fa[N][20],n;
struct Dsu
{
	int fa[N];
	int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
	void merge(int u,int v) {fa[find(u)]=find(v);}
	void init() {for(int i=1;i<=n;i++) fa[i]=i;}
}dsu;
int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	int go=dep[u]-dep[v];
	for(int j=0;j<19;j++) if(go>>j&1) u=fa[u][j];
	if(u==v) return u;
	for(int i=18;i>=0;i--)
	{
		if(fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
	}
	return fa[u][0];
}
void dfs2(int u,int f)
{
	fa[u][0]=f,dep[u]=dep[f]+1;
	for(int j=1;j<19;j++) fa[u][j]=fa[fa[u][j-1]][j-1];
	for(int v:H[u]) if(v!=f) dfs2(v,u);
}
int jump(int u,int v,int d)
{
	for(int i=18;i>=0;i--)
	{
		if(dep[u]-(1<<i)>d&&dsu.find(fa[u][i])!=dsu.find(v)) u=fa[u][i];
	}
	return u;
}
void dfs1(int u,int f)
{
	for(int v:G[u]) if(v!=f) dfs1(v,u);
	if(!f) return ;
	int L=lca(u,f);
	if(dsu.find(u)!=dsu.find(L))
	{
		int res=dsu.find(u);
		printf("%d %d %d %d\n",res,fa[res][0],u,f);
		dsu.merge(res,fa[res][0]);
	}
	else
	{
		int res=jump(f,dsu.find(u),dep[L]);
		printf("%d %d %d %d\n",res,fa[res][0],u,f);
		dsu.merge(res,fa[res][0]);
	}
}
signed main()
{
	n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		H[u].pb(v),H[v].pb(u);
	}
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dsu.init();
	cout<<n-1<<endl;
	dfs2(1,0);
	dfs1(1,0);
	return 0;
}