#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
const int mod=1e9+7;
const int N=200050;
vector<int> E[N];
int sz[N];
bool vis[N];
void DFS(int u, int p, int &n)
{
	n++;sz[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p && !vis[v]) DFS(v,u,n),sz[u]+=sz[v];
	}
}
int Find(int u, int p, int n)
{
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p && !vis[v] && sz[v]>n/2) return Find(v,u,n);
	}
	return u;
}
int Find(int u){ int n=0;DFS(u,u,n);return Find(u,u,n);}
int sum[2],cnt[2],a[N],sol;
vector<int> bck[2];
void Solve(int u, int p, int d, int w, int cen)
{
	d++;w=-w+mod;w+=a[u];if(w>=mod) w-=mod;
	bck[(d&1)^1].pb(w);
	if(!(d&1)){ w-=a[cen];if(w<0) w+=mod;}
	else{ w+=a[cen];if(w>=mod) w-=mod;}
	if(d&1)
	{
		sol+=(ll)sum[0]*2%mod;
		if(sol>=mod) sol-=mod;
		sol+=(ll)cnt[0]*2*w%mod;
		if(sol>=mod) sol-=mod;
	}
	else
	{
		sol+=(ll)sum[1]*2%mod;
		if(sol>=mod) sol-=mod;
		sol+=(ll)cnt[1]*2*w%mod;
		if(sol>=mod) sol-=mod;
	}
	if(!(d&1)){ w+=a[cen];if(w>=mod) w-=mod;}
	else{ w-=a[cen];if(w<0) w+=mod;}
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v] && v!=p) Solve(v,u,d,w,cen);
	}
}
void Decompose(int u)
{
	u=Find(u);vis[u]=1;
	int i,j;
	sum[0]=sum[1]=cnt[0]=cnt[1]=0;
	cnt[1]=1;sum[1]=a[u];
	sol+=a[u];if(sol>=mod) sol-=mod;
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v])
		{
			Solve(v,u,0,a[u],u);
			for(j=0;j<bck[0].size();j++)
			{
				sum[0]+=bck[0][j];cnt[0]++;
				if(sum[0]>=mod) sum[0]-=mod;
			}
			bck[0].clear();
			for(j=0;j<bck[1].size();j++)
			{
				sum[1]+=bck[1][j];cnt[1]++;
				if(sum[1]>=mod) sum[1]-=mod;
			}
			bck[1].clear();
		}
	}
	for(i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(!vis[v]) Decompose(v);
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]<0) a[i]+=mod;
	}
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].pb(v);
		E[v].pb(u);
	}
	Decompose(1);
	printf("%i\n",sol);
	return 0;
}