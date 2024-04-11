#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 5005
vector<int> G[N];
int n,m;
int w[N],d[N];
int f[N][N][2];
int siz[N];
void dfs(int u)
{
	siz[u]=1;
	f[u][0][0]=0;
	f[u][1][0]=w[u];
	f[u][1][1]=w[u]-d[u];
	for(int v:G[u])
	{
		dfs(v);
		for(int i=siz[u];i>=0;i--)
		{
			for(int j=0;j<=siz[v];j++)
			{
				if(f[v][j][0]+f[u][i][1]<f[u][i+j][1]) f[u][i+j][1]=f[v][j][0]+f[u][i][1];
				if(f[v][j][1]+f[u][i][1]<f[u][i+j][1]) f[u][i+j][1]=f[v][j][1]+f[u][i][1];
				if(f[v][j][0]+f[u][i][0]<f[u][i+j][0]) f[u][i+j][0]=f[v][j][0]+f[u][i][0];
			}
		}
		siz[u]+=siz[v];
	}
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	memset(f,0x3f,sizeof(f));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		w[i]=read(),d[i]=read();
		if(i>1)
		{
			int u=read();
			G[u].pb(i);
		}
	}
	dfs(1);
	int ans=0;
//	cout<<f[1][1][1]<<endl;
	for(int i=1;i<=n;i++)
	{
		if(f[1][i][1]<=m) ans=i; 
		if(f[1][i][0]<=m) ans=i; 
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}