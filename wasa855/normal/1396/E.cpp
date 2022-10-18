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
#define N 100005
vector<int> G[N];
int n,k,siz[N];
int rt,sum;
void dfs1(int u,int f)
{
	siz[u]=1; int maxn=0;
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		maxn=max(maxn,siz[v]);
	}
	maxn=max(maxn,n-siz[u]);
	if(maxn*2<=n) rt=u;
}
int fa[N],dep[N],cnt[N],bl[N];
void dfs2(int u,int f)
{
	fa[u]=f,dep[u]=dep[f]+1,siz[u]=1;
	sum+=dep[u]-1;
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs2(v,u);
		siz[u]+=siz[v];
		if(G[v].size()>1) cnt[u]++;
	}
}
struct Node
{
	int id,siz;
	Node(int x,int y){id=x,siz=y;}
	bool operator < (const Node &x) const
	{
		return siz<x.siz;
	}
};
priority_queue<Node> qn;
struct Fa
{
	int id,dep;
	Fa(int x,int y){id=x,dep=y;}
	bool operator < (const Fa &x) const
	{
		return dep<x.dep;
	}
};
priority_queue<Fa> q[N];
vector<int> sn[N];
void dfs3(int u,int f,int id)
{
	if(cnt[u]==0&&G[u].size()!=1) q[id].emplace(u,dep[u]);
	bl[u]=id;
	for(int v:G[u])
	{
		if(v==f) continue;
		if(G[v].size()==1) sn[u].pb(v);
		dfs3(v,u,id);
	}
}
vector<pii> ans;
bool vis[N];
int dfs4(int u,int f,int ned)
{
	if(!vis[u]&&dep[u]==ned&&(cnt[u]>0||sn[u].size()>0)) return u;
	for(int v:G[u])
	{
		if(v==f) continue;
		int R=dfs4(v,u,ned);
		if(R) return R;
	}
	return 0;
}
vector<int> res[N];
void dfs5(int u,int f,int id)
{
	if(!vis[u]) res[id].pb(u);
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs5(v,u,id);
	}
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,0);
	dfs2(rt,0);
	for(int v:G[rt]) qn.emplace(v,siz[v]);
	for(int v:G[rt]) dfs3(v,rt,v);
	int Ans=0; for(int i=1;i<=n;i++) Ans+=siz[i]&1;
	// cout<<Ans<<endl;
	// cout<<rt<<endl;
	// for(int i=1;i<=n;i++)
	// {
		// if(sn[i].size())
		// {
			// cout<<i<<" :";
			// for(int j:sn[i]) printf("%d ",j);
			// cout<<'\n';
		// }
	// }
	// for(int i=1;i<=n;i++) printf("%d ",dep[i]); cout<<"\n";
	if((sum-k)&1) {cout<<"NO\n"; return 0;}
	if(sum<k) {cout<<"NO\n"; return 0;}
	while(sum>k)
	{
		Node u=qn.top(); qn.pop();
		if(u.siz==1) break;
		int b=u.id;
		if(q[b].empty()) break;
		Fa x=q[b].top(); q[b].pop();
		// printf("%d %d\n",x.id,x.dep);
		int id=x.id;
		if(sum-(dep[id]-1)*2<k)
		{
			u.siz-=2;
			// printf("%d %d\n",u.id,u.siz);
			if(u.siz>0) qn.push(u);
			int r=dfs4(b,rt,(sum-k)/2+1);
			vector<int> t; t.pb(r);
			for(int v:G[r])
			{
				if(v==fa[r]) continue;
				if(!vis[v]) t.pb(v);
			}
			sum=k;
			ans.eb(t[0],t[1]);
			vis[t[0]]=vis[t[1]]=1;
			break;
		}
		if(!sn[id].size())
		{
			qn.push(u);
			continue;
		}
		u.siz-=2;
		// printf("%d %d\n",u.id,u.siz);
		if(u.siz>0) qn.push(u);
		sum-=(dep[id]-1)*2;
		// cout<<sum<<endl;
		if(sn[id].size()==1)
		{
			ans.eb(id,sn[id][0]);
			sn[id].clear();
			if(fa[id]!=rt)
			{
				int f=fa[id];
				cnt[f]--;
				if(!cnt[f])
				{
					if(sn[f].size()) q[b].emplace(f,dep[f]);
					else
					{
						int ff=fa[f];
						if(ff!=rt)
						{
							cnt[ff]--,sn[ff].pb(f);
							q[b].emplace(ff,dep[ff]);
						}
					}
				}
			}
		}
		else if(sn[id].size()==2)
		{
			ans.eb(sn[id][0],sn[id][1]);
			sn[id].clear();
			if(fa[id]!=rt)
			{
				cnt[fa[id]]--;
				sn[fa[id]].pb(id);
				if(!cnt[fa[id]]) q[bl[id]].emplace(fa[id],dep[fa[id]]);
			}
		}
		else
		{
			int X=sn[id].back(); sn[id].pop_back();
			int Y=sn[id].back(); sn[id].pop_back();
			q[b].emplace(id,dep[id]);
			ans.eb(X,Y);
		}
		auto [A,B]=ans.back();
		vis[A]=vis[B]=1;
	}
	// for(auto [x,y]:ans) printf("%d %d\n",x,y);
	if(sum!=k) {cout<<"NO\n"; return 0;}
	for(int v:G[rt]) dfs5(v,rt,v);
	while(qn.size()>1)
	{
		auto [id1,_]=qn.top(); qn.pop();
		auto [id2,__]=qn.top(); qn.pop();
		if(_!=1) qn.emplace(id1,_-1);
		if(__!=1) qn.emplace(id2,__-1);
		ans.eb(res[id1].back(),res[id2].back());
		res[id1].pop_back(),res[id2].pop_back();
	}
	auto [id1,_]=qn.top(); qn.pop();
	assert(_==1);
	ans.eb(res[id1].back(),rt);
	cout<<"YES\n";
	for(auto [x,y]:ans) printf("%lld %lld\n",x,y);
	return 0;
}