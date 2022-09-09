#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
vector<int> E[N];
int sz[N],par[N];
void DFS(int c, int p)
{
	par[c]=p;
	sz[c]=1;
	int i;
	for(i=0;i<E[c].size();i++)
	{
		int v=E[c][i];
		if(v!=p)
		{
			DFS(v,c);
			sz[c]+=sz[v];
		}
	}
}
void swap(int &a, int &b)
{
	int tmp=a;
	a=b;
	b=tmp;
}
int u[N],v[N],w[N],n;
ll Add(int j, int f)
{
	if(par[u[j]]!=v[j]) swap(u[j],v[j]);
	ll ret=(ll)sz[u[j]]*(sz[u[j]]-1)*(n-sz[u[j]]);
	ret+=(ll)sz[u[j]]*(n-sz[u[j]])*(n-sz[u[j]]-1);
	ret=ret*f*w[j];
	return ret;
}
double sol;
int main()
{
	int q,i,j,l;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i %i %i",&u[i],&v[i],&w[i]),E[u[i]].pb(v[i]),E[v[i]].pb(u[i]);
	DFS(1,0);
	for(i=1;i<n;i++) sol+=Add(i,1);
	scanf("%i",&q);
	while(q--)
	{
		scanf("%i %i",&j,&l);
		sol+=Add(j,-1);
		w[j]=l;
		sol+=Add(j,1);
		double ans=(double) sol/((ll)n*(n-1)*(n-2));
		ans=ans*6;
		printf("%.12llf\n",ans);
	}
	return 0;
}