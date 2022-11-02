#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 200000;
const int MOD = 998244353;

typedef pair<int, int> pii;
#define fi first
#define se second
#define mp make_pair

vector<pii>G[MAXN + 5];
void addedge(int u, int v, int w) {
	G[u].push_back(mp(w, v));
	G[v].push_back(mp(w, u));
}

int dp[3][MAXN + 5], pro[MAXN + 5];
void dfs(int x, int f) {
	for(int i=0;i<(int)G[x].size();i++)
		if( G[x][i].se != f )
			dfs(G[x][i].se, x);
	int lst = 1, tmp = 0;
	for(int i=0;i<(int)G[x].size();i++) {
		if( G[x][i].se == f ) {
			tmp = lst;
			continue;
		}
		pro[G[x][i].se] = lst, lst = 1LL*lst*dp[0][G[x][i].se]%MOD;
	}
	dp[1][x] = dp[2][x] = lst, lst = 1;
	bool flag = false;
	for(int i=(int)G[x].size()-1;i>=0;i--) {
		if( G[x][i].se == f ) {
			dp[0][x] = (dp[0][x] + 1LL*lst*tmp%MOD)%MOD;
			flag = true;
		}
		else {
			if( flag ) {
				dp[0][x] = (dp[0][x] + 1LL*lst*pro[G[x][i].se]%MOD*dp[1][G[x][i].se]%MOD)%MOD;
			}
			else {
				dp[1][x] = (dp[1][x] + 1LL*lst*pro[G[x][i].se]%MOD*dp[1][G[x][i].se]%MOD)%MOD;
			}
			dp[2][x] = (dp[2][x] + 1LL*lst*pro[G[x][i].se]%MOD*dp[1][G[x][i].se]%MOD)%MOD;
			lst = 1LL*lst*dp[2][G[x][i].se]%MOD;
		}
	}
}
/*
dp[0][x] - (x, fa[x])  x  x 
dp[1][x] - (x, fa[x])  x  x
dp[2][x] - (x, fa[x])  fa[x] 

dp[2][x] = dp[0][x] + dp[1][x]

*/
int main() {
	int n; scanf("%d", &n);
	for(int i=1;i<n;i++) {
		int u, v; scanf("%d%d", &u, &v);
		addedge(u, v, i);
	}
	dfs(1, 0), printf("%d\n", dp[1][1]);
}