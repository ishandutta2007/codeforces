#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
const int MAXN = 5000;
vector<int>G[MAXN + 5];
void addedge(int u, int v) {G[u].push_back(v);}
bool vis[MAXN + 5];
int bcnt = 0, num[MAXN + 5];
int n, m, s, dfn[MAXN + 5], low[MAXN + 5], dcnt = 0;
stack<int>Sta;
void dfs(int x) {
	vis[x] = true; Sta.push(x);
	dfn[x] = low[x] = (++dcnt);
	for(int i=0;i<G[x].size();i++) {
		if( !dfn[G[x][i]] ) {
			dfs(G[x][i]);
			low[x] = min(low[x], low[G[x][i]]);
		}
		else {
			if( vis[G[x][i]] )
				low[x] = min(low[x], dfn[G[x][i]]);
		}
	}
	if( dfn[x] == low[x] ) {
		bcnt++;
		while( true ) {
			int t = Sta.top(); Sta.pop();
			num[t] = bcnt; vis[t] = false;
			if( t == x ) break;
		}
	}
}
int dOUT[MAXN + 5];
int main() {
	scanf("%d%d%d", &n, &m, &s);
	for(int i=1;i<=m;i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		addedge(u, v);
	}
	for(int i=1;i<=n;i++)
		if( !dfn[i] ) dfs(i);
	for(int i=1;i<=n;i++) {
		for(int j=0;j<G[i].size();j++)
			if( num[i] != num[G[i][j]] ) dOUT[num[G[i][j]]]++;
	}
	int ans = 0;
	for(int i=1;i<=bcnt;i++)
		if( !dOUT[i] ) ans++;
	if( !dOUT[num[s]] ) ans--;
	printf("%d\n", ans);
}