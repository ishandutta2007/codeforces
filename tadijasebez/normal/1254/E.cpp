#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=500050;
const int mod=1e9+7;
map<int,int> id[N];
vector<pair<int,int>> E[N];
int dep[N],par[N],p_e[N],n,deg[N];
void DFS(int u, int p, int pe)
{
	p_e[u]=pe;
	par[u]=p;
	dep[u]=dep[p]+1;
	for(auto e:E[u]) if(e.first!=p) DFS(e.first,u,e.second);
}
int cnt;
int fir[N],las[N];
bool debug=0;
void No(int msg)
{
	printf("0\n");
	if(debug) printf("%i\n",msg);
	exit(0);
}
vector<int> go[N],in[N];
void AddPath(int u, int v)
{
	if(u==v) No(1);
	vector<int> nod_l,nod_r,edg_l,edg_r;
	while(dep[u]>dep[v]) nod_l.pb(u),edg_l.pb(p_e[u]),u=par[u],cnt++;
	while(dep[v]>dep[u]) nod_r.pb(v),edg_r.pb(p_e[v]),v=par[v],cnt++;
	while(u!=v) nod_l.pb(u),edg_l.pb(p_e[u]),u=par[u],nod_r.pb(v),edg_r.pb(p_e[v]),v=par[v],cnt+=2;
	if(cnt>n*2-2) No(2);
	reverse(nod_r.begin(),nod_r.end());
	reverse(edg_r.begin(),edg_r.end());
	vector<int> nod,edg;
	for(int i:nod_l) nod.pb(i);nod.pb(u);for(int i:nod_r) nod.pb(i);
	for(int i:edg_l) edg.pb(i);for(int i:edg_r) edg.pb(i);
	if(~fir[nod[0]]) No(3);
	fir[nod[0]]=id[nod[0]][edg[0]];
	deg[nod[0]]--;
	if(~las[nod.back()]) No(4);
	las[nod.back()]=id[nod.back()][edg.back()];
	deg[nod.back()]--;
	for(int i=1;i+1<nod.size();i++)
	{
		int a=id[nod[i]][edg[i-1]];
		int b=id[nod[i]][edg[i]];
		if(~go[nod[i]][a] || ~in[nod[i]][b]) No(5);
		go[nod[i]][a]=b;
		in[nod[i]][b]=a;
		deg[nod[i]]--;
	}
}
void Check()
{
	for(int i=1;i<=n;i++)
	{
		if(debug) printf("Check %i\n",i);
		if(~fir[i] && ~in[i][fir[i]]) No(6);
		if(!las[i] && ~go[i][las[i]]) No(7);
		vector<int> was(E[i].size());
		for(int j=0;j<E[i].size();j++) if(!was[j])
		{
			int u=j;
			while(~u && !was[u])
			{
				was[u]=1;
				u=go[i][u];
			}
			if(u==j) No(8);
		}
		if(~fir[i])
		{
			int u=fir[i],cnt=1;
			while(~go[i][u]) u=go[i][u],cnt++;
			if(u==las[i] && cnt!=E[i].size()) No(9);
		}
	}
}
int main()
{
	scanf("%i",&n);
	for(int i=1,u,v;i<n;i++) scanf("%i %i",&u,&v),E[u].pb({v,i}),E[v].pb({u,i});
	for(int i=1;i<=n;i++)
	{
		deg[i]=E[i].size();
		for(int j=0;j<E[i].size();j++) id[i][E[i][j].second]=j;
		fir[i]=las[i]=-1;
		go[i].assign(deg[i],-1);
		in[i].assign(deg[i],-1);
	}
	DFS(1,0,0);
	for(int i=1,j;i<=n;i++)
	{
		scanf("%i",&j);
		if(j) AddPath(j,i);
	}
	Check();
	for(int i=1;i<=n;i++) deg[i]=max(deg[i],0);
	int ans=1;
	for(int i=1;i<=n;i++) while(deg[i]) ans=(ll)ans*deg[i]%mod,deg[i]--;
	printf("%i\n",ans);
	return 0;
}