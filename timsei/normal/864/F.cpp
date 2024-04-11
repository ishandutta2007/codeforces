#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

const int N = 3005;

vector<int> G[N];

int st[N][15] , n ,  m , q , x , y , k , reach[N] , ans[N * N] , dfs_clock , dis[N][N] , depth[N] , dfn[N] , low[N] , all[N] , die[N];

struct NODE {
	int s , t , k , id;
}Q[N * N];

vector<NODE>Query[N];

void read(void) {
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1 ,x , y;i <= m;i ++) {
		scanf("%d%d",&x,&y); G[x].push_back(y);
	}
	for(int i = 1;i <= n;i ++) sort(G[i].begin() , G[i].end());
	for(int i = 1 , x , y , k;i <= q;i ++) {
		scanf("%d%d%d",&Q[i].s,&Q[i].t,&Q[i].k); Q[i].id = i;
		Query[Q[i].s].push_back(Q[i]);
	}
}

void dfs(int x , int f , int no , int died) {
	all[x] = 1;
	st[x][0] = f; depth[x] = depth[f] + 1; 
	low[x] = dfn[x] = ++ dfs_clock;
	dis[no][x] = dis[no][f] + 1;
	reach[x] = 1;
	if(died) st[x][0] = 0  , dis[no][x] = 0;
	die[x] = died;
	if(!died)for(int i = 1;i <= 12;i ++) st[x][i] = st[st[x][i - 1]][i - 1];
	for(int i = 0;i < (int) G[x].size();i ++) {
		int V = G[x][i];
		if(!reach[V]) {
			dfs(V , x , no , died);
		}
		else if(!all[V]) continue;
		low[x] = min(low[x] , low[V]);
		if(low[x] < dfn[x] || low[V] == dfn[x]) died |= 1;
	}
	all[x] = 0;
}

void do_query(int x) {
	memset(reach , 0 ,sizeof(reach));
	dfs_clock = 0;
	dfs(x , 0 , x , 0);
	for(int i = 0;i < (int) Query[x].size();i ++) {
		NODE ind = Query[x][i];
		int t = ind.t , k = ind.k;
		if(!reach[t] || dis[x][t] < k || die[t]) ans[ind.id] = -1;
		else {
			for(int j = 12;j >= 0;j --) if(dis[x][st[t][j]] >= k) {
				t = st[t][j];
			}
			ans[ind.id] = t;
			if(dis[x][t] != k) ans[ind.id] = -1;
		}
	}
}

int main(void) {
	read();
	for(int i = 1;i <= n;i ++) do_query(i);
	for(int i = 1;i <= q;i ++) printf("%d\n",ans[i]);
	return 0;
}