#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define F first
#define S second

const int MN = 5e5+5;
int N, M, i, j, x, y, w, ans, col[MN], dis[MN];
vector<pii> adj[MN];
queue<int> q;

int main(){
	scanf("%d%d",&N,&M);
	for(i=1;i<=M;i++){
		scanf("%d%d%d",&x,&y,&w);
		adj[y].push_back({x,w});
	}
	memset(col,-1,sizeof(col));
	memset(dis,-1,sizeof(dis));
	q.push(N); dis[N] = 0;
	while(q.size()){
		x = q.front(); q.pop();
		for(auto v : adj[x]){
			if(dis[v.F]!=-1) continue;
			if(col[v.F]==-1) col[v.F] = !v.S;
			else if(col[v.F]==v.S){
				dis[v.F] = dis[x]+1;
				q.push(v.F);
			} 
		}
	}
	printf("%d\n",dis[1]);
	for(i=1;i<=N;i++)
		printf("%d",max(0,col[i]));
	printf("\n");
	return 0;
}