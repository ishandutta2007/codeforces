#include <bits/stdc++.h>
using namespace std;
#define ldb long double
#define pb push_back
const int N=100050;
ldb p[N],sum[N],ans;
int par[N];
vector<int> E[N];
void DFS(int u, int f)
{
	ans+=(1-p[u])*p[f];
	par[u]=f;
	for(int v:E[u]) if(v!=f)
	{
		DFS(v,u);
		sum[u]+=1-p[v];
	}
}
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n,q,i,u,v;
	cin>>n;
	for(i=1;i<=n;i++) cin>>p[i];
	for(i=1;i<n;i++) cin>>u>>v,u++,v++,E[u].pb(v),E[v].pb(u);
	p[0]=1;
	DFS(1,0);
	cin>>q;
	while(q--)
	{
		cin>>u;u++;
		ans-=(1-p[u])*p[par[u]];
		ans-=p[u]*sum[u];
		sum[par[u]]-=1-p[u];
		cin>>p[u];
		ans+=(1-p[u])*p[par[u]];
		ans+=p[u]*sum[u];
		sum[par[u]]+=1-p[u];
		cout<<fixed<<setprecision(12)<<ans<<"\n";
	}
	return 0;
}