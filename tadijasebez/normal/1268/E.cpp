#include <bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=500050;
int ans[N],f[N],go[N],par[N],up[N],dep[N],ab[N],a[N],b[N];
vector<int> E[N];
void DFS(int u, int p, int _e)
{
	par[u]=p;
	dep[u]=dep[p]+1;
	up[u]=_e;
	for(int e:E[u])
	{
		int v=ab[e]^u;
		if(v==p) continue;
		if(!dep[v]) DFS(v,u,e);
		else if(dep[v]<dep[u])
		{
			vector<int> cyc;
			cyc.pb(e);
			for(int i=u;i!=v;i=par[i]) cyc.pb(up[i]);
			int mn=0;
			for(int i=1;i<cyc.size();i++) if(cyc[i]<cyc[mn]) mn=i;
			int L=0,R=0,sz=cyc.size();
			auto md=[&](int x){ return (x%sz+sz)%sz;};
			while(cyc[md(mn+L)]<cyc[md(mn+L+1)]) L++;
			while(cyc[md(mn-R)]<cyc[md(mn-R-1)]) R++;
			if(L+R==cyc.size()) go[cyc[mn]]=cyc[md(mn+L)];
		}
	}
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1,u,v;i<=m;i++) scanf("%i %i",&u,&v),a[i]=u,b[i]=v,ab[i]=u^v,E[u].pb(i),E[v].pb(i);
	DFS(1,0,0);
	for(int i=1;i<=n;i++) ans[i]=1;
	for(int i=m;i>=1;i--) ans[a[i]]=ans[b[i]]=f[i]=ans[a[i]]+ans[b[i]]-f[go[i]];
	for(int i=1;i<=n;i++) printf("%i ",ans[i]-1);
	return 0;
}