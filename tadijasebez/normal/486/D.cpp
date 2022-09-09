#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int mod=1e9+7;
const int N=2050;
vector<int> E[N];
int a[N],sol;
int DFS(int u, int p, int bot, int top, int tr)
{
	if(a[u]<bot || a[u]>top) return 0;
	if(a[u]==bot && u<tr) return 0;
	int ret=1;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p)
		{
			ret=(ll)ret*(DFS(v,u,bot,top,tr)+1)%mod;
		}
	}
	return ret;
}
int main()
{
	int n,u,v,i,d;
	scanf("%i %i",&d,&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	for(i=1;i<=n;i++)
	{
		sol+=DFS(i,i,a[i],a[i]+d,i);
		sol%=mod;
	}
	printf("%i\n",sol);
	return 0;
}