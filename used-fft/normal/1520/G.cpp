#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

signed main(){
	cin.tie(0)->sync_with_stdio(0);

	int n, m, w; cin >> n >> m >> w;

	int g[n][m];
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin >> g[i][j];
		}
	}

	int dist[n][m];
	for(int i=0; i<n; ++i) fill(dist[i], dist[i] + m, INF);

	queue<array<int, 2>> q;
	q.push({0, 0});
	dist[0][0] = 0;
	while(!q.empty()){
		int x = q.front()[0], y = q.front()[1];
		q.pop();
		for(int k=0; k<4; ++k){
			int i = dx[k] + x, j = dy[k] + y;
			if(i < 0 or i == n or j < 0 or j == m or g[i][j] < 0 or dist[i][j] < INF) continue;
			dist[i][j] = dist[x][y] + w;
			q.push({i, j});
		}
	}

	int left = INF;
	int ans = dist[n-1][m-1];
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(g[i][j] > 0) left = min(left, g[i][j] + dist[i][j]);
		}
	}


	q.push({n-1, m-1});
	for(int i=0; i<n; ++i) fill(dist[i], dist[i] + m, INF);
	dist[n-1][m-1] = 0;
	while(!q.empty()){
		int x = q.front()[0], y = q.front()[1];
		q.pop();
		for(int k=0; k<4; ++k){
			int i = dx[k] + x, j = dy[k] + y;
			if(i < 0 or i == n or j < 0 or j == m or g[i][j] < 0 or dist[i][j] < INF) continue;
			dist[i][j] = dist[x][y] + w;
			q.push({i, j});
		}
	}

	int right = INF;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(g[i][j] > 0) right = min(right, g[i][j] + dist[i][j]);
		}
	}

	ans = min(ans, left + right);
	if(ans >= (int)1e16) ans = -1;
	cout << ans;
}