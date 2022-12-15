#include <bits/stdc++.h>
using namespace std;

const int MN = 1005;
int d[MN][2], mat[MN][MN], N, M, i, j, x, y, s, t, sh, cnt;
vector<int> adj[MN];
queue<int> q;

void rec(int dep, int dir){
	int sz = q.size();
	while(sz--){
		int cur = q.front(); q.pop();
		d[cur][dir] = dep;
		for(auto v : adj[cur]){
			if(d[v][dir]==-1){
				d[v][dir] = dep+1;
				q.push(v);
			}
		}
	}
	if(q.size()) rec(dep+1,dir);
}

int main(){
	scanf("%d%d%d%d",&N,&M,&s,&t);
	for(i=0;i<M;i++){
		scanf("%d%d",&x,&y);
		adj[x].push_back(y);
		adj[y].push_back(x);
		mat[x][y]=mat[y][x]=1;
	}
	memset(d,-1,sizeof(d));
	q.push(s); rec(0,0);
	q.push(t); rec(0,1);
	sh = d[t][0];
	for(i=1;i<=N;i++){
		for(j=i+1;j<=N;j++){
			if(mat[i][j]||i==j) continue;
			if(d[i][0]+1+d[j][1]>=sh&&d[i][1]+1+d[j][0]>=sh) cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}