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
typedef pair<int,int> pii;
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 100005
vector<int> G[N];
int n,f[N],ans[N],suf[N],dep[N];
int cmp(int x,int y) {return f[x]>f[y];}
int query(int x);
void dfs1(int u,int fa)
{
	dep[u]=dep[fa]+1;
	vector<int> tmp;
	for(int v:G[u])
	{
		if(v==fa) continue;
		dfs1(v,u),tmp.pb(f[v]);
	}
	sort(tmp.begin(),tmp.end(),greater<int>());
	sort(G[u].begin(),G[u].end(),cmp);
	f[u]=1;
	for(int i=0;i<(int)tmp.size();i++) f[u]=max(f[u],tmp[i]+i);
}
void dfs2(int u,int fa)
{
	int _cur=f[u]; vector<int> tmp;
	for(int v:G[u]) tmp.pb(f[v]);
	sort(tmp.begin(),tmp.end(),greater<int>());
	int res=0,mx=0;
	for(int i=0;i<(int)tmp.size();i++)
	{
		res=max(res,tmp[i]+mx+max(0,i-1));
		mx=max(mx,tmp[i]);
	}
	ans[u]=res;
	sort(G[u].begin(),G[u].end(),cmp);
	int pre=0; suf[G[u].size()]=0;
	for(int i=(int)G[u].size()-1;i>=0;i--) suf[i]=max(suf[i+1],f[G[u][i]]+i-1);
	for(int i=0;i<(int)G[u].size();i++)
	{
		int v=G[u][i];
		f[u]=max(1,max(pre,suf[i+1]));
		pre=max(pre,f[v]+i);
		if(v!=fa) dfs2(v,u);
	}
	f[u]=_cur;
}
vector<int> init(int _n, vector<pair<int, int> > e)
{
	n=_n;
	for(int i=0;i<(int)e.size();i++)
	{
		int u=e[i].fir,v=e[i].sec;
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,0),dfs2(1,0);
	vector<int> r(ans+1,ans+n+1);
	return r;
}
int query(int x) {cout<<"? "<<x<<endl; return read();}
int getnd(int u,int fa)
{
	if(fa&&G[u].size()==1) return query(u);
	for(int v:G[u])
	{
		if(v==fa) continue;
		int r=getnd(v,u);
		if(dep[r]!=dep[u]) return r;
	}
	return u;
}
pair<int, int> solve(int u)
{
	dfs1(u,0);
	int a=0,b=0;
	for(int v:G[u])
	{
		int r=getnd(v,u);
		if(r!=u)
		{
			if(!a) a=r;
			else b=r;
		}
		if(a&&b) break;
	}
	if(!a) a=u;
	if(!b) b=u;
//	printf("%d ^ %d %d\n",u,a,b);
	return {a,b};
}
signed main()
{
	int n=read();
	vector<pii> a;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		a.eb(u,v);
	}
	auto r=init(n,a);
	int mx=0; for(int i:r) mx=max(mx,i);
	cout<<mx<<endl;
	int f=read();
	auto [x,y]=solve(f);
	printf("! %d %d\n",x,y);
	return 0;
}