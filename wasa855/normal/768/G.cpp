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
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
#define N 100005
vector<int> G[N],v[N];
int fa[N],siz[N],n,rt,son[N];
int minn[N],maxn[N],id[N],ans[N];
multiset<int> s[N];
void dfs1(int u)
{
	siz[u]=1;
	for(int V:G[u])
	{
		dfs1(V),siz[u]+=siz[V];
		v[u].pb(siz[V]);
		if(siz[V]>maxn[u]) maxn[u]=siz[V],id[u]=V;
		minn[u]=min(minn[u],siz[V]);
		if(siz[V]>siz[son[u]]) son[u]=V;
	}
	if(u==rt) return ;
	v[u].pb(n-siz[u]);
	if(n-siz[u]>maxn[u]) maxn[u]=n-siz[u],id[u]=-1;
	minn[u]=min(minn[u],n-siz[u]);
}
int getans(const vector<int> &v,const multiset<int> &s)
{
	int A=(v[0]-v.back())/2;
	auto x=s.lower_bound(A);
	int ans=v[0];
	if(x!=s.end()) ans=min(ans,max(v[0]-(*x),v[1],v.back()+(*x)));
	if(x==s.begin()) return ans;
	--x;
	if(x!=s.end()) ans=min(ans,max(v[0]-(*x),v[1],v.back()+(*x)));
	return ans;
}
void merge(multiset<int> &u,multiset<int> &v)
{
	if(u.size()<v.size()) swap(u,v);
	for(auto i:v) u.insert(i);
}
void dfs2(int u)
{
	for(int v:G[u]) dfs2(v);
	if(id[u]!=-1&&v[u].size()!=1) ans[u]=getans(v[u],s[id[u]]);
	s[u].insert(siz[u]);
	for(int v:G[u]) merge(s[u],s[v]);
}
multiset<int> cur,cur2;
int getans2(int u,const vector<int> &v)
{
	int A=(v[0]-v.back())/2;
	auto x=cur2.lower_bound(A+siz[u]);
	int ans=v[0];
	if(x!=cur2.end()) ans=min(ans,max(v[0]-((*x)-siz[u]),v[1],v.back()+((*x)-siz[u])));
	if(x==cur2.begin()) return ans;
	--x;
	if(x!=cur2.end()) ans=min(ans,max(v[0]-((*x)-siz[u]),v[1],v.back()+((*x)-siz[u])));
	return ans;
}
void ins(int u)
{
	cur.erase(cur.find(siz[u]));
	for(int v:G[u]) ins(v);
}
void del(int u)
{
	cur.insert(siz[u]);
	for(int v:G[u]) del(v);
}
void dfs3(int u,int h)
{
	if(!son[u]) return ;
	cur.erase(cur.find(siz[u]));
	cur2.insert(siz[u]);
	for(int v:G[u])
	{
		if(v==son[u]) continue;
		dfs3(v,0);
	}
	dfs3(son[u],1);
	cur2.erase(cur2.find(siz[u]));
	for(int v:G[u]) if(v!=son[u]) ins(v);
	if(id[u]==-1&&v[u].size()!=1) ans[u]=min(getans(v[u],cur),getans2(u,v[u]));
	if(!h)
	{
		for(int v:G[u]) del(v);
		cur.insert(siz[u]);
	}
}
signed main()
{
	cin>>n;
	if(n==1)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		int u=read(),v=read();
		if(u==0) rt=v;
		else G[u].pb(v),fa[v]=u;
	}
	for(int i=1;i<=n;i++) minn[i]=inf;
	dfs1(rt);
	for(int i=1;i<=n;i++) sort(v[i].begin(),v[i].end(),greater<int>());
	for(int i=1;i<=n;i++) if(v[i].size()==1) ans[i]=v[i][0];
	// for(int i=1;i<=n;i++) printf("%d%c",(int)v[i].size()," \n"[i==n]);
	dfs2(rt);
	for(int i=1;i<=n;i++) cur.insert(siz[i]);
	dfs3(rt,1);
	for(int i=1;i<=n;i++) printf("%d\n",ans[i]);
	return 0;
}