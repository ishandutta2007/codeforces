#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pb push_back
const int N=200050;
vector<int> E[N];
ll ans,sol;
int sz[N],n,c[2];
void Solve(int u, int p, int d)
{
	ll all=0;sz[u]=1;c[d&1]++;
	for(int v:E[u]) if(v!=p) Solve(v,u,d+1),sz[u]+=sz[v],all-=(ll)sz[v]*(sz[v]-1)/2;
	all+=(ll)sz[u]*(sz[u]-1)/2;
	//printf("u:%i all:%lld\n",u,all);
	sol-=(ll)2*d*all;
	sol+=(ll)d*(n-1);
}
int main()
{
	scanf("%i",&n);
	int u,v,i;
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
    Solve(1,0,0);
    sol+=(ll)c[1]*c[0];
    ans=sol/2;
    printf("%lld\n",ans);
	return 0;
}