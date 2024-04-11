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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
typedef pair<int,int> pii;
#define N 200005
int p[N],a[N],b[N],n,Q;
int pre[N],st[N],val[N],sum[N],tp;
vector<int> G[N];
void dfs1(int u)
{
	val[u]=a[u]-b[u];
	for(int v:G[u]) dfs1(v),val[u]+=b[v];
}
void dfs2(int u)
{
	for(int v:G[u]) dfs2(v);
	if(val[u]<0&&u) val[pre[u]]+=val[u],val[u]=0;
}
int dep[N],siz[N],son[N],dfn[N],top[N],fa[N];
void dfs3(int u)
{
	sum[u]=sum[pre[u]]+val[u];
	dep[u]=dep[pre[u]]+1,siz[u]=1;
	son[u]=N-1;
	for(int v:G[u])
	{
		dfs3(v);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs4(int u,int tp)
{
	top[u]=tp;
	if(!son[u]) return ;
	dfs4(son[u],tp);
	for(int v:G[u]) if(v!=son[u]) dfs4(v,v);
}
int lca(int u,int v)
{
	while(top[u]!=top[v])
	{
		if(dep[top[u]]>dep[top[v]]) u=fa[top[u]];
		else v=fa[top[v]];
	}
	return dep[u]<dep[v]?u:v;
}
int dis(int u,int v)
{
	int l=lca(u,v);
	return sum[u]+sum[v]-sum[l]*2;
}
int ans=0;
set<int> s;
void ins(int id)
{
	auto it=s.lower_bound(id);
	int pre,suf; it--; pre=*it;
	it++;
	if(it==s.end()) suf=0;
	else suf=*it;
	// printf("%d %d %d\n",pre,id,suf);
	ans+=dis(pre,id)+dis(id,suf)-dis(pre,suf);
	s.insert(id);
}
void del(int id)
{
	s.erase(id);
	auto it=s.lower_bound(id);
	int pre,suf; it--; pre=*it;
	it++;
	if(it==s.end()) suf=0;
	else suf=*it;
	ans-=dis(pre,id)+dis(id,suf)-dis(pre,suf);
}
int cnt[N],vis[N];
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++) p[i]=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=n;i++) b[i]=read();
	p[0]=inf; st[++tp]=0;
	for(int i=1;i<=n;i++)
	{
		while(p[i]>p[st[tp]]) tp--;
		pre[i]=st[tp],st[++tp]=i;
	}
	// for(int i=1;i<=n;i++) printf("%d%c",pre[i]," \n"[i==n]);
	for(int i=1;i<=n;i++) G[pre[i]].pb(i);
	pre[0]=N-1; s.insert(0),cnt[0]=inf;
	for(int i=0;i<=n;i++) fa[i]=pre[i];
	// for(int i=0;i<=n;i++)
	// {
		// printf("%lld : ",i); print(G[i]);
	// }
	dfs1(0),dfs2(0),dfs3(0),dfs4(0,0);
	// for(int i=0;i<=n;i++) printf("%d%c",val[i]," \n"[i==n]);
	ans=val[0]*2;
	while(Q--)
	{
		int u=read();
		if(!vis[u])
		{
			if(!cnt[pre[u]]++) ins(pre[u]);
		}
		else
		{
			if(!--cnt[pre[u]]) del(pre[u]);
		}
		vis[u]^=1;
		printf("%lld\n",ans/2);
	}
	return 0;
}