#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rnd(15381);
int Rnd(int l,int r) {return rnd()%(r-l+1)+l;}
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
#define N 200005
vector<int> G[N];
int n,m,dep[N],fa[N],dfn[N],ofn[N],siz[N],dfscnt;
void dfs1(int u,int f)
{
	fa[u]=f,dfn[u]=++dfscnt,siz[u]=1;
	for(int v:G[u])
	{
		if(!dfn[v]) dfs1(v,u),siz[u]+=siz[v];
	}
	ofn[u]=dfscnt;
}
int chk(int u)
{
	for(int i=1;i<=n;i++) dfn[i]=0;
	fa[u]=0,dfscnt=0;
	dfs1(u,0);
	for(int i=1;i<=n;i++) for(int v:G[i]) if(fa[v]!=i)
	{
		if(dfn[v]>dfn[i]||ofn[v]<ofn[i]) return 0;
	}
	return 1;
}
struct CMP
{
	bool operator () (const int &x,const int &y) const {return dep[x]>dep[y];}
};
multiset<int,CMP> s[N];
int ok[N];
void merge(int u,int v)
{
	if(s[u].size()<s[v].size()) swap(s[u],s[v]);
	for(int i:s[v]) s[u].insert(i);
}
void dfs2(int u,int f)
{
	dfn[u]=++dfscnt,dep[u]=dep[f]+1;
	for(int v:G[u])
	{
		if(!dfn[v]) dfs2(v,u),merge(u,v);
		else s[u].insert(v);
	}
	while(*s[u].begin()==u) s[u].erase(s[u].begin());
	if(s[u].size()>1) fa[u]=0;
	else if(s[u].size()==1) fa[u]=*s[u].begin();
}
void dfs3(int u,int f)
{
	if(fa[u]) ok[u]=ok[fa[u]];
	dfn[u]=++dfscnt;
	for(int v:G[u])
	{
		if(!dfn[v]) dfs3(v,u);
	}
}
void work()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v);
	}
	memset(ok,0,sizeof(ok));
	for(int i=1;i<=100;i++)
	{
		int nd=Rnd(1,n);
		if(chk(nd))
		{
			// cout<<nd<<endl;
			// return ;
			for(int j=1;j<=n;j++) s[j].clear();
			for(int i=1;i<=n;i++) dfn[i]=0;
			dfscnt=0;
			memset(fa,0,sizeof(fa));
			dfs2(nd,0);
			// for(int i=1;i<=n;i++) printf("%d%c",fa[i]," \n"[i==n]);
			ok[nd]=1;
			for(int i=1;i<=n;i++) dfn[i]=0;
			dfscnt=0;
			dfs3(nd,0);
			int ans=0;
			for(int i=1;i<=n;i++) if(ok[i]) ans++;
			if(ans*5<n) printf("-1\n");
			else
			{
				for(int i=1;i<=n;i++) if(ok[i]) printf("%d ",i);
				cout<<"\n";
			}
			return ;
		}
	}
	cout<<"-1\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}