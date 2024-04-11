#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back 

const int key[8][2] = {{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}}; 

const int N = 400; 

int n; 
int t[40]; 
bool vis[N][N]; 
bool v[8][40][N][N];

struct data {
	int d, s, x, y; 
}; 
deque<data> q; 

void Push(int d, int s, int x, int y) {
	if (!v[d][s][x][y]) {
		v[d][s][x][y] = true; 
		q.pb({d,s,x,y}); 
	}
}

void bfs() {
	memset(vis, false, sizeof(vis)); 
	memset(v, false, sizeof(v)); 
	q.clear();
	Push(1,1,N/2,N/2); 
	while (!q.empty()) {
		auto u = q.front(); q.pop_front();
		//cout<<u.x<<' '<<u.y<<endl;  
		for (int i = 0; i < t[u.s]; ++i) 
			vis[u.x+i*key[u.d][0]][u.y+i*key[u.d][1]] = true; 
		u.x += (t[u.s]-1)*key[u.d][0]; 
		u.y += (t[u.s]-1)*key[u.d][1]; 
		if (u.s != n) { 
			Push((u.d+7)%8,u.s+1,u.x+key[(u.d+7)%8][0],u.y+key[(u.d+7)%8][1]); 
			Push((u.d+1)%8,u.s+1,u.x+key[(u.d+1)%8][0],u.y+key[(u.d+1)%8][1]); 
		}
	}
	int ans = 0; 
	for (int i = 0; i < N; ++i) 
		for (int j = 0; j < N; ++j) 
			if (vis[i][j]) ++ans; 
	cout<<ans<<endl; 
}

int main() {
	scanf( "%d", &n ); 
	for (int i = 1; i <= n; ++i) scanf( "%d", &t[i]); 
	bfs(); 
}