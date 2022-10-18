#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define ll __int128
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
int Ask(int u,int v)
{
	printf("? %d %d\n",u,v); fflush(stdout);
	return read();
}
namespace QAQ
{
	const int N=105;
	vector<int> G[N];
	ll f[N],pw[N];
	int ans[N],vis[N],fa[N],n;
	void ban(int u,int f)
	{
		vis[u]=1;
		for(int v:G[u])
		{
			if(vis[v]||v==f) continue;
			ban(v,u);
		}
	}
	struct Node
	{
		ll val; int id;
		bool operator < (const Node &x) const {return val<x.val;}
		Node(ll v,int i) {val=v,id=i;}
	};
	void dfs1(int u,int _fa)
	{
		fa[u]=_fa;
		for(int v:G[u]) if(v!=_fa) dfs1(v,u);
		f[u]=pw[n]-1;
		for(int i=n-1;i>=0;i--)
		{
			f[u]^=pw[i];
			priority_queue<ll> q;
			for(int v:G[u]) if(v!=_fa) q.push(f[v]);
			bool ok=1;
			for(int j=n-1;j>=0;j--)
			{
				if((f[u]>>j&1)&&!q.empty())
				{
					ll val=q.top(); q.pop();
					if(val>>(j+1)) ok=0;
					else if(val>>j&1) q.push(val^pw[j]);
				}
				else if(!q.empty())
				{
					ll val=q.top();
					if(val>>j) ok=0;
				}
			}
			if(!q.empty()) ok=0;
			if(!ok) f[u]^=pw[i];
		}
		priority_queue<Node> q;
		for(int v:G[u]) if(v!=_fa) q.emplace(f[v],v);
		for(int i=n-1;i>=0;i--)
		{
			if((f[u]>>i&1)&&!q.empty())
			{
				auto [val,id]=q.top(); q.pop();
				if(val>>i&1) q.emplace(val^pw[i],id);
				else ans[id]=i;
			}
		}
	}
	int Main(int _n,vector<pii> E)
	{
		n=_n; pw[0]=1; for(int i=1;i<=n;i++) pw[i]=pw[i-1]*2;
		for(int i=0;i<(int)E.size();i++)
		{
			int u=E[i].fir,v=E[i].sec;
			G[u].pb(v),G[v].pb(u);
		}
		dfs1(1,0);
//		for(int i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
		while(1)
		{
			int maxn=-inf,id=0;
			for(int i=2;i<=n;i++) if(!vis[i]&&!vis[fa[i]]) if(ans[i]>maxn) maxn=ans[i],id=i;
			if(!id)
			{
				for(int i=1;i<=n;i++) if(!vis[i]) return i;
				assert(0);
			}
			int q=Ask(id,fa[id]);
			if(q==fa[id]) ban(id,fa[id]);
			else ban(fa[id],id);
		}
	}
};
int Find(int N,vector<pair<int,int> > E) {return QAQ::Main(N,E);}
signed main()
{
	int n=read();
	vector<pii> E;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		E.eb(u,v);
	}
	int ans=Find(n,E);
	printf("! %d\n",ans);
	return 0;
}