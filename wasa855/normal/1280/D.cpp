#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
#define N 3005
#define INF 1e18 
typedef pair<int,int> pii;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
int a[N],siz[N];
pii f[N][N];
pii operator + (pii x,pii y)
{
	return mp(x.first+y.first,x.second+y.second);
}
vector<int> G[N];
void dfs(int u,int fa)
{
	siz[u]=1,f[u][0]=mp(0,a[u]);
	for(int v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		for(int i=siz[u];i>=0;i--)
		{
			for(int j=siz[v];j>=1;j--)
			{
				f[u][i+j]=max(f[u][i+j],f[u][i]+f[v][j]);
			}
			f[u][i]=f[u][i]+f[v][0];
		}
		siz[u]+=siz[v];
	}
	if(u!=1)
	{
		for(int i=siz[u];i>=0;i--)
		{
			f[u][i+1]=max(f[u][i+1],mp(f[u][i].first+(bool)(f[u][i].second>0),0LL));
		}
	}
}
void work()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) a[i]=read()-a[i];
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++) f[i][j]=mp(0,-INF);
	}
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,0);
	cout<<f[1][m-1].first+(bool)(f[1][m-1].second>0)<<endl;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//