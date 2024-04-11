#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 200005
vector<int> G[N];
int a[N],b[N],w[N];
int siz[N][2];
int ans;
void dfs(int u,int fa,int minn)
{
	if(a[u]!=b[u])
	{
		if(a[u]==0) siz[u][0]++;
		else siz[u][1]++;
	}
	for(int v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u,min(minn,w[v]));
		siz[u][0]+=siz[v][0];
		siz[u][1]+=siz[v][1];
	}
	if(w[u]==minn)
	{
		int r=min(siz[u][0],siz[u][1]);
		// printf("%d %d\n",u,r);
		ans+=2*r*w[u];
		siz[u][0]-=r,siz[u][1]-=r;
	}
}
signed main()
{
	int n=read();
	int c1=0,c2=0;
	for(int i=1;i<=n;i++)
	{
		w[i]=read(),a[i]=read(),b[i]=read();
		if(a[i]==0) c1++;
		if(b[i]==0) c2++;
	}
	if(c1!=c2)
	{
		cout<<"-1\n";
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,0,w[1]);
	cout<<ans<<endl;
	return 0;
}