#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mt make_tuple
const int N=200050;
vector<int> E[N];
vector<tuple<int,int,int> > ans;
bool ctr[N];
int last,sz[N],n;
void DFSSZ(int u, int p)
{
	sz[u]=1;ctr[u]=1;
	for(int v:E[u]) if(v!=p)
	{
		DFSSZ(v,u);
		sz[u]+=sz[v];
		if(sz[v]>n/2) ctr[u]=0;
	}
	if(n-sz[u]>n/2) ctr[u]=0;
}
void DFS(int u, int p, int cen, int sku)
{
	for(int v:E[u]) if(v!=p && !ctr[v])
	{
		DFS(v,u,cen,sku);
		ans.pb(mt(cen,last,v));
		ans.pb(mt(v,u,sku));
		last=v;
	}
}
int main()
{
	int i,j,u,v;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFSSZ(1,0);
	vector<int> cns;
	for(i=1;i<=n;i++) if(ctr[i]) cns.pb(i);
	for(i:cns)
	{
		for(j:E[i]) if(!ctr[j])
		{
			last=j;
			DFS(j,i,i,j);
			ans.pb(mt(i,last,j));
		}
	}
	vector<tuple<int,int,int> > sol;
	for(i=0;i<ans.size();i++) if(get<1>(ans[i])!=get<2>(ans[i])) sol.pb(ans[i]);
	printf("%i\n",sol.size());
	for(auto p:sol) printf("%i %i %i\n",get<0>(p),get<1>(p),get<2>(p));
	return 0;
}