#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=100050;
const int L=17;
vector<int> E[N];
int par[N][L],dep[N],lid[N],rid[N],tid;
void DFS(int u, int p)
{
	par[u][0]=p;
	dep[u]=dep[p]+1;
	lid[u]=++tid;
	for(int i=1;i<L;i++) par[u][i]=par[par[u][i-1]][i-1];
	for(int v:E[u]) if(v!=p) DFS(v,u);
	rid[u]=tid;
}
int LCA(int u, int v)
{
	if(dep[u]<dep[v]) return LCA(v,u);
	int i;
	for(i=L-1;~i;i--) if(dep[par[u][i]]>=dep[v]) u=par[u][i];
	for(i=L-1;~i;i--) if(par[u][i]!=par[v][i]) u=par[u][i],v=par[v][i];
	return u==v?v:par[v][0];
}
int Dist(int u, int v){ return dep[u]+dep[v]-2*dep[LCA(u,v)];}
set<pair<int,int> > all;
int sz;
void Print(){ for(auto p:all) printf("(%i %i) ",p.first,p.second);printf("\n");}
void Add(int u)
{
	int l=0,r=0;
	all.insert(mp(lid[u],u));
	auto it=all.find(mp(lid[u],u));
	if(it!=all.begin()){ it--;r=it->second;it++;}
	it++;if(it!=all.end()){ l=it->second;it++;if(it!=all.end() && !r) r=all.rbegin()->second;it--;}it--;
	if(!l && it!=all.begin()){ it--;if(it!=all.begin()){ it--;l=all.begin()->second;it++;}it++;}
	if(l && r) sz+=(Dist(u,l)+Dist(u,r)-Dist(l,r))/2;
	else if(l) sz+=Dist(u,l);
	else if(r) sz+=Dist(u,r);
	else sz=1;
	//printf("Add:%i, (l:%i r:%i) = %i\n",u,l,r,sz);
	//Print();
}
void Del(int u)
{
	int l=0,r=0;
	auto it=all.find(mp(lid[u],u));
	if(it!=all.begin()){ it--;r=it->second;it++;}
	it++;if(it!=all.end()){ l=it->second;it++;if(it!=all.end() && !r) r=all.rbegin()->second;it--;}it--;
	if(!l && it!=all.begin()){ it--;if(it!=all.begin()){ it--;l=all.begin()->second;it++;}it++;}
	if(l && r) sz-=(Dist(u,l)+Dist(u,r)-Dist(l,r))/2;
	else if(l) sz-=Dist(u,l);
	else if(r) sz-=Dist(u,r);
	else sz=0;
	all.erase(mp(lid[u],u));
	//printf("Del:%i, (l:%i r:%i) = %i\n",u,l,r,sz);
	//Print();
}
int main()
{
	int n,i,j,u,v,k;
	scanf("%i %i",&n,&k);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	j=1;DFS(1,0);int sol=0;
	for(i=1;i<=n;i++)
	{
		while(j<=n && sz<=k)
		{
			//printf("(%i %i)=%i\n",i,j,sz);
			sol=max(sol,j-i);Add(j);j++;
		}
		if(sz<=k) sol=max(sol,j-i);
		//printf("(%i %i)=%i\n",i,j,sz);
		Del(i);
	}
	printf("%i\n",sol);
	//printf("Dist(%i, %i)=%i\n",2,3,Dist(2,3));
	return 0;
}