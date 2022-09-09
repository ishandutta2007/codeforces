#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
const int N=200050;
vector<int> E[N];
int p[N],sz[N];
ll ans;
ll fir(int x){ return (ll)x*(x-1)/2;}
int Find(int x){ return p[x]==x?x:p[x]=Find(p[x]);}
void Union(int x, int y)
{
	x=Find(x);y=Find(y);
	ans-=fir(sz[x]);
	ans-=fir(sz[y]);
	p[y]=x;
	sz[x]+=sz[y];
	ans+=fir(sz[x]);
}
vector<pair<int,int> > edges[N];
int a[N];
ll sol[N];
int gcd(int x, int y){ return x?gcd(y%x,x):y;}
int main()
{
	int n,i,j,k,u,v;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		edges[gcd(a[u],a[v])].pb(mp(u,v));
	}
	for(i=1;i<N;i++)
	{
		for(j=i;j<N;j+=i)
		{
			for(k=0;k<edges[j].size();k++)
			{
				p[edges[j][k].first]=edges[j][k].first;
				p[edges[j][k].second]=edges[j][k].second;
				sz[edges[j][k].first]=1;
				sz[edges[j][k].second]=1;
			}
		}
		ans=0;
		for(j=i;j<N;j+=i)
		{
			for(k=0;k<edges[j].size();k++)
			{
				//printf("%i:(%i %i)\n",i,edges[j][k].first,edges[j][k].second);
				Union(edges[j][k].first,edges[j][k].second);
			}
		}
		sol[i]=ans;
	}
	for(i=200000;i;i--)
	{
		for(j=i*2;j<=200000;j+=i) sol[i]-=sol[j];
	}
	for(i=1;i<=n;i++) sol[a[i]]++;
	for(i=1;i<=200000;i++)
	{
		if(sol[i]) printf("%i %lld\n",i,sol[i]);
	}
	return 0;
}