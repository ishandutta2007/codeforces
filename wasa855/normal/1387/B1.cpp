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
#define N 100005
vector<int> G[N];
int p[N],vis[N],id[N],a[N],b[N],c[N],f[N];
int ans=0,cnt=0;
void dfs(int u,int fa)
{
	f[u]=fa;
	for(int v:G[u])
	{
		if(v==fa) continue;
		dfs(v,u);
	}
	if(fa&&!vis[u]&&!vis[fa])
	{
		vis[u]=fa,vis[fa]=u;
		ans+=2;
		cnt++; id[u]=id[fa]=cnt;
		a[cnt]=u,b[cnt]=fa;
		p[fa]=u,p[u]=fa;
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
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			int x=f[i];
			if(!x)
			{
				for(int v:G[i]) if(vis[v]) {x=v; break;}
			}
			int y=vis[x];
			if(x!=a[id[x]]) swap(x,y);
			// printf("%d %d %d\n",x,y,i);
			ans+=2;
			if(!c[id[x]])
			{
				p[x]=y,p[y]=i,p[i]=x;
				c[id[x]]=i;
			}
			else
			{
				p[c[id[x]]]=i,p[i]=x,c[id[x]]=i;
			}
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) printf("%d ",p[i]);
	return 0;
}