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
#define N 200005
vector<int> G[N];
int n,m;
int cnt[N],dep[N],fa[N];
void dfs(int u,int f)
{
	fa[u]=f,dep[u]=dep[f]+1;
	for(int v:G[u])
	{
		if(v==f) continue;
		if(!dep[v]) dfs(v,u);
		else if(dep[v]<dep[u])  cnt[u]++,cnt[v]--;
	}
}
void dfs2(int u)
{
	for(int v:G[u])
	{
		if(fa[v]==u)
		{
			dfs2(v);
			cnt[u]+=cnt[v];
		}
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v]) swap(u,v);
	while(dep[u]>dep[v]) u=fa[u];
	while(u!=v) u=fa[u],v=fa[v];
	return u;
}
vector<pii> ans;
void dfs3(int u,int tp)
{
	for(int v:G[u])
	{
		if(fa[v]==u) dfs3(v,tp);
		else if(fa[u]!=v)
		{
			if(dep[v]<=dep[tp]) ans.eb(v,u);
		}
	}
}
void print(vector<int> v)
{
	printf("%d ",(int)v.size());
	for(int i:v) printf("%d ",i);
	cout<<"\n";
}
void print(int x)
{
	cout<<"YES\n";
	dfs3(x,fa[x]);
	// for(auto [a,b]:ans) printf("-- %d %d\n",a,b);
	// return ;
	int A=ans[0].fir,B=ans[1].fir,C=ans[0].sec,D=ans[1].sec;
	int u=lca(C,D),v=dep[A]>dep[B]?A:B;
	vector<int> pr;
	int tmp=u;
	while(tmp!=v)
	{
		pr.pb(tmp);
		tmp=fa[tmp];
	}
	pr.pb(v);
	print(pr);
	pr.clear();
	
	tmp=v;
	while(tmp!=A)
	{
		pr.pb(tmp);
		tmp=fa[tmp];
	}
	pr.pb(A);
	tmp=C;
	while(tmp!=u)
	{
		pr.pb(tmp);
		tmp=fa[tmp];
	}
	pr.pb(u);
	reverse(pr.begin(),pr.end());
	print(pr);
	pr.clear();
	
	tmp=v;
	while(tmp!=B)
	{
		pr.pb(tmp);
		tmp=fa[tmp];
	}
	pr.pb(B);
	tmp=D;
	while(tmp!=u)
	{
		pr.pb(tmp);
		tmp=fa[tmp];
	}
	pr.pb(u);
	reverse(pr.begin(),pr.end());
	print(pr);
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dep[i])
		{
			dfs(i,0);
			dfs2(i);
		}
	}
	// for(int i=1;i<=n;i++) printf("%d ",cnt[i]); cout<<"\n";
	for(int i=2;i<=n;i++)
	{
		if(cnt[i]>=2) {print(i); return 0;}
	}
	cout<<"NO\n";
	return 0;
}