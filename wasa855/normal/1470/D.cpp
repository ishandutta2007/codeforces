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
#define N 300005
int fa[N],vis[N],col[N];
int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
vector<int> G[N],H[N];
void dfs(int u,int f)
{
	vis[u]=1;
	for(int i=0;i<(int)G[u].size();i++)
	{
		int v=G[u][i];
		if(v==f) H[u][i]=1;
		else if(!vis[v]) dfs(v,u),H[u][i]=1;
	}
}
void dfs2(int u,int f)
{
	bool ok=0;
	for(int v:G[u]) ok|=col[v];
	if(!ok) col[u]=1;
	for(int i=0;i<(int)G[u].size();i++)
	{
		if(G[u][i]!=f&&H[u][i]==1) dfs2(G[u][i],u);
	}
}
void work()
{
	int n=read(),m=read();
	for(int i=1;i<=n;i++) fa[i]=i,vis[i]=col[i]=0;
	for(int i=1;i<=n;i++) G[i].clear(),H[i].clear();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		fa[find(u)]=find(v);
		G[u].pb(v),G[v].pb(u);
		H[u].pb(0),H[v].pb(0);
	}
	for(int i=2;i<=n;i++) if(find(i)!=find(1))
	{
		cout<<"NO\n";
		return ;
	}
	dfs(1,0),dfs2(1,0);
	int sum=0; for(int i=1;i<=n;i++) sum+=col[i];
	cout<<"YES\n";
	cout<<sum<<"\n";
	for(int i=1;i<=n;i++) if(col[i]) printf("%d ",i);
	cout<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}