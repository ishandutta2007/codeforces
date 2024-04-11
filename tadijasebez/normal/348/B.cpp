#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long
const ll inf=1e15;
const int N=1e5+50;
ll min(ll a, ll b){ return a>b?b:a;}
ll sum,Max=inf,q=1,a[N];
vector<int> E[N];
void DFS(int u, int p, ll d)
{
	q=q/__gcd(q,d)*d;
	if(d>sum || d<0){ printf("%lld\n",sum); exit(0);}
	if(E[u].size()==1 && u>1) Max=min(Max,a[u]*d);
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		if(v!=p) DFS(v,u,d*(E[u].size()-(u!=1)));
	}
}
int main()
{
	int n,i,u,v;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
	for(i=1;i<n;i++)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	DFS(1,0,1);
	printf("%lld\n",sum-Max/q*q);
	return 0;
}