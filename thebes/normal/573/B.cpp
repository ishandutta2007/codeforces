#include <bits/stdc++.h>
using namespace std;

const int MN = 100005;
typedef pair<int,int> pii;
struct pq{bool operator()(const pii&i,const pii&j)
	{return(i.second>j.second);}};
priority_queue<pii,vector<pii>,pq> q;
int N, dist[MN], ans, i;
bitset<MN> vis;

int main(){
	for(scanf("%d",&N),i=1;i<=N;i++)
		scanf("%d",&dist[i]);
	for(i=1;i<=N;i++){
		dist[i] = min(dist[i], min(i,N-i+1));
		q.push(make_pair(i,dist[i]));
	}
	while(!q.empty()){
		pii cur = q.top(); q.pop();
		int c = cur.first;
		if(vis[cur.first]) continue;
		else vis[cur.first] = 1;
		dist[c-1]=min(dist[c-1],dist[c]+1);
		dist[c+1]=min(dist[c+1],dist[c]+1);
		ans=max(ans,dist[c]);
		if(c!=1) q.push(make_pair(c-1,dist[c-1]));
		if(c!=N) q.push(make_pair(c+1,dist[c+1]));
	}
	printf("%d\n",ans);
	return 0;
}