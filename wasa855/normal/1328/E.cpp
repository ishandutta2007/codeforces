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
#define N 200005
vector<int> G[N];
int dep[N],fa[N],siz[N],dfn[N],_cnt;
int a[N];
bool cmp(int x,int y)
{
	return dep[x]<dep[y];
}
void dfs(int u,int Fa)
{
	fa[u]=Fa,dfn[u]=++_cnt,siz[u]=1,dep[u]=dep[Fa]+1;
	for(int v:G[u])
	{
		if(v==Fa) continue;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}
bool son(int u,int v)
{
	return dfn[v]>=dfn[u]&&dfn[v]<=dfn[u]+siz[u]-1;
}
signed main()
{
	int n,Q;
	cin>>n>>Q;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,1);
	// for(int i=1;i<=n;i++) printf("%d ",dfn[i]); cout<<"\n";
	while(Q--)
	{
		int m=read();
		for(int i=1;i<=m;i++) a[i]=fa[read()];
		sort(a+1,a+m+1,cmp);
		// for(int i=1;i<=m;i++) printf("%d ",a[i]); cout<<"\n";
		bool ok=1;
		for(int i=1;i<m;i++)
		{
			ok&=son(a[i],a[i+1]);
		}
		printf("%s\n",ok?"YES":"NO");
	}
	return 0;
}