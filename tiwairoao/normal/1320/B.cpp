#include <queue>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 200000;

int n, m, k;
vector<int>G1[MAXN + 5], G2[MAXN + 5];

int d[MAXN + 5];
void bfs(int s) {
	for(int i=1;i<=n;i++)
		d[i] = MAXN + 5;
	queue<int>que; d[s] = 0; que.push(s);
	while( !que.empty() ) {
		int x = que.front(); que.pop();
		for(int i=0;i<G2[x].size();i++) {
			int to = G2[x][i];
			if( d[to] > d[x] + 1 )
				d[to] = d[x] + 1, que.push(to);
		}
	}
}

int p[MAXN + 5];
int main() {
	scanf("%d%d", &n, &m);
	for(int i=1;i<=m;i++) {
		int u, v; scanf("%d%d", &u, &v);
		G1[u].push_back(v), G2[v].push_back(u);
	}
	scanf("%d", &k);
	for(int i=1;i<=k;i++)
		scanf("%d", &p[i]);
	bfs(p[k]);
	int mn = 0, mx = 0;
	for(int i=1;i<k;i++) {
		int cnt = 0;
		for(int j=0;j<G1[p[i]].size();j++) {
			int x = G1[p[i]][j];
			if( d[p[i]] == d[x] + 1 ) cnt++;
		}
		if( d[p[i]] != d[p[i+1]] + 1 ) mn++;
		else if( cnt != 1 ) mx++;
	}
	
	printf("%d %d\n", mn, mn + mx);
}