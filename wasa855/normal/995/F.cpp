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
#define mod 1000000007
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
int qpow(int x,int y)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x);
		x=mul(x,x);
		y>>=1;
	}
	return ans;
}
int Inv(int x){return qpow(x,mod-2);}
#define N 5055
int f[N][N],g[N][N],fa[N],n,m=5050,D;
vector<int> G[N];
int fac[N],inv[N],pinv[N];
void init()
{
	fac[0]=1; for(int i=1;i<N;i++) fac[i]=mul(fac[i-1],i);
	inv[0]=inv[1]=1; for(int i=2;i<N;i++) inv[i]=mul(mod-mod/i,inv[mod%i]);
	pinv[0]=1; for(int i=1;i<N;i++) pinv[i]=mul(pinv[i-1],inv[i]);
}
void dfs(int u)
{
	for(int v:G[u]) dfs(v);
	for(int i=1;i<=m;i++)
	{
		f[u][i]=1;
		for(int v:G[u]) f[u][i]=mul(f[u][i],g[v][i]);
	}
	for(int i=1;i<=m;i++) g[u][i]=add(g[u][i-1],f[u][i]);
}
signed main()
{
	n=read(),D=read(); init();
	for(int i=2;i<=n;i++)
	{
		int u=read(); G[u].pb(i);
	}
	dfs(1);
	if(D<=m)
	{
		printf("%d\n",g[1][D]);
		return 0;
	}
	int prd=1,ans=0;
	for(int i=1;i<=m;i++) prd=mul(prd,D-i);
	for(int i=1;i<=m;i++)
	{
		int cur=mul(prd,Inv(D-i),g[1][i]);
		int x=mul(pinv[i-1],pinv[m-i]);
		if((m-i)&1) x=sub(0,x);
		ans=add(ans,mul(cur,x));
	}
	cout<<ans<<endl;
	return 0;
}