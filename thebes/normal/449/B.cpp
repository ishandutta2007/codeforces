#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;

typedef tuple<long long,int> T;
typedef tuple<long long,int,int> T2;
const int MN = 1e5 + 5;
int n, m, k, i, x, y, w, dist[MN], ans;
vector<T> adj[MN];
priority_queue<T2> q;

int main(){
	for(scanf("%d%d%d",&n,&m,&k),i=0;i<m;i++){
		scanf("%d%d%d",&x,&y,&w);
		adj[x].push_back(mt(y,w));
		adj[y].push_back(mt(x,w));
	}
	for(i=0;i<k;i++){
		scanf("%d%d",&x,&y);
		q.push(mt(-y,x,0));
	}
	q.push(mt(0,1,1));
	while(!q.empty()){
		auto t = q.top(); q.pop();
		x = get<1>(t), y = -get<0>(t), w = get<2>(t);
		if(dist[x]) continue;
		if(w == 0) ans++;
		dist[x] = y;
		for(auto t2 : adj[x]){
			if(!dist[get<0>(t2)]&&get<0>(t2))
				q.push(mt(-1LL*(y+get<1>(t2)),get<0>(t2),1));
		}
	}
	printf("%d\n",k-ans);
	return 0;
}