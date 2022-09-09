#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
const ll inf=1e18;
vector<pair<int,ll>> E[N];
ll dist[N];
int par[N];
int main(){
	int n,m;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=m;i++){
		int u,v,w;
		scanf("%i %i %i",&u,&v,&w);
		E[u].push_back({v,w});
		E[v].push_back({u,w});
	}
	for(int i=1;i<=n;i++)dist[i]=inf;
	priority_queue<pair<ll,int>> pq;
	dist[1]=0;
	pq.push({-dist[1],1});
	while(pq.size()){
		ll d=-pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(d!=dist[u])
			continue;
		for(auto e:E[u]){
			int v=e.first;
			ll w=e.second;
			if(dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				par[v]=u;
				pq.push({-dist[v],v});
			}
		}
	}
	if(dist[n]==inf)printf("-1\n");
	else{
		vector<int> path;
		for(int i=n;i!=0;i=par[i])
			path.push_back(i);
		reverse(path.begin(),path.end());
		for(int i:path)printf("%i ",i);
		printf("\n");
	}
	return 0;
}