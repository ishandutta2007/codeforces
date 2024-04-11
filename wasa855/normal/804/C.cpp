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
#define N 300005
vector<int> G[N],c[N];
int s[N],col[N];
void dfs(int u,int fa)
{
	if(fa==-1)
	{
		for(int i=0;i<(int)c[u].size();i++) col[c[u][i]]=i+1;
	}
	else
	{
		vector<int> vis;
		for(int i:c[u]) if(col[i]) vis.pb(col[i]);
		sort(vis.begin(),vis.end());
		int cur=0,tmp=1;
		for(int i:c[u])
		{
			if(col[i]) continue;
			while(cur<(int)vis.size()&&vis[cur]==tmp) cur++,tmp++;
			col[i]=tmp; tmp++;
		}
	}
	for(int v:G[u]) if(v!=fa) dfs(v,u);
}
signed main()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		s[i]=read();
		c[i].resize(s[i]);
		for(int &j:c[i]) j=read();
	}
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,-1);
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		if(!col[i]) col[i]=1;
		if(col[i]>ans) ans=col[i];
	}
	cout<<ans<<endl;
	for(int i=1;i<=m;i++) printf("%d ",col[i]);
	return 0;
}