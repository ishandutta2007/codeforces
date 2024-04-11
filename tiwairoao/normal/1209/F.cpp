#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2000000;
const int MOD = int(1E9) + 7;
struct edge{
	int to, key;
	edge(int _t=0, int _k=0):to(_t), key(_k) {}
};
vector<edge>G[MAXN + 5];
void addedge(int u, int v, int w) {
	G[u].push_back(edge(v, w));
//	printf("! %d %d %d\n", u, v, w);
}
int cnt;
void func(int u, int v, int id) {
	int p = id;
	while( p ) {
		if( p >= 10 )
			addedge(++cnt, u, p % 10), u = cnt;
		else addedge(v, u, p % 10);
		p /= 10;
	}
}
int d[MAXN + 5], n, m;
void bfs(int x) {
	queue<int>que;
	que.push(x); d[x] = 1;
	while( !que.empty() ) {
		int f = que.front(); que.pop();
		for(int i=0;i<G[f].size();i++) {
			edge p = G[f][i];
			if( !d[p.to] ) {
				d[p.to] = d[f] + 1;
				que.push(p.to);
			}
		}
	}
}
int ans[MAXN + 5], nxt[MAXN + 5];
bool vis[MAXN + 5];
void dfs(int x, int k) {
	int p = x;
	while( p ) ans[p] = k, p = nxt[p];
	for(int i=0;i<10;i++) {
		int q = -1, fir = -1; p = x;
		while( p ) {
			for(int j=0;j<G[p].size();j++) {
				edge &r = G[p][j];
				if( vis[r.to] || d[p] + 1 != d[r.to] )
					continue;
				if( r.key == i ) {
					if( q != -1 ) nxt[q] = r.to;
					else fir = r.to;
					vis[q = r.to] = true;
				}
			}
			p = nxt[p];
		}
		if( fir != -1 )
			dfs(fir, (10LL*k + i)%MOD);
	}
}
int main() {
	scanf("%d%d", &n, &m), cnt = n;
	for(int i=1;i<=m;i++) {
		int x, y; scanf("%d%d", &x, &y);
		func(x, y, i), func(y, x, i);
	}
	bfs(1), vis[1] = true, dfs(1, 0);
	for(int i=2;i<=n;i++)
		printf("%d\n", ans[i]);
}