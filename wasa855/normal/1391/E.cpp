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
#define N 500005
vector<int> G[N];
vector<int> qaq[N];
int n,m;
int dep[N],fa[N];
void dfs(int u,int f)
{
	dep[u]=dep[f]+1; fa[u]=f;
	for(int v:G[u])
	{
		if(v==f) continue;
		if(!dep[v]) dfs(v,u);
	}
}
void work()
{
	cin>>n>>m;
	int ned=(n+1)/2;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,0);
	int maxn=1;
	for(int i=1;i<=n;i++) if(dep[i]>dep[maxn]) maxn=i;
	if(dep[maxn]>=ned)
	{
		cout<<"PATH\n";
		cout<<dep[maxn]<<"\n";
		int tmp=maxn;
		while(tmp!=1) printf("%d ",tmp),tmp=fa[tmp];
		cout<<"1\n";
	}
	else
	{
		vector<pii> ans;
		for(int i=1;i<=n;i++) qaq[dep[i]].pb(i);
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j+1<(int)qaq[i].size();j+=2)
			{
				ans.eb(qaq[i][j],qaq[i][j+1]);
			}
		}
		cout<<"PAIRING\n";
		cout<<ans.size()<<"\n";
		for(auto [x,y]:ans) printf("%d %d\n",x,y);
	}
	for(int i=1;i<=n;i++) G[i].clear(),qaq[i].clear();
	for(int i=1;i<=n;i++) dep[i]=0;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}