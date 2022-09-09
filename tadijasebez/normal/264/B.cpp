#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
const int N=100050;
const int S=317;
vector<int> E[N],Prime;
bool sieve[S];
void FindPrimes()
{
	int i,j;
	for(i=2;i<S;i++)
	{
		if(!sieve[i])
		{
			Prime.pb(i);
			for(j=i;j<S;j+=i) sieve[j]=1;
		}
	}
}
int last[N];
void Add(int x, int id)
{
	int i;
	for(i=0;i<Prime.size();i++)
	{
		if(x%Prime[i]==0)
		{
			if(last[Prime[i]]) E[last[Prime[i]]].pb(id);
			last[Prime[i]]=id;
			while(x%Prime[i]==0) x/=Prime[i];
		}
	}
	if(x>1)
	{
		if(last[x]) E[last[x]].pb(id);
		last[x]=id;
	}
}
int sz[N],sol,vis[N];
int max(int a, int b){ return a>b?a:b;}
void DFS(int u)
{
	if(vis[u]) return;
	sz[u]=1;vis[u]=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		DFS(v);sz[u]=max(sz[u],sz[v]+1);
	}
	sol=max(sol,sz[u]);
}
int a[N];
int main()
{
	FindPrimes();
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		Add(a[i],i);
	}
	for(i=1;i<=n;i++) if(!vis[i]) DFS(i);
	printf("%i\n",sol);
	return 0;
}