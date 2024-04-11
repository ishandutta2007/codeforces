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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 3005
int a[N][N];
int x[N*N/4],y[N*N/4];
int n,fa[N],siz[N],sum[N],h[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
vector<int> G[N];
int f[N][N],g[N];
void dfs(int u)
{
	siz[u]=1;
	if(G[u].empty())
	{
		f[u][1]=1;
		return ;
	}
	f[u][0]=1;
	for(int v:G[u])
	{
		dfs(v);
		for(int i=0;i<=siz[u]+siz[v];i++)
		{
			g[i]=0;
			for(int j=0;j<=siz[u];j++) g[i]=add(g[i],mul(f[u][j],f[v][i-j]));
		}
		for(int i=0;i<=siz[u]+siz[v];i++) f[u][i]=g[i];
		siz[u]+=siz[v];
	}
	if(h[u]) f[u][1]=add(f[u][1],1);
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=read();
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			x[a[i][j]]=i,y[a[i][j]]=j;
		}
	}
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1,h[i]=1;
	int cnt=n;
	for(int i=1;i<=n*(n-1)/2;i++)
	{
		int u=find(x[i]),v=find(y[i]);
		if(u==v)
		{
			sum[u]++;
			if(siz[u]*(siz[u]-1)/2==sum[u]) h[u]=1;
		}
		else
		{
			int x=++cnt; fa[x]=x;
			fa[u]=fa[v]=x;
			siz[x]=siz[u]+siz[v];
			sum[x]=sum[u]+sum[v]+1;
			G[x]={u,v};
			if(siz[x]*(siz[x]-1)/2==sum[x]) h[x]=1;
		}
	}
	dfs(cnt);
	// for(int i=n+1;i<=cnt;i++)
	// {
		// printf("%d %d : ",i,h[i]);
		// print(G[i]);
	// }
	for(int i=1;i<=n;i++) printf("%d%c",f[cnt][i]," \n"[i==n]);
	return 0;
}