//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const int N=1000050;
int p[N],sz[N];
void Init(int n){ for(int i=1;i<=n;i++) p[i]=i,sz[i]=1;}
int Find(int x){ return x==p[x]?x:p[x]=Find(p[x]);}
void Union(int x, int y){ x=Find(x);y=Find(y);p[x]=y;sz[y]+=sz[x];}
ll sol;
struct edge
{
	int u,v,w;
	edge(){}
	edge(int a, int b, int c){ u=a,v=b,w=c;}
	bool operator < (edge b) const{ return w<b.w;}
};
vector<edge> edges[2];
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int a[N];
int main()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		edges[0].push_back(edge(u,v,min(a[u],a[v])));
		edges[1].push_back(edge(u,v,max(a[u],a[v])));
	}
	sort(edges[0].begin(),edges[0].end());
	reverse(edges[0].begin(),edges[0].end());
	sort(edges[1].begin(),edges[1].end());
	Init(n);
	for(i=0;i<edges[0].size();i++)
	{
		sol-=(ll)edges[0][i].w*sz[Find(edges[0][i].u)]*sz[Find(edges[0][i].v)];
		Union(edges[0][i].u,edges[0][i].v);
	}
	//printf("%lld\n",sol);
	Init(n);
	for(i=0;i<edges[1].size();i++)
	{
		sol+=(ll)edges[1][i].w*sz[Find(edges[1][i].u)]*sz[Find(edges[1][i].v)];
		Union(edges[1][i].u,edges[1][i].v);
	}
	printf("%lld\n",sol);
	return 0;
}