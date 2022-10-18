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
#define N 400005
int u[N],v[N],w[N];
int fa[N],c[N],n,Q;
int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
int popcnt(int x) {return __builtin_popcount(x)&1;}
vector<pii> G[N];
void dfs(int u,int f)
{
	for(auto [v,w]:G[u])
	{
		if(v==f) continue;
		if(w!=-1) printf("%d %d %d\n",u,v,w);
		else printf("%d %d %d\n",u,v,c[u]^c[v]);
		dfs(v,u);
	}
}
void work()
{
	n=read(),Q=read();
	for(int i=1;i<=n*2;i++) fa[i]=i;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<n;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
		G[u[i]].eb(v[i],w[i]);
		G[v[i]].eb(u[i],w[i]);
		if(w[i]!=-1)
		{
			if(popcnt(w[i])) fa[find(u[i])]=find(v[i]+n),fa[find(u[i]+n)]=find(v[i]);
			else fa[find(u[i])]=find(v[i]),fa[find(u[i]+n)]=find(v[i]+n);
		}
	}
	for(int i=1;i<=Q;i++)
	{
		int a=read(),b=read(),c=read();
		if(c==0) fa[find(a)]=find(b),fa[find(a+n)]=find(b+n);
		else fa[find(a)]=find(b+n),fa[find(a+n)]=find(b);
	}
	for(int i=1;i<=n;i++) if(find(i)==find(i+n)) {printf("NO\n"); return ;}
	printf("YES\n");
	for(int i=1;i<=n;i++)
	{
		if(find(i)<=n) c[i]=0;
		else c[i]=1;
	}
	if(c[0]==1)
	{
		for(int i=1;i<=n;i++) c[i]^=1;
	}
	dfs(1,0);
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}