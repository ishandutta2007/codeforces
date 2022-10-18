#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 3005
int rt,n;
int p[N][N],siz[N][N];
int f[N][N];
vector<int> G[N];
void init(int u)
{
	siz[rt][u]=1;
	for(int v:G[u])
	{
		if(v!=p[rt][u])
		{
			p[rt][v]=u;
			init(v);
			siz[rt][u]+=siz[rt][v];
		}
	}
}
int dp(int u,int v)
{
	if(u==v) return 0;
	if(f[u][v]) return f[u][v];
	return f[u][v]=max(dp(u,p[u][v]),dp(p[v][u],v))+siz[u][v]*siz[v][u];
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	for(int i=1;i<=n;i++)
	{
		rt=i;
		init(i);
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans=max(ans,dp(i,j));
		}
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}