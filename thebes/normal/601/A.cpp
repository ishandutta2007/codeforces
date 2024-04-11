#include <bits/stdc++.h>
using namespace std;

const int MN = 404;
bitset<MN> adj[MN];
int N, M, i, x, y, f1, f2, vis[MN];
queue<pair<int,int>> q;

int main(){
	for(scanf("%d%d",&N,&M),i=0;i<M;i++){
		scanf("%d%d",&x,&y);
		adj[x][y]=adj[y][x]=1;
	}
	q.push({1,0});
	while(!q.empty()){
		auto cur=q.front(); q.pop();
		if(!vis[cur.first]) vis[cur.first]=cur.second;
		else continue;
		for(i=1;i<=N;i++){
			if(adj[cur.first][i])
				q.push({i,cur.second+1});
		}
	}
	f1 = vis[N];
	memset(vis, 0, sizeof(vis));
	q.push({1,0});
	while(!q.empty()){
		auto cur=q.front(); q.pop();
		if(!vis[cur.first]) vis[cur.first]=cur.second;
		else continue;
		for(i=1;i<=N;i++){
			if(!adj[cur.first][i])
				q.push({i,cur.second+1});
		}
	}
	f2 = vis[N];
	printf("%d\n",(!f1||!f2)?-1:max(f1,f2));
	return 0;
}