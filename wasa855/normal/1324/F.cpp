#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define INF 0x3fffffff
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 200005
vector<int> G[N];
int n;
int f[N],g[N],h[N],w[N];
void dfs1(int u,int fa)
{
	f[u]=w[u];
	for(int v:G[u])
	{
		if(v==fa) continue;
		dfs1(v,u);
		f[u]+=g[v];
	}
	g[u]=max(0,f[u]);
}
void dfs2(int u,int fa)
{
	if(fa!=0) h[u]=max(0,h[fa]-g[u])+f[u];
	else h[u]=f[u];
	for(int v:G[u])
	{
		if(v==fa) continue;
		dfs2(v,u);
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) w[i]=read();
	for(int i=1;i<=n;i++) if(w[i]==0) w[i]=-1;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,0),dfs2(1,0);
	for(int i=1;i<=n;i++) printf("%d ",h[i]);
	return 0;
}
////