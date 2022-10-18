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
#define N 200005
vector<int> G[N];
int a[N],sum[N],b[N],n;
bool vis[N];
vector<int> ans;
int res=0;
void dfs1(int u)
{
	sum[u]=a[u];
	for(int v:G[u])
	{
		dfs1(v);
		if(sum[v]>0) sum[u]+=sum[v];
	}
}
void dfs2(int u)
{
	for(int v:G[u])
	{
		if(sum[v]>0) dfs2(v);
	}
	ans.pb(u);
	res+=sum[u];
	for(int v:G[u])
	{
		if(sum[v]<=0) dfs2(v);
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++)
	{
		b[i]=read();
		if(b[i]!=-1) G[b[i]].pb(i);
	}
	for(int i=1;i<=n;i++) if(b[i]==-1) dfs1(i);
	for(int i=1;i<=n;i++) if(b[i]==-1) dfs2(i);
	cout<<res<<endl;
	for(int i:ans)  printf("%d ",i);
	return 0;
}