#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int N=100050;
const int L=17;
vector<pair<int,int>> E[N];
ll dep[N];
int lid[N],rid[N],tid,lvl[N],par[N][L],n;
void DFS(int u, int p)
{
	lid[u]=++tid;
	par[u][0]=p;
	lvl[u]=lvl[p]+1;
	for(int i=1;i<L;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(auto e:E[u]) if(e.first!=p) dep[e.first]=dep[u]+e.second,DFS(e.first,u);
	rid[u]=tid;
}
int LCA(int u, int v)
{
	if(lvl[u]<lvl[v]) swap(u,v);
	for(int i=L-1;~i;i--) if(lvl[par[u][i]]>=lvl[v]) u=par[u][i];
	for(int i=L-1;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
struct cmp{ bool operator()(int a, int b)const{ return lid[a]<lid[b];}};
set<int,cmp> all;
int GetPar(int u)
{
	auto it=all.find(u);
	int lca1=0,lca2=0;
	if(it!=all.begin()) it--,lca1=LCA(*it,u),it++;
	it++;if(it!=all.end()) lca2=LCA(*it,u);it--;
	if(lca1==0 && lca2==0) return u;
	if(lvl[lca1]>lvl[lca2]) return lca1;
	return lca2;
}
bool IsLeaf(int u)
{
	auto it=all.find(u);
	it++;if(it==all.end()) return 1;
	int v=*it;
	if(lid[u]<=lid[v] && rid[u]>=lid[v]) return 0;
	return 1;
}
int GetChild1(int u)
{
	auto it=all.find(u);
	it++;if(it==all.end()) return 0;
	int v=*it;
	if(lid[u]<=lid[v] && rid[u]>=lid[v]) return v;
	return 0;
}
int GetChild2(int u)
{
	lid[n+1]=rid[u]+1;
	auto it=all.lower_bound(n+1);
	it--;if(*it!=u) return *it;
	return 0;
}
ll ans;
bool active[N];
void Add(int u)
{
	active[u]=1;
	if(all.count(u)) return;
	all.insert(u);
	int p=GetPar(u);
	bool flag=0;
	if(!all.count(p)) all.insert(p),flag=1;
	if(p==u) flag=1;
	if(IsLeaf(u)) ans+=dep[u]-dep[p];//,printf("+(%i %i) = %lld\n",u,p,dep[u]-dep[p]);
	auto it=all.find(p);
	if(it==all.begin() && !IsLeaf(p) && flag)
	{
		int x=GetChild1(p);
		if(x==u) x=*(++all.find(x));
		ans+=dep[x]-dep[p];
		//printf("+(%i %i) = %lld\n",x,p,dep[x]-dep[p]);
	}
}
void Try(int u)
{
	if(active[u] || !all.count(u)) return;
	bool del=0;
	if(IsLeaf(u))
	{
		int p=GetPar(u);
		ans-=dep[u]-dep[p];
		del=1;
		//printf("-(%i %i) = %lld\n",u,p,dep[u]-dep[p]);
	}
	else
	{
		int ch1=GetChild1(u),ch2=GetChild2(u);
		if(LCA(ch1,ch2)!=u) del=1;
	}
	if(del)
	{
		auto it=all.find(u);
		if(it==all.begin() && !IsLeaf(u))
		{
			int x=GetChild1(u);
			ans-=dep[x]-dep[u];
			//printf("-(%i %i) = %lld\n",x,u,dep[x]-dep[u]);
		}
		all.erase(u);
	}
}
void Del(int u)
{
	active[u]=0;
	int p=GetPar(u);
	Try(u);
	Try(p);
}
int main()
{
	int q,i,u,v,w,x;char t;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i %i",&u,&v,&w),E[u].pb({v,w}),E[v].pb({u,w});
	DFS(1,0);
	scanf("%i",&q);
	while(q--)
	{
		scanf("\n%c",&t);
		if(t=='+') scanf("%i",&x),Add(x);
		if(t=='-') scanf("%i",&x),Del(x);
		if(t=='?') printf("%lld\n",ans);
	}
	return 0;
}