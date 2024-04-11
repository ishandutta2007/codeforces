#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
const int N=300050;
vector<tuple<int,int,int> > E[N];
ll dist[N];
int main()
{
	int n,m,u,v,w,i,k;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=n;i++) dist[i]=1e18;
	for(i=1;i<=m;i++) scanf("%i %i %i",&u,&v,&w),E[u].pb(mt(v,w,i)),E[v].pb(mt(u,w,i));
	priority_queue<pair<ll,pair<int,int> > > pq;
	vector<int> ans;
	pq.push(mp(0,mp(1,-1)));
	dist[1]=0;
	while(pq.size())
	{
		int u=pq.top().second.first;
		int e=pq.top().second.second;
		ll d=-pq.top().first;
		pq.pop();
		if(d!=dist[u]) continue;
		if(e!=-1) ans.pb(e);
		if(ans.size()>=k) break;
		for(auto p:E[u])
		{
			int v=get<0>(p);
			int w=get<1>(p);
			int id=get<2>(p);
			if(dist[v]>dist[u]+w)
			{
				dist[v]=dist[u]+w;
				pq.push(mp(-dist[v],mp(v,id)));
			}
		}
	}
	printf("%i\n",ans.size());
	for(i:ans) printf("%i ",i);
	return 0;
}