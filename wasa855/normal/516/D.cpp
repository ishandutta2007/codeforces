#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
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
#define N 100005
struct Edge{int v,w;};
vector<Edge> G[N];
int n,Q,rt,dis[N],f[N];
void dfs(int u,int fa)
{
	for(Edge v:G[u])
	{
		if(v.v==fa) continue;
		dis[v.v]=dis[u]+v.w;
		if(dis[v.v]>f[v.v]) f[v.v]=dis[v.v];
		if(dis[v.v]>dis[rt]) rt=v.v;
		dfs(v.v,u);
	}
}
int fa[N],a[N],vis[N],siz[N];
int find(int u){return fa[u]==u?u:fa[u]=find(fa[u]);}
bool cmp(int x,int y){return f[x]>f[y];}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read(),w=read();
		G[u].pb((Edge){v,w});
		G[v].pb((Edge){u,w});
	}
	dfs(1,0);
	dis[rt]=0; dfs(rt,0);
	dis[rt]=0; dfs(rt,0);
	// for(int i=1;i<=n;i++) printf("%lld ",f[i]); cout<<"\n";
	for(int i=1;i<=n;i++) a[i]=i;
	sort(a+1,a+n+1,cmp);
	// for(int i=1;i<=n;i++) printf("%d ",a[i]); cout<<"\n";
	Q=read();
	while(Q--)
	{
		int x=read(),ans=0;
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++) siz[i]=1;
		int cur=1;
		for(int i=1;i<=n;i++)
		{
			// printf("%d :\n",i);
			while(f[a[cur]]-f[a[i]]>x)
			{
				siz[find(a[cur])]--; cur++;
			}
			// printf("%d %d\n",i,cur);
			vis[a[i]]=1;
			for(Edge v:G[a[i]])
			{
				if(vis[v.v]) siz[find(a[i])]+=siz[find(v.v)],fa[find(v.v)]=find(a[i]);
			}
			// for(int i=1;i<=n;i++) printf("%d ",siz[i]); cout<<"\n";
			if(siz[find(a[i])]>ans) ans=siz[find(a[i])];
		}
		printf("%lld\n",ans);
	}
	return 0;
}