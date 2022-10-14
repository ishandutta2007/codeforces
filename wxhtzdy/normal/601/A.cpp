#include <bits/stdc++.h>

using namespace std;

typedef pair < int, int > pii;

const int N = 4e3 + 50;
const int INF = 123456;

int n, m, cost[2][N][N], dis[2][N][N];
map < pii, int> ima;

void dijkstra(int k){
	queue < int > que;
	que.push(1);
	dis[k][1][1] = 0;
	while(!que.empty()){
		int x = que.front();
		que.pop();
		for(int i = 1;i <= n;i++){
			if(cost[k][x][i] == 1 && dis[k][1][i] > dis[k][1][x] + 1){
				dis[k][1][i] = dis[k][1][x] + 1;
				que.push(i);
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++){
			cost[0][i][j] = (i == j ? 0 : INF);
			cost[1][i][j] = (i == j ? 0 : INF);
			dis[0][i][j] = cost[0][i][j];
			dis[1][i][j] = cost[1][i][j];
		}
	}
	for(int i = 0;i < m;i++){
		int u, v;
		scanf("%d%d", &u, &v);
		cost[0][u][v] = cost[0][v][u] = 1;
	}
	for(int x = 1;x <= n;x++){
		for(int y = 1;y <= n;y++){
			if(cost[0][x][y] == INF){
				cost[1][x][y] = 1;
			}
		}
	}
	dijkstra(0);
	dijkstra(1);
	int ans = max(dis[0][1][n], dis[1][1][n]);
	printf("%d", (ans == INF ? -1 : ans));
	return 0;
}