#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=1050;
vector<int> all,E[N];
bool was[N];
int par[N],dep[N];
void DFS(int u, int p)
{
	was[u]=1;
	dep[u]=dep[p]+1;
	par[u]=p;
	all.pb(u);
	for(int v:E[u]) if(v!=p) DFS(v,u);
}
bool comp(pair<int,int> a, pair<int,int> b){ return a.second<b.second;}
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	for(i=1;i<=m;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	vector<pair<int,int> > work,ans;
	int sol=0;
	for(i=1;i<=n;i++) if(!was[i])
	{
		all.clear();
		DFS(i,0);
		int cen=0,den=0;
		for(int v:all) if(dep[cen]<dep[v]) cen=v;
		all.clear();
		DFS(cen,0);
		for(int v:all) if(dep[den]<dep[v]) den=v;
		int mx=dep[den];
		sol=max(sol,mx-1);
		int goal=(dep[den]+1)/2;
		while(dep[den]!=goal) den=par[den];
		work.pb(mp(den,max(dep[den]-1,mx-dep[den])));
	}
	sort(work.begin(),work.end(),comp);
	for(i=0;i+1<work.size();i++)
	{
		ans.pb(mp(work[i].first,work.back().first));
		sol=max(sol,work[i].second+work.back().second+1);
	}
	int sz=work.size();
	if(work.size()>2) sol=max(sol,work[sz-3].second+work[sz-2].second+2);
	printf("%i\n",sol);
	for(auto p:ans) printf("%i %i\n",p.first,p.second);
	return 0;
}