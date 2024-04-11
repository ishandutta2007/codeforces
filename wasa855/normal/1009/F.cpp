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
#define N 1000005
vector<int> G[N];
int n,fa[N],len[N],son[N],ans[N];
int f[N],_[N],*g=_;
void dfs1(int u,int f)
{
	fa[u]=f;
	for(int i=0;i<(int)G[u].size();i++)
	{
		int v=G[u][i];
		if(v==f) continue;
		dfs1(v,u);
		if(len[v]>len[u]) son[u]=v,len[u]=len[v];
	}
	len[u]++;
}
void dfs2(int u,int *f)
{
	if(!son[u]) {f[0]=1,ans[u]=0; return ;}
	dfs2(son[u],f+1); f[0]=1; ans[u]=ans[son[u]]+1;
	if(f[ans[u]]==1) ans[u]=0;
	for(int i=0;i<(int)G[u].size();i++)
	{
		int v=G[u][i];
		if(v==fa[u]||v==son[u]) continue;
		int *tmp=g; g+=len[v];
		dfs2(v,tmp);
		for(int j=1;j<=len[v];j++)
		{
			f[j]+=tmp[j-1];
			if(f[j]>f[ans[u]]||(f[j]==f[ans[u]]&&j<ans[u])) ans[u]=j;
		}
		for(int j=0;j<len[v];j++) g[j]=0;
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,0),dfs2(1,f);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}