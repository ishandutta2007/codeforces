#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
const int N=300050;
ll mx[N],ans,a[N];
vector<pair<int,int> > E[N];
void DFS(int u, int p)
{
	ll best=0;ans=max(ans,a[u]);
	for(auto v:E[u]) if(v.first!=p)
	{
		DFS(v.first,u);
		ll tmp=mx[v.first]-v.second;
		if(tmp>0)
		{
			ans=max(ans,best+tmp+a[u]);
			best=max(best,tmp);
		}
	}
	mx[u]=best+a[u];
}
int main()
{
	int n,i,u,v,w;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<n;i++) scanf("%i %i %i",&u,&v,&w),E[u].pb(mp(v,w)),E[v].pb(mp(u,w));
	DFS(1,0);
	printf("%lld\n",ans);
	return 0;
}