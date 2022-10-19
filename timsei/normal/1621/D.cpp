#include <bits/stdc++.h>
using namespace std;
 
const int N = 505;
 
int l, r, Min1, Min2, n, a, P[N];
long long dis[N * N];
int  c[N][N];
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
 
int id(int x, int y) {
	return (x) * 2 * n + y + 1;
}
 
struct NODE {
	long long dis;
	int lst;
	
	friend bool operator < (NODE a, NODE b) {
		return a.dis > b.dis;
	}
}now;
 
priority_queue < NODE > q;
 
bool vis[N * N];
long long build(int xxx, int yyy) {
	for(int i = 0; i < 2 * n; ++ i) for(int j = 0; j < n * 2; ++ j) dis[id(i, j)] = 1e18, vis[id(i, j)] = 0;
	for(int i = 0; i < n; ++ i) for(int j = 0; j < n; ++ j) dis[id(i, j)] = 0, q.push((NODE){0, id(i, j)});
	while(!q.empty()) {
		now = q.top();
		q.pop();
		int it = now.lst;
		if(vis[it]) continue;
		vis[it] = 1;
		int x = (it - 1) / (n * 2), y = (it - 1) % (n * 2);
		for(int i = 0; i < 4; ++ i) {
			if(i != xxx && i != yyy) continue;
			int nx = x + dx[i], ny = y + dy[i];
			nx = (nx + 2 * n) % (2 * n);
			ny = (ny + n * 2) % (n * 2);
			int V = id(nx, ny);
			if(vis[V]) continue;
			long long Dis = dis[it] + c[nx][ny];
			if(Dis >= dis[V]) continue;
			dis[V] = Dis;
			q.push((NODE){Dis, V});
		}
	}
	long long ans = 1e18;
	for(int i = n; i < 2 * n; ++ i) {
		for(int j = n; j < 2 * n; ++ j) ans = min(ans, dis[id(i, j)]);
	}
	return ans;
}
 
void solve() {
	scanf("%d", &n);
	long long res = 0;
	for(int i = 0; i < 2 * n; ++ i) {
		for(int j = 0; j < 2 * n; ++ j) {
			scanf("%d", &c[i][j]), dis[id(i, j)] = 1e18;
			if(i >= n && j >= n) {
				res += c[i][j], c[i][j] = 0;
			}
		}
	}
	long long ans = 
	min(min(min(c[n][n - 1], c[n - 1][n]), min(c[0][n], c[n][0])), 
	min(min(c[n - 1][2 * n - 1], c[2 * n - 1][n - 1]), min(c[2 * n - 1][0], c[0][2 * n - 1])));
	cout << ans + res << endl;
}
 
int main() {
	int t;
	for(cin >> t; t --;) {
		solve();
	}
}