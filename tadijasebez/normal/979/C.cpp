#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define ll long long
const int N=300050;
vector<int> E[N];
int dep[N],sz[N],lid[N],rid[N],tid,par[N];
void DFS(int u, int p)
{
	sz[u]=1;par[u]=p;
	dep[u]=dep[p]+1;
	lid[u]=++tid;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u),sz[u]+=sz[v];
	}
	rid[u]=tid;
}
int main()
{
	int n,x,y,i,u,v;
	scanf("%i %i %i",&n,&x,&y);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	DFS(1,0);
	ll sol;
	if(lid[x]<=lid[y] && rid[x]>=lid[y])
	{
		int h=y;
		while(par[h]!=x) h=par[h];
		sz[x]=n-sz[h];
		sol=(ll)n*(n-1)-(ll)sz[x]*sz[y];
	}
	else if(lid[y]<=lid[x] && rid[y]>=lid[x])
	{
		int h=x;
		while(par[h]!=y) h=par[h];
		sz[y]=n-sz[h];
		sol=(ll)n*(n-1)-(ll)sz[x]*sz[y];
	}
	else
	{
		sol=(ll)n*(n-1)-(ll)sz[x]*sz[y];
	}
	printf("%lld\n",sol);
	return 0;
}