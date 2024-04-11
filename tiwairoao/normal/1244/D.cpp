#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 100000;
vector<int>G[MAXN + 5];
void addedge(int u, int v) {
	G[u].push_back(v), G[v].push_back(u);
}
ll c[3][MAXN + 5], ans;
ll dfs(int x, int f, int C, int d) {
	ll ret = 0;
	for(int i=0;i<G[x].size();i++) {
		if( G[x][i] != f )
			ret += dfs(G[x][i], x, (C + d) % 3, d);
	}
	return ret + c[C][x];
}
int col[MAXN + 5];
void get(int x, int f, int C, int d) {
	for(int i=0;i<G[x].size();i++) {
		if( G[x][i] != f )
			get(G[x][i], x, (C + d) % 3, d);
	}
	col[x] = C;
}
int main() {
	int n; scanf("%d", &n);
	for(int i=0;i<3;i++)
		for(int j=1;j<=n;j++)
			scanf("%lld", &c[i][j]);
	for(int i=1;i<n;i++) {
		int u, v; scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	int rt = 0;
	for(int i=1;i<=n;i++)
		if( G[i].size() >= 3 ) {
			puts("-1");
			return 0;
		}
		else if( G[i].size() == 1 )
			rt = i;
	ll ans = (1LL<<60);
	int k = 0, d = 0;
	for(int i=0;i<3;i++)
		for(int j=1;j<3;j++)
			if( dfs(rt, 0, i, j) < ans )
				ans = dfs(rt, 0, i, j), k = i, d = j;
	get(rt, 0, k, d);
	printf("%lld\n", ans);
	for(int i=1;i<=n;i++)
		printf("%d ", col[i] + 1);
}