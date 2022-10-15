#include <bits/stdc++.h>
 
using namespace std;
 
#define FOE(i, s, t) for (int i = s; i <= t; i++)
#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOD(i, s, t) for (int i = s; i >= t; i--)
#define LL long long
#define mp make_pair
#define pb push_back
#define pow qjwopjqpw


#define K 100
int a[K][K], n;
int col[K], h;
int ans[K][K][K];

map<int, int> M[K];

vector<int> nxt[K];

int deg[K];
int layer[K], h2;
 
void DFS(int u) {
	deg[u] = -1;
	layer[u] = h2;
	h2 -= 2;
	
	for (auto x : nxt[u]) {
		deg[x]--;
		
		if (deg[x] == 0) DFS(x);
	}
}
 
int main() {
	scanf("%d", &n);
	
	FOE(i, 1, n) FOE(j, 1, n) scanf("%d", &a[i][j]);
	FOE(k, 1, n) FOE(i, 1, n) FOE(j, 1, n) a[i][j] |= (a[i][k] & a[k][j]);
	
	FOE(i, 1, n) if (col[i] == 0) {
		col[i] = ++h;
		
		FOE(j, 1, n) if (a[i][j] && a[j][i]) col[j] = h;
	}
	
	FOE(i, 1, n) FOE(j, 1, n) if (a[i][j] && col[i] != col[j] && M[col[i]].find(col[j]) == M[col[i]].end()) {
		nxt[col[i]].pb(col[j]);
		M[col[i]][col[j]] = 1;
		deg[col[j]]++;	
	}
	
	h2 = 2 * h + 1;
	
	FOE(i, 1, h) if (deg[i] == 0) {
		DFS(i);
	}
	
	int lay = 2 * h + 2;
	int width = 3;
	int len = 3 + h * (h + 1);
	int edge = 5;
	
	
	for (int curL = 2 * h + 1; curL >= 3; curL -= 2) {
		int u;
		FOE(i, 1, h) if (layer[i] == curL) u = i;
		
		
		int cx = 1, cy = 1;
		FOE(i, 1, n) if (col[i] == u) {
			ans[cx][cy][curL + 1] = i; 
			
			if (cy == 3) {
				cx++;
				cy = 1;	
			} else cy++;
		}
		
		FOE(i, 1, 3) FOE(j, 1, 3) ans[i][j][curL] = -1;
		FOE(i, 1, len) ans[1][i][curL] = -1;
		
		for (auto x : nxt[u]) {
			// occupy one
			int tarL = layer[x];
			
			ans[2][edge][curL] = ans[2][edge][tarL] = -1;
			ans[3][edge][tarL] = -1;
			
			FOE(j, tarL + 2, curL) ans[2][edge][j] = -1;
			FOE(j, curL + 2, lay) ans[2][edge][j] = -1;
			
			edge += 2;
		}
	}
	
	printf("%d %d %d\n", len, width, lay);
	
	assert(len <= 100 && width <= 100 && lay <= 100);
	assert(len * width * lay <= 1000000);
	
	FOD(i, lay, 1) {
		FOE(j, 1, width) FOE(k, 1, len) {
			int res = ans[j][k][i];
			
			if (res == -1) printf("#");
			else if (res == 0) printf(".");
			else printf("%d", res);
			if (k == len) puts("");	
		}
		
		if (i != 1) puts("");	
	}
}