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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 300005
vector<int> G[N];
int a[N],dep[N],rev[N],fa[N],n,cur;
ll ans;
int dfn[N],out[N],dfscnt,outcnt,cnt;
void dfs(int u)
{
	dep[u]=dep[fa[u]]+1,dfn[u]=++dfscnt;
	if(a[u]>=cur)
	{
		if(cnt+cur!=a[u]) cout<<"NO\n",exit(0);
		cnt++;
	}
	for(int v:G[u]) dfs(v);
	outcnt++; out[u]=outcnt;
	if(a[u]<cur&&a[u]!=outcnt) cout<<"NO\n",exit(0);
	if(a[u]<cur) ans+=dep[u];
}
signed main()
{
	cin>>n; dep[0]=-1;
	for(int i=1;i<=n;i++) a[i]=read(),rev[a[i]]=i;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		fa[v]=u,G[u].pb(v);
	}
	for(int i=1;i<=n;i++) sort(G[i].begin(),G[i].end(),[&](int x,int y){return a[x]<a[y];});
	int _nd;
	if(a[1]!=1)
	{
		cur=a[1]-1; int nd=rev[cur]; _nd=nd;
		while(nd>1)
		{
			int u=nd,v=fa[nd];
			swap(a[u],a[v]);
			swap(rev[a[u]],rev[a[v]]);
			nd=fa[nd],ans++;
		}
	}
	else cur=1,_nd=rev[1];
	dfs(1);
	for(int i=1;i<=n;i++) if(out[i]==cur)
	{
		if(dfn[i]<dfn[_nd]||out[i]>out[_nd]) cout<<"NO\n",exit(0);
	}
	cout<<"YES\n";
	cout<<ans<<endl;
	for(int i=1;i<=n;i++) printf("%d%c",dfn[i]," \n"[i==n]);
	return 0;
}