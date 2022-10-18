#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
#define N 200005
vector<int> G[N];
int w[N],siz[N],dep[N];
void dfs(int u,int fa)
{
	siz[u]=1; dep[u]=dep[fa]+1;
	for(int v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
	w[u]=dep[u]-siz[u];
}
signed main()
{
	int n=read(),k=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,0);
	sort(w+1,w+n+1,greater<int>());
	ll ans=0;
	for(int i=1;i<=k;i++) ans+=w[i];
	cout<<ans<<endl;
	return 0;
}