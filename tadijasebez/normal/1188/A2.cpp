#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
void ckmx(int &a, int b){ a=max(a,b);}
void ckmn(int &a, int b){ a=min(a,b);}
void ckmx(ll &a, ll b){ a=max(a,b);}
void ckmn(ll &a, ll b){ a=min(a,b);}
const int N=1005;
vector<pair<int,pair<int,int>>> ans;
vector<pair<int,int>> E[N];
int sum[N],par[N];
int GetLeaf(int u, int p)
{
	for(auto e:E[u]) if(e.first!=p) return GetLeaf(e.first,u);
	return u;
}
void PRE(int u, int p)
{
	par[u]=p;
	for(auto e:E[u]) if(e.first!=p) PRE(e.first,u);
}
int lf[N],deg[N];
void DFS(int u, int p)
{
	vector<int> leaf;
	for(auto e:E[u]) if(e.first!=p)
	{
		int v=e.first;
		leaf.pb(GetLeaf(v,u));
		lf[v]=leaf.back();
	}
	if(leaf.size()==2)
	{
		leaf.pb(GetLeaf(p,u));
	}
	for(auto e:E[u]) if(e.first!=p)
	{
		int v=e.first;
		int hal=(e.second-sum[v])/2;
		int l,r,i;
		for(i=0;i<leaf.size();i++) if(leaf[i]!=lf[v]){ l=leaf[i];break;}
		i++;
		for(;i<leaf.size();i++) if(leaf[i]!=lf[v]){ r=leaf[i];break;}
        ans.pb({hal,{lf[v],l}});
        ans.pb({hal,{lf[v],r}});
        ans.pb({-hal,{l,r}});
        for(int x=lf[v];x!=u;x=par[x]) sum[x]+=hal*2;
	}
	for(auto e:E[u]) if(e.first!=p) DFS(e.first,u);
}
int main()
{
	int n,u,v,w,root;
	scanf("%i",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%i %i %i",&u,&v,&w);
		deg[u]++;
		deg[v]++;
		E[u].pb({v,w});
		E[v].pb({u,w});
	}
	root=-1;
	for(int i=1;i<=n;i++)
	{
		if(deg[i]==2)
		{
			printf("NO\n");
			return 0;
		}
		if(deg[i]!=1) root=i;
	}
	if(root!=-1)
	{
		PRE(root,0);
		DFS(root,0);
		printf("YES\n");
		printf("%i\n",ans.size());
		for(auto p:ans)
		{
			printf("%i %i %i\n",p.second.first,p.second.second,p.first);
		}
	}
	else
	{
		printf("YES\n");
		printf("1\n");
		w=E[1][0].second;
		printf("1 2 %i\n",w);
	}
	return 0;
}