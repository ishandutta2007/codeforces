#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
int n, m;
char g[1002][1002];
inline bool valid(int i, int j) { return i >= 0 && i < n && j >= 0 && j < m && g[i][j] != '#'; }
int d[3][1002][1002];
int di[4] = {1, -1, 0, 0};
int dj[4] = {0, 0, 1, -1};
//int ds[3][3];

void bfs(int s) {
	//ds[s][0] = ds[s][1] = ds[s][2] = 1500000;
	int i, j;
	deque<pii> q;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++)
			if(g[i][j] == '1' + s)
				q.pb(pii(i, j)), d[s][i][j] = 0;
	//ds[s][s] = 0;
	while(!q.empty()) {
		pii p = q.front(); q.pop_front();
		//char c = g[p.fst][p.snd];
		//printf("[%d, %d] %c = %d\n", p.fst, p.snd, c, d[s][p.fst][p.snd]);
		//if(c >= '1' && c <= '3') ds[s][c - '1'] = min(ds[s][c - '1'], d[s][p.fst][p.snd]);
		for(int i = 0; i < 4; i++) {
			int ni = p.fst + di[i], nj = p.snd + dj[i];
			if(!valid(ni, nj)) continue;
			int nd = d[s][p.fst][p.snd] + !isdigit(g[ni][nj]);
			if(d[s][ni][nj] <= nd) continue;
			d[s][ni][nj] = nd;
			//printf("(%d, %d) %c = %d\n", ni, nj, g[ni][nj], nd);
			if(isdigit(g[ni][nj])) q.push_front(pii(ni, nj));
			else q.pb(pii(ni, nj));
		}
	}
	//for(int i =0 ; i < 3; i++)
	//	printf("%d -> %d = %d\n", s, i, ds[s][i]);
}

int main() {
	int i, j;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			scanf(" %c", &g[i][j]);
			d[0][i][j] = d[1][i][j] = d[2][i][j] = 1500000;
		}
	for(i = 0; i < 3; i++)
		bfs(i);
	int tot = INT_MAX;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			int bt = tot;
			tot = min(tot, d[0][i][j] + d[1][i][j] + d[2][i][j] - (!isdigit(g[i][j]) * 2));
		}
	//for(i = 0; i < 3; i++)
	//	tot = min(tot, ds[i][0] + ds[i][1] + ds[i][2]);
	if(tot > 1000000) puts("-1");
	else printf("%d\n", tot);
}