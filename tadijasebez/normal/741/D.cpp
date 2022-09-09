#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define pb push_back
const int N=500050;
const int M=1<<22;
const int inf=1e9+7;
vector<int> E[N];
int sz[N],val[N],lid[N],rid[N],tid,nod[N],dep[N],HC[N],sol[N];
char ch[N];
void DFS(int u)
{
	lid[u]=++tid;
	nod[tid]=u;
	sz[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		dep[v]=dep[u]+1;
		val[v]=val[u]^(1<<(ch[v]-'a'));
		DFS(v);sz[u]+=sz[v];
		if(sz[v]>sz[HC[u]]) HC[u]=v;
	}
	rid[u]=tid;
}
int max(int a, int b){ return a>b?a:b;}
int mx[M];
void Solve(int u)
{
	int i,j,k;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=HC[u])
		{
			Solve(v);sol[u]=max(sol[u],sol[v]);
			for(j=lid[v];j<=rid[v];j++)
			{
				int h=nod[j];
				mx[val[h]]=-inf;
			}
		}
	}
	if(HC[u]) Solve(HC[u]),sol[u]=max(sol[u],sol[HC[u]]);
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=HC[u])
		{
			for(j=lid[v];j<=rid[v];j++)
			{
				int h=nod[j];
				sol[u]=max(sol[u],mx[val[h]]+dep[h]-2*dep[u]);
				for(k=0;k<22;k++) sol[u]=max(sol[u],mx[val[h]^(1<<k)]+dep[h]-2*dep[u]);
			}
			for(j=lid[v];j<=rid[v];j++)
			{
				int h=nod[j];
				mx[val[h]]=max(mx[val[h]],dep[h]);
			}
		}
	}
	for(k=0;k<22;k++) sol[u]=max(sol[u],mx[val[u]^(1<<k)]+dep[u]-2*dep[u]);
	sol[u]=max(sol[u],mx[val[u]]+dep[u]-2*dep[u]);
	mx[val[u]]=max(mx[val[u]],dep[u]);
}
int main()
{
	int n,i,x;
	scanf("%i",&n);
	for(i=2;i<=n;i++) scanf("%i %c",&x,&ch[i]),E[x].pb(i);
	for(i=0;i<M;i++) mx[i]=-inf;
	DFS(1);Solve(1);
	for(i=1;i<=n;i++) printf("%i ",sol[i]);
	return 0;
}