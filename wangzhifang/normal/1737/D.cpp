#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int max_n=500,max_m=250000;
vector<int> g[max_n+1];
int a[max_m+1][3];
int diss[max_n+1],dist[max_n+1],disa[max_n+1];
void test(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		dist[i]=diss[i]=n,g[i].clear();
	for(int i=1; i<=m; ++i){
		scanf("%d%d%d",a[i],a[i]+1,a[i]+2);
		g[a[i][0]].emplace_back(a[i][1]),
		g[a[i][1]].emplace_back(a[i][0]);
	}
	queue<int>que;
	que.push(1),diss[1]=0;
	while(!que.empty()){
		const int u=que.front();
		const int d=diss[u]+1;
		que.pop();
		for(const int&v:g[u])
			if(diss[v]>d)
				diss[v]=d,que.push(v);
	}
	que.push(n),dist[n]=0;
	while(!que.empty()){
		const int u=que.front();
		const int d=dist[u]+1;
		que.pop();
		for(const int&v:g[u])
			if(dist[v]>d)
				dist[v]=d,que.push(v);
	}
	priority_queue<pair<int,int> >pq;
	for(int i=1; i<=n; ++i){
		disa[i]=diss[i]+dist[i];
		pq.emplace(-disa[i],i);
	}
	while(!pq.empty()){
		const int u=pq.top().second,d=-pq.top().first;
		pq.pop();
		if(d!=disa[u])
			continue;
		for(const int&v:g[u])
			if(disa[v]>d+1){
				disa[v]=d+1;
				pq.emplace(-disa[v],v);
			}
	}
	ll ans=1ll<<60;
	for(int i=1; i<=m; ++i){
		const ll tmp=ll(a[i][2])*(min(min(diss[a[i][0]]+dist[a[i][1]],diss[a[i][1]]+dist[a[i][0]]),min(disa[a[i][0]],disa[a[i][1]])+1)+1);
		if(tmp<ans)
//			fprintf(stderr,"%d %d %d: %lld\n",a[i][0],a[i][1],a[i][2],tmp),
			ans=tmp;
	}
	printf("%lld\n",ans);
}
int main(){
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}