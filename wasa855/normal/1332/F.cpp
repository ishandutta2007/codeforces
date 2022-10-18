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
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
#define N 300005
vector<int> G[N];
int n,f[N][3];
void dfs(int u,int fa)
{
	f[u][0]=1;
	for(int v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u);
		int U=mul(add(f[u][2],f[u][0]),add(add(f[v][2],f[v][1]),add(f[v][0],f[v][0])));
		int V=mul(f[u][2],add(add(f[v][2],f[v][1]),f[v][0]));
		f[u][2]=add(U,V);
		U=mul(add(f[u][1],f[u][0]),add(f[v][2],f[v][0]));
		V=mul(f[u][1],add(add(f[v][2],f[v][1]),f[v][0]));
		f[u][1]=add(U,V);
		f[u][0]=mul(f[u][0],add(add(f[v][2],f[v][1]),f[v][0]));
	}
}
signed main()
{
	int n=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,0);
	int ans=add(f[1][0],add(f[1][1],f[1][2]));
	cout<<sub(ans,1)<<endl;
	return 0;
}