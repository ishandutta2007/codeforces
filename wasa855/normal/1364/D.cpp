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
int dep[N],vis[N],fa[N];
void dfs(int u,int f)
{
	vis[u]=1;
	dep[u]=dep[f]+1; fa[u]=f;
	for(int v:G[u])
	{
		if(v==f) continue;
		if(vis[v])
		{
			vector<int> ans;
			int tmp=u;
			while(tmp!=v) ans.pb(tmp),tmp=fa[tmp];
			ans.pb(v);
			cout<<2<<endl<<ans.size()<<endl;
			for(int i:ans) printf("%d ",i);
			exit(0);
		}
		dfs(v,u);
	}
}
signed main()
{
	int n,k,m;
	cin>>n>>m>>k; n=k;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if(u<=n&&v<=n) G[u].pb(v),G[v].pb(u);
	}
	for(int i=1;i<=n;i++) if(!vis[i]) dfs(i,0);
	vector<int> ans[2];
	for(int i=1;i<=n;i++) ans[dep[i]&1].pb(i);
	cout<<1<<endl;
	if(ans[0].size()>=(k+1)/2) for(int i=0;i<(k+1)/2;i++) printf("%d ",ans[0][i]);
	else for(int i=0;i<(k+1)/2;i++) printf("%d ",ans[1][i]);
	return 0;
}