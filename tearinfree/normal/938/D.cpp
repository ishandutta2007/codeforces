#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>

using namespace std;
typedef long long lli;
typedef pair<lli,int> pli;

int n,m;
vector<pli> adj[200001];
lli dist[200001];
int vis[200001];

int main() {
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++) {
		int a,b;
		lli c;
		scanf("%d%d%lld",&a,&b,&c);
		c *= 2;
		adj[a].push_back(pli(c,b));
		adj[b].push_back(pli(c,a));
	}
	for(int i=1;i<=n;i++) scanf("%lld",dist+i);

	priority_queue<pli,vector<pli>,greater<pli>> que;
	for(int i=1;i<=n;i++) {
		que.push(pli(dist[i],i));
	}
	while(!que.empty()) {
		lli cost=que.top().first;
		int cur=que.top().second;
		que.pop();
		if(vis[cur]) continue;
		vis[cur] = 1;
		for(auto &v:adj[cur]) {
			if(!vis[v.second] && dist[v.second] > cost + v.first) {
				dist[v.second] = cost + v.first;
				que.push(pli(dist[v.second],v.second));
			}
		}
	}
	for(int i=1;i<=n;i++) printf("%lld ",dist[i]);
	
	return 0;
}